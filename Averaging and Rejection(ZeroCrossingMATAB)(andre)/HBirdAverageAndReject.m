% Aquires Audio
wavFile3 = 'hum1_8k.wav';
[humFull, Fs3] = audioread(wavFile3);
%downsamples to 4k
 humFullDS = downsample(humFull,2);
 Fs3=4000;
audioLength=length(humFullDS);
% Adapted from zero-crossing 

frameLength = 250;
frameNumber = 1;
%zeroCrossingTotal[audioLength/frameLength];
%zeroCrossingTotal = zeros(int16(audioLength/frameLength),1);
for i1 = 1001:frameLength:audioLength
    x = i1-frameLength;
    zc = 0;
    for i2 = x:i1
        if (humFullDS(i2) * humFullDS(i2+1)) < 0
            zc = zc+1;
        end
    end
        zeroCrossingTotal(frameNumber)=zc;
        frameNumber=frameNumber+1;
end
%convert each zero crossing into a note'
zeroCrossingTotalLength=length(zeroCrossingTotal);
for i3=1:1:zeroCrossingTotalLength
    framePitch(i3)=(zeroCrossingTotal(i3)/4)/(frameLength/Fs3);
end

%averaging 3 frames -> removes bad estimates:

A = [0 0 0];
thresh = 10;
i6=1;
% takes the average of the previous three frames
for i4=3:3:length(framePitch)
    avg0 = (framePitch(i4) + framePitch(i4-1) + framePitch(i4-2))/3;
    averagePitch(i4-2)=avg0;
    averagePitch(i4-1)=avg0;
    averagePitch(i4-0)=avg0;

%     badFrame = 0;   %flag for determining if a frame was removed from avg
%     A(1) = abs(avg0 - framePitch(i4)); A(2) = abs(avg0 -
%     framePitch(i4-1)); A(3) = abs(avg0 - framePitch(i4-2)); Y = max(A);
%     for i5=1:1:3
%         if (A(i5)==Y) && (A(i5)>thresh)     %logic for rejecting bad frame
%             A(i5) = 0;
%             avgFinal(i6) = (A(1) + A(2) + A(3))/2; 
%             badFrame=1;
%         end      
%     end 
%     if badFrame==0
%         avgFinal(i6) = (A(1) + A(2) + A(3))/3;
%     end
%     i6 = i6 + 1;
end
% Takes a similar average, but with a running average that advances one
% frame at a time as opposed to 3
for i4=3:1:length(framePitch)
    avg0 = (framePitch(i4) + framePitch(i4-1) + framePitch(i4-2))/3;
    average2Pitch(i4-2)=avg0;
end

%aquires midi notes for each pitch
for i5= 1:length(framePitch)
   midiUnfiltered(i5) = round((69+(12*log(framePitch(i5)/440)/log(2))));
end

for i5= 1:length(averagePitch)
   midiFiltered1(i5)   = round((69+(12*log(averagePitch(i5)/440)/log(2))));  
end

for i5= 1:length(average2Pitch)
   midiFiltered2(i5)   = round((69+(12*log(average2Pitch(i5)/440)/log(2))));  
end

close all
figure
subplot(2,1,1)
bar(framePitch)
subplot(2,1,2)
bar(averagePitch)

figure
bar(midiUnfiltered);
title('midiUnfiltered')

figure
bar(midiFiltered1);
title('midiFiltered1')

%creates a midi file based on our results so we can hear what they might
%sound like:

% initialize matrix:
N = 255;  % number of notes
M = zeros(N,6);

M(:,1) = 1;         % all in track 1
M(:,2) = 1;         % all in channel 1
for i5=1:length(midiFiltered1)
    M(i5,3) = midiFiltered1(i5);      % note numbers
    M(i5,5) = i5*.0625;        % note on:  notes start every 16th of a second (4000 sp/sec, 250 sp/frame, 16 frames/second
end
M(:,4) = 80;  % all at 80
  % note on:  notes start every 16th of a second (4000 sp/sec, 250 sp/frame, 16 frames/second
M(:,6) = M(:,5) + .0625;   % note off: each note has duration .5 seconds

midi_new = matrix2midi(M);
writemidi(midi_new, 'testout.mid');
