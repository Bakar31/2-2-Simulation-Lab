clc
clear all

r=30.45;
c=15e-6;
L=5e-3;

A = [-1/(r*c) 1/c; -1/L 0];
B = [0;1/L];
C = [1 0];
D = [0];

sys = ss(A,B,C,D)
G = tf(sys)
R= 100;
Q= (C'*C)*[15e65 0; 0 1]

[K,S,e] = lqr(A,B,Q,R)
AA = (A-(B*K));
Con = ss(AA,B,C,D);
Con_tf = tf(Con);
Cl = feedback(G,Con_tf,1);

step(G)
hold on
step(Cl)