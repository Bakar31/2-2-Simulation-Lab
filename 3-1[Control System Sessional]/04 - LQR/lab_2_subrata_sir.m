clc
clear all

% variables
r = 30.45;
l = 5e-3;
c = 15e-6;

% system matrix
A = [0 -1/(r*l); 1/(r*c) 0]
B = [0; 1/(r*l)]
C = [0 1]
D = 0

sys = ss(A, B, C, D)
G = tf(sys)

R = 100;
q = c'*c
[K,S,e] = lqr(A, B, q, R) 

AA = A - (B*K)
con = ss(AA, B, C, D)
contf = tf(con)

%try all type of connection
%cl = feedback(G, contf, 1)
%cl =  feedback(G*contf, 1, 1)
%cl = feedback(G*contf, 1) 
cl = feedback(G*contf, 1,1) 
%cl = feedback(G, contf) 


%step(G)
%hold on
step(cl)
