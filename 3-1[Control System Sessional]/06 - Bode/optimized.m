clc
clear all

L = 2e-3;
c = 15e-6;

A = [0 -1/L; 1/c 0];
B = [1/L; 0];
C = [0 1];
D = [0];

Sys = ss(A,B,C,D);
G = tf(Sys)

%bode(Sys)

w = 5770

neu = [1 (2*0.7*w) 0];
den = [1 (2*0.7*w) (w*w)]

TF = tf(neu,den)
O = feedback(G,TF,1,1)

figure(1)
bode(G)
hold on
bode(O)

figure(2)
step(G)
hold on
step(O)
hold off