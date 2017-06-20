clear;
clc;
% wavFile3 = 'hum1_8k.wav';
wavFile3 = 'LowMarcus3.wav';
[humFull, Fs3] = audioread(wavFile3);
%downsamples to 4k
%humFullDS = audioFrame1;
humFullDS = downsample(humFull,2);
Fs3=4000;
audioLength=length(humFullDS);
% Adapted from zero-crossing 

frameLength = 251; %250
frameNumber = 1;
%zeroCrossingTotal[audioLength/frameLength];
%zeroCrossingTotal = zeros(int16(audioLength/frameLength),1);

last_freq = 0;
last_midi = 2;

for i4 = 1:128
   midiTable(i4+1) = (440/32)*(2^((i4-8)/12)); 
   %It was just off by 1? so i just fixed it i guess
end
increment=frameLength;
for i1 = frameLength+1:increment:audioLength
    x = i1-frameLength;
    zc = 0;
    zcAlt = 0;
    
    % run two zero crossings, one at 0, another at a different, negative
    % value
    for i2 = x:i1
        if (humFullDS(i2) * humFullDS(i2+1)) < 0
            zc = zc+1;
        end
    end
    % Alternate "zero" crossing at -0.5
    for i2 = x:i1
        if ((humFullDS(i2)+0.5) * (humFullDS(i2+1)+0.5) )< 0
            zcAlt = zcAlt+1;
        end
    end
    zcChart(frameNumber) = zc;
    freq = (zc / 2)/(frameLength/Fs3);
    pitch(frameNumber) = freq;
    
    freqAlt = (zcAlt / 2)/(frameLength/Fs3);
    pitchAlt(frameNumber) = freq;
    
    uphyst = 0.9;
    dnhyst = 0.9;
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
    
    unfilteredMidi(frameNumber) = round((69+(12*log(freq/440)/log(2))));
    
    frameNumber = frameNumber + 1;
end

% for i3=1:1:length(midiNotes)
%    if midiNotes(i3)< 30
%        midiNotes(i3)=2;
%    end
% end
% 
% close all;
% 
% figure;
% bar(humFullDS)
% 
% %figure;
% %plot(psd(spectrum.periodogram,humFullDS,'Fs',Fs3,'NFFT',length(humFullDS)));
% 
% figure;
% bar(pitch);
% title('Frequency vs Time, ZC method')
% 
% figure
% bar(pitchAlt);
% title('Frequency vs Time, Alternative ZC method')
% figure
% bar(zcChart);
% title(strcat('Number of ZC for each Frame',num2str(frameLength)))

figure
bar(midiNotes);
title(strcat('MIDI with Hysteresis FL:',num2str(frameLength)));
% figure
% bar(unfilteredMidi);
% title('Unfiltered MIDI');

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

% initialize matrix for non-filted notes:
N = length(unfilteredMidi);  % number of notes
M2 = zeros(N,6);

M2(:,1) = 1;         % all in track 1
M2(:,2) = 1;         % all in channel 1
for i5=1:length(unfilteredMidi)
    M2(i5,3) = unfilteredMidi(i5);      % note numbers
    M2(i5,5) = i5*.0625;        % note on:  notes start every 16th of a second (4000 sp/sec, 250 sp/frame, 16 frames/second
end
M2(:,4) = 80;  % all at 80
  % note on:  notes start every 16th of a second (4000 sp/sec, 250 sp/frame, 16 frames/second
M2(:,6) = M2(:,5) + .0625;   % note off: each note has duration .5 seconds

midi_new2 = matrix2midi(M2);
writemidi(midi_new2, 'MidiUnfilt.mid');
