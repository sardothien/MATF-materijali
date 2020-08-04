% Napisati predikat brojevi(X) koji pronalazi tri broja, dvocifren broj X,
% trocifren Y i četvorocifren broj Z, tako da se brojevi sastoje od različitih 
% cifara, proizvod dvocifrenog i trocifrenog broja bude jednak četvorocifrenom
% i četvorocifren broj bude maksimalan.

% X = AB
% Y = CDE
% Z = FGHI

ispisi(X,Y,Z) :-
	write(X), write(" * "),write(Y),write(" = "),write(Z),
	nl.

brojevi(Vars) :- Vars = [A, B, C, D, E, F, G, H, I],
                 Vars :: 1..9,
                 alldifferent(Vars),
                 X #= 10*A + B,
                 Y #= 100*C + 10*D + E,
                 Z #= 1000*F + 100*G + 10*H + I,
                 X*Y #= Z,
                 labeling([maximize(Z)], Vars),
                 ispisi(X, Y, Z).
                 
