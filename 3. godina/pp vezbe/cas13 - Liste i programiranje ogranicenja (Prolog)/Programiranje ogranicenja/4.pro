/* Napisati program koji redja brojeve u magican kvadrat. Magican 
   kvadrat je kvadrat dimenzija 3x3 takav da je suma svih brojeva 
   u svakom redu, svakoj koloni i svakoj dijagonali jednak 15 i svi
   brojevi razliciti. */

magicni(Vars) :- Vars = [X1, X2, X3, X4, X5, X6, X7, X8, X9],
           Vars :: 1..9,
           alldifferent(Vars),
           X1+X2+X3 #= 15,
           X4+X5+X6 #= 15,
           X7+X8+X9 #= 15,
           X1+X4+X7 #= 15,
           X2+X5+X8 #= 15,
           X3+X6+X9 #= 15,
           X1+X5+X9 #= 15,
           X3+X5+X7 #= 15,
           labeling(Vars),
           write(X1), write(' '), write(X2), write(' '), write(X3), nl,
           write(X4), write(' '), write(X5), write(' '), write(X6), nl,
           write(X7), write(' '), write(X8), write(' '), write(X9), nl.