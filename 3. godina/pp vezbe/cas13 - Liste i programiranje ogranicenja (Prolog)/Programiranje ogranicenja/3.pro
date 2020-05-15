/* Dati su novcici od 1, 2, 5, 10, 20 dinara. Napisati program koji 
   pronalazi svemoguce kombinacije tako da zbir svih novcica bude 50
   i da se svaki novcic pojavljuje bar jednom u kombinaciji. */

%  A - 1, B - 2, C - 5, D - 10, E - 20
kombinacije(Vars) :- Vars = [A, B, C, D, E],
                     A :: 1..50,
                     B :: 1..25,
                     C :: 1..10,
                     D :: 1..5,
                     E :: 1..2,
                     A + 2*B + 5*C + 10*D + 20*E #= 50,
                     labeling(Vars),
                     write(A + 2*B + 5*C + 10*D + 20*E = 50), nl.