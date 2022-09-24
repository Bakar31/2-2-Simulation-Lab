clc
clear all

A = [-2 -1; 9 -1];
B = [5; 0];
C = [1 0];
D = [0];

state_space = ss(A,B,C,D)

state = 2;
output = 1;
Q = [19 0; 0 19];
R = 17;

QXU = blkdiag(0.000031*eye(state), 0.0001);
QWV = blkdiag(Q, R);
QI = eye(output);
KLOG = lqg(state_space, QXU, QWV, QI, '1dof')
CL = feedback(KLOG*state_space, 1)

step(state_space)
hold on
step(CL)