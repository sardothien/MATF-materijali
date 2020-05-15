/* Napisati program koji pronalazi vrednosti 
   A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S (svako slovo predstavlja razlicit broj)
   koje su poredjane u heksagon na sledeci nacin:
      A,B,C
     D,E,F,G
    H,I,J,K,L
     M,N,O,P
      Q,R,S
   tako da zbir vrednosti duz svake horizontalne i dijagonalne linije bude 38
   (A+B+C=D+E+F+G=...=Q+R+S=38, A+D+H=B+E+I+M=...=L+P+S=38, C+G+L=B+F+K+P=...=H+M+Q=38). */

heksagon(Vars) :- Vars = [A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S],
                  Vars :: 1..38,
                  alldifferent(Vars),
                  % ogranicenje za svaku horizontalnu liniju
                  A+B+C #= 38,
                  D+E+F+G #= 38,
                  H+I+J+K+L #= 38,
                  M+N+O+P #= 38,
                  Q+R+S #= 38,
                  % ogranicenje za svaku sporednu dijagonalu
                  A+D+H #= 38,
                  B+E+I+M #= 38,
                  C+F+J+N+Q #= 38,
                  G+K+O+R #= 38,
                  L+P+S #= 38,
                  % ogranicenje za svaku glavnu dijagonalu
                  C+G+L #= 38,
                  B+F+K+P #= 38,
                  A+E+J+O+S #= 38,
                  D+I+N+R #= 38,
                  H+M+Q #= 38,
                  labeling(Vars).