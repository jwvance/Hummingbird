clear;
clc;
%wavFile3 = 'hum1_8k.wav';
wavFile3 = 'Marcus5notes8k.wav';
[humFull, Fs3] = audioread(wavFile3);
%downsamples to 8k
humFullDS = humFull;%downsample(humFull,2);
%humFullDS = humFull;
Fs3=8000;
audioLength=length(humFullDS);
% Adapted from zero-crossing 

frameLength = 250; %250
frameNumber = 1;


last_freq = 0;
last_midi = 2;

for i4 = 1:128
   midiTable(i4+1) = (440/32)*(2^((i4-8)/12)); 
   %It was just off by 1? so i just fixed it i guess
end
increment=frameLength;
for i1 = frameLength+1:increment:audioLength
    x = i1-frameLength;

    %creates frame
    frame = humFullDS(x:i1); 
    freq = ac_pitch(frame);
    pitch(frameNumber) = freq;
    

    f = @() ac_pitch(frame);
    compTime(frameNumber) = timeit(f);
    
    uphyst = 0.7;
    dnhyst = 0.7;
    upper = midiTable(last_midi) + uphyst*(midiTable(last_midi+1)-midiTable(last_midi));
    lower = midiTable(last_midi) - dnhyst*(midiTable(last_midi)-midiTable(last_midi-1));
    
    if freq < upper && freq > lower
        midiNotes(frameNumber) = last_midi;
    else
        note = round((69+(12*log(freq/440)/log(2))));
        if note < 2
            note = 2;
        end
        
        last_midi = note;
        last_freq = freq;
        
        midiNotes(frameNumber) = note;
    end
    
    
    %verifies that we are within an acceptable volume range
    max=0;
    for i=1:1:frameLength
        if frame(i)>max
            max=frame(i);
        end
    end
    
%     volumeThreshold=0.06;
%     if max<volumeThreshold
%         midiNotes(frameNumber)=2;
%     end
    frameNumber = frameNumber + 1;
end

 
% figure;
% plot(humFullDS)


figure
stairs(midiNotes,'LineWidth',3);
title(strcat('MIDI from Autocorrelation, Note Snapping: Cromatic, Hysteresis:',num2str(dnhyst)));%,num2str(frameLength),' Fs: ',num2str(Fs3)));

%creates a midi file based on our results so we can hear what they might
%sound like:

% initialize matrix:
N = length(midiNotes);  % number of notes
M = zeros(N,6);

M(:,1) = 1;         % all in track 1
M(:,2) = 1;         % all in channel 1
for i5=1:length(midiNotes)
    M(i5,3) = midiNotes(i5);      % note numbers
    M(i5,5) = i5*.0625;        % note on:  notes start every 16th of a second (4000 sp/sec, 250 sp/frame, 16 frames/second
end
M(:,4) = 80;  % all at 80
  % note on:  notes start every 16th of a second (4000 sp/sec, 250 sp/frame, 16 frames/second
M(:,6) = M(:,5) + .0625;   % note off: each note has duration .5 seconds

midi_new = matrix2midi(M);
writemidi(midi_new, 'hystMidi2.mid');



%plot(compTime)
S = sum(compTime)