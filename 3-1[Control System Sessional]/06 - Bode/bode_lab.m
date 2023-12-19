clc
clear all

l = 2e-3
c = 15e-6

A = [0 -1/l; 1/c 0];
B = [1/l; 0];
C = [0 1];
D = 0;

sys = ss(A, B, C, D)
G = tf(sys);

xi = 0.7;
Wr = 5770;

num = [1 2*xi*Wr 0]
den = [1 2*xi*Wr Wr*Wr]
ttf = tf(num,den)
%cl = feedback(G, ttf, 1, 1)
%cl = feedback(G, ttf, 1)
%cl = feedback(G, ttf)
%cl = feedback(G*ttf, 1)
cl = feedback(G*ttf, 1, 1)

figure(1)
bode(sys)
hold on
bode(cl)

figure(2)
step(sys)
hold on
step(cl)