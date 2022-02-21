clc 
clear all

numerator = [1];
denominator = [1 5 31];
transfer_function = tf(numerator, denominator);

kp = 120;
ki = 790;
kd = 25;

controller = pid(kp, ki, kd);
CL = feedback(transfer_function*controller, 1);

figure(1)
step(transfer_function)
hold on
step(CL)
