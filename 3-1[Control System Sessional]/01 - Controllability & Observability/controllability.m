clc
clear all;

A = [-2 -1 -3; 0 31 1; -7 -8 -9];
B = [2; 1; 2];

cr = ctrb(A,B);
control_rank = rank(cr);
rank_a = rank(A);

if(control_rank == rank_a)
    disp('Given System is Controllable')
else
    disp('Given System is not Controllable')
    
end