clear
clc
close all

fileID = fopen('SAMPLES.txt','r');
formatSpec = '%d';
A = fscanf(fileID,formatSpec);
fclose(fileID);
figure
plot(A);
Y = fft(A);

L=1024;
Fs=8000;
P2 = abs(Y/L);
P1 = P2(1:L/2+1);
P1(2:end-1) = 2*P1(2:end-1);
f = Fs*(0:(L/2))/L;
figure
plot(f,P1)
title('Single-Sided Amplitude Spectrum of A(t)')
xlabel('f (Hz)')
ylabel('|P1(f)|')
