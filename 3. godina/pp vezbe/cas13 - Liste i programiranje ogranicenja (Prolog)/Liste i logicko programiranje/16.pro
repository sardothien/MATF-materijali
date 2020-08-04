% Napisati predikat parNepar(L, L1, L2) koji deli listu L na 
% dve liste, listu parnih elemenata L1 i listu neparnih elemenata L2.

parNepar([], [], []) :- !.
parNepar([G|R], [G|R1], L2) :- G mod 2 =:= 0, parNepar(R, R1, L2), !.
parNepar([G|R], L1, [G|R1]) :- G mod 2 =:= 1, parNepar(R, L1, R1).