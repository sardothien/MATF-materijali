/* Napisati predikat zameni(X, Y, L, NL) koji od date liste L
   formira novu listu NL zamenom elemenata X i Y. */
zameni(_, _, [], []).
zameni(X, Y, [X|R], [Y|R1]) :- zameni(X, Y, R, R1).
zameni(X, Y, [Y|R], [X|R1]) :- zameni(X, Y, R, R1).
zameni(X, Y, [G|R], [G|R1]) :- G \== X, G \== Y, zameni(X, Y, R, R1).