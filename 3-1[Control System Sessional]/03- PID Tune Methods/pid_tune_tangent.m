clc
clear all 

num = [1];
den = [1 20 100];

Tf = tf(num, den)

figure(1)
step(Tf)

K = 0.01;
L = 0.025;
T = 0.31 - L;

a = (K*L)/T;

Kp = 1.2/a;
Ki = Kp/(2*L);
Kd = (Kp*L)/2;

con = pid(Kp, Ki, Kd);
Cl = feedback(Tf*con, 1);

figure(2)
step(Tf)
hold on
step(Cl)