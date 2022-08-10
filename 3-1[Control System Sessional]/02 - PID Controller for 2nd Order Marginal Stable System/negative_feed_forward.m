clc
clear all

% System
a = [0 -1/0.003; 1/0.000015 0];
b = [1/0.003; 0];
c = [0 1];
d = 0;

sys = ss(a, b, c, d)
g = tf(sys)
pole(g)
figure(1)
step(g);

% Pid Controller
kp = 45;
ki = 5.5;
kd = 3;

controller = pid(kp, ki, kd)
controller_tf = tf(controller)

%feed forward
ff = controller_tf*g
cl = feedback(ff, 1, 1)
pole(cl)
figure(2)
step(cl)