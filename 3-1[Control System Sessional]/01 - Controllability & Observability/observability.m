clc
clear all;

A = [-2 -1 -3; 0 31 1; -7 -8 -9];
C = [2 4 31];

ob = obsv(A,C);
control_rank = rank(ob);
rank_a = rank(A);

if(control_rank == rank_a)
    disp('Given System is Observable')
else
    disp('Given System is not Observable')
    
end