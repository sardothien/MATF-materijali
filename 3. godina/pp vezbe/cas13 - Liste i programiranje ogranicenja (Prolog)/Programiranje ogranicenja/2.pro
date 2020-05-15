/* Napisati program koji pronalazi petocifren broj ABCDE za koji je
   izraz A+2*B-3*C+4*D-5*E minimalan i A,B,C,D i E su razlicite cifre. */

petocifren :- Vars = [A, B, C, D, E],
              A :: 1..9,
              [B,C,D,E] :: 0..9,
              alldifferent(Vars),
              labeling([minimize(A+2*B-3*C+4*D-5*E)], Vars),
              Broj is 10000*A + 1000*B + 100*C + 10*D + E,
              write(Broj), nl.