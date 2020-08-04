% Napisati predikat krug(L) koji ređa 10 različitih brojeva iz intervala[1,100) 
% u krug takav da zbir kvadrata dva susedna broja bude jednak zbiru kvadrata dva
% susedna broja koja se nalaze naspram njih i suma svih brojeva bude minimalna.

zbir(X1, X2, Y1, Y2) :- X1*X1 + X2*X2 #= Y1*Y1 + Y2*Y2.

krug(L) :- L = [A, B, C, D, E, F, G, H, I, J],
           L :: 1..99,
           alldifferent(L),
           zbir(A, B, F, G),
           zbir(B, C, G, H),
           zbir(C, D, H, I),
           zbir(D, E, I, J),
           zbir(E, F, J, A),
           labeling([minimize(A+B+C+D+E+F+G+H+I+J)], L),
           nl, nl,
           format("     ~d  ~d\n", [J, A]),
           format("   ~d       ~d\n", [I, B]),
           format(" ~d           ~d\n", [H, C]),
           format("   ~d       ~d\n", [G, D]),
           format("     ~d  ~d\n", [F, E]),
           nl, nl.