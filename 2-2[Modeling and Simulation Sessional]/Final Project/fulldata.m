clc;
clear all
%data
data = readtable('Sensor_data.csv');
x = data.date_time;
y = data.absolute_humidity;
%noise
fs = 7111;
T = 1/fs;
t = 0:T:1-T;
no1 = 0.01*randn(size(t));
no2 = 0.04*randn(size(t));
no3 = 0.08*randn(size(t));
noise1 = reshape(no1, 7111, 1);
noise2 = reshape(no2, 7111, 1);
noise3 = reshape(no3, 7111, 1);
% signal and noise
noisy_signal = y+noise1+noise2+noise3;
fs = 7111;
filter = designfilt('lowpassfir', 'FilterOrder',20,'cutoffFrequency', 5, 'SampleRate', fs);
y_filter = filtfilt(filter, noisy_signal);
subplot(3, 1, 1)
plot(x, y)
title('Main Signal')
subplot(3, 1, 2)
plot(x, noisy_signal,'red')
title('Noisy Signal')
subplot(3, 1, 3)
plot(x, y_filter,'green')
title('Signal after removing noise with Lowpass filter')