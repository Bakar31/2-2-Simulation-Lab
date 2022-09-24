clc
clear all

A = [-1 -2; 5 -1];
B = [20; 0];
C = [0 1];
D = [0];

state_space = ss(A,B,C,D)

state = 2;
output = 1;
Q = [1 0; 0 1];
R = 1;

QXU = blkdiag(0.1*eye(state), 1);
QWV = blkdiag(Q, R);
QI = eye(output);
KLOG = lqg(state_space, QXU, QWV, QI, '1dof')
CL = feedback(KLOG*state_space, 1)

step(state_space)
hold on
step(CL)