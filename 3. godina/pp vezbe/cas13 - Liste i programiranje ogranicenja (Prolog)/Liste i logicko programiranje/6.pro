/* Napisati predikat pretvori(L, X) koji za datu listu 
   cifara L formira broj odredjen tim ciframa. */
izdvojPoslednji([G], G, []) :- !.
izdvojPoslednji([G|R], X, [G|R1]) :- izdvojPoslednji(R, X, R1).

pretvori([], 0) :- !.
% P - poslednji, O - ostatak
pretvori(L, X) :- izdvojPoslednji(L, P, O), pretvori(O, Y), X is P + 10*Y.