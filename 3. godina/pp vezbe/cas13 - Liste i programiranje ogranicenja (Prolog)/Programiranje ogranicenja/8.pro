/* Napisati program koji rasporedjuje brojeve 1-9 u dve linije koje
   se seku u jednom broju. Svaka linija sadrzi 5 brojeva takvih da 
   je njihova suma u obe linije 25 i brojevi su u rastucem redosledu. */

dijagonale(Vars) :- Vars = [A1, B1, C1, D1, E1, A2, B2, D2, E2],
                    Vars :: 1..9,
                    alldifferent(Vars),
                    A1+B1+C1+D1+E1 #= 25,
                    A2+B2+C1+D2+E2 #= 25,
                    A1 #< B1, B1 #< C1, C1 #< D1, D1 #< E1,
                    A2 #< B2, B2 #< C1, C1 #< D2, D2 #< E2,
                    labeling(Vars),
                    write(A1), write('     '), write(A2), nl,
                    write(' '), write(B1), write('   '), write(B2), nl,
                    write('   '), write(C1), nl,
                    write(' '), write(D2), write('   '), write(D1), nl,
                    write(E2), write('     '), write(E1), nl.