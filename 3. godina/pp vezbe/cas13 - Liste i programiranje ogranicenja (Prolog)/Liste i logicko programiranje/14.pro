% Napisati predikate za liste brojeva:

% (a) duplikati(L, L1) - izbacuje duplikate iz liste L 
duplikati([], []).
duplikati([G|R], [G|R1]) :- not(sadrzi(G, R)), duplikati(R, R1), !.
duplikati([_|R], R1) :- duplikati(R, R1).

sadrzi(X, [X|_]) :- !.
sadrzi(X, [G|R]) :- G \== X, sadrzi(X, R).

% (b) unija(L1, L2, L) - odredjuje uniju listi L1 i L2
unija(L1, L2, L) :- spoji(L1, L2, L3), duplikati(L3, L).

spoji([], L, L).
spoji([G|R1], L2, [G|R3]) :- spoji(R1, L2, R3).

% (c) presek(L1, L2, L) - odredjuje presek listi L1 i L2
presek([], _, []).
presek([G|R1], L2, [G|R3]) :- sadrzi(G, L2), duplikati(L3, L), !.
presek([_|R1], L2, L) :- presek(R1, L2, L).

% (d) razlika(L1, L2, L) - odredjuje razliku listi L1 i L2
razlika([], _, []).
razlika([G1|R1], L2, R3) :- sadrzi(G1, L2), razlika(R1, L2, R3), !.
razlika([G|R1], L2, [G|R3]) :- razlika(R1, L2, R3).