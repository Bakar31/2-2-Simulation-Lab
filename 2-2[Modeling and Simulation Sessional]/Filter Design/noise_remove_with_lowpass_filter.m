clc;
clear all;

fs = 100;
T = 1/fs;
f = 11;
t = 0:T:1-T;
A = 0.5;
x = A*sin(2*pi*f*t);
no = 0.25*randn(size(t));
xn = x+no;

filter = designfilt('lowpassfir', 'FilterOrder', 7, 'cutoffFrequency', 1.5, 'SampleRate', fs);
y = filtfilt(filter, xn);

plot(xn)
hold on
plot(y, 'red')
