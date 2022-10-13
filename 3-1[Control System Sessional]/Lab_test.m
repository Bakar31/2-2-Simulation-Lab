clc
clear all

j = 0.01;
b = 0.1;
k = 0.02;
l = 0.5;
r = 1;

A = [0 1 0; 0 (-b/j) (k/j); 0 (-k/l) (-r/l)]
B = [0; 0; (1/l)]
C = [1 0 0]
D = 0;

sys = ss(A, B, C,D)
G = tf(sys)

kp = 20;
ki = 10;
kd = 2;

controller = pid(kp, ki, kd);
Ctf = tf(controller)
con = feedback(G*Ctf, 1)

figure(1)
step(G)
hold on
step(con)