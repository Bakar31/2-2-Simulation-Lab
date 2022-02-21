clc 
clear all

numerator = [1];
denominator = [1 20 31];
transfer_function = tf(numerator, denominator);

kp = 189;
ki = 310;
kd = 5;

controller = pid(kp, ki, kd);
CL = feedback(transfer_function*controller, 1);

figure(1)
step(transfer_function)
hold on
step(CL)