/* Napisati program koji za ceo broj n ispisuje magicnu sekvencu S brojeva
   od 0 do n-1. S=(x0, x1,..., xn−1) je magicna sekvenca ukoliko postoji xi
   pojavljivanja broja i za i= 0,1,..., n−1. */

magicna(N) :- length(S,N),
              S :: 0..N-1,
              foreach(I in 0..N-1,
                      sum([(S[J] #= I) : J in 1..N]) #= S[I+1]),
              labeling(S),
              writeln(S),fail.