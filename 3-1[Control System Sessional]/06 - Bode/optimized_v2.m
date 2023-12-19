clc
clear all

L = 2e-3;
c = 15e-6;

A = [0 -1/L ; 1/c 0];
B = [1/L ; 0];
C = [0 1];
D = 0;

sys = ss(A, B, C, D);
G = tf(sys);

p = 0.7;
w = 5.31e3;

num = [1  2*p*w 0];
den = [1 2*p*w w*w];

Ctf = tf(num, den)
cl = feedback(G,Ctf,1, 1);

figure(1)
bode(G);
hold on
bode(cl)

figure(2)
step(G)
hold on
step(cl)