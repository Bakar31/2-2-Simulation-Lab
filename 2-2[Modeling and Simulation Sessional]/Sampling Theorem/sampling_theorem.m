clc;
clear all;
% continuous time signal representation
A = 31;
f = 7;
theta = .35;
t = 0:0.005:1;
x = A*sin(2*pi*f*t + theta);
subplot(3, 1, 1)
plot(t, x);
xlabel('Time (Sec)')
ylabel('x');
title('Continuous time signal')
% Discrete signal
fs = 31*f;
ts = 1/fs;
t1 = 0:ts:fs*ts;
xs = A*sin(2*pi*f*t1+theta);
subplot(3, 1, 2)
stem(t1, xs)
xlabel('Time (Sec)')
ylabel('xs')
title('Discrete signal')
% Recontruction
subplot(3, 1, 3)
plot(t1, xs)
xlabel('Time (Sec)')
ylabel('xs')
title('Reconstucted continuous signal')