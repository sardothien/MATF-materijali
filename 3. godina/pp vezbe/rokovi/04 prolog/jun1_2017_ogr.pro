% Napisati predikat stepenice(X) koji ređa različite vrednosti iz intervala
% [1,9] u stepenice tako da suma brojeva na svakoj stepenici bude jednaka 15
%  i suma brojeva po svakoj dijagonali bude jednaka 15. Predikat treba da
% pronađe jedno moguće rešenje.

ispisi([A,B,C,D,E,F,G,H,I]) :-
	nl,
	write(A),write(' '),write(B),write(' '),write(C), nl, write('  '),
	write(D),write(' '),write(E),write(' '),write(F), nl, write('   '),
	write(G),write(' '),write(H),write(' '),write(I),
	nl,nl.

stepenice(X) :- X = [A, B, C, D, E, F, G, H, I],
                X :: 1..9,
                alldifferent(X),
                A+B+C #= 15,
                D+E+F #= 15,
                G+H+I #= 15,
                A+D+G #= 15,
                B+E+H #= 15,
                C+F+I #= 15,
                labeling(X),
                ispisi(X), !.