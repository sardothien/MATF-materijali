/* Napisati predikat savrsen(N) koji proverava da li je prirodan broj
   N savrsen tj. da li je jednak sumi svojih pravih delilaca. U slucaju
   da se prosledi neispravan argument, predikat treba da ispise poruku o
   gresci i prekine program. */
savrsen(N) :- provera(N), sumaDelilaca(N, S), N =:= S.

provera(N) :- N>0.
provera(N) :- N=<0, write('Broj  nije prirodan.'), nl, fail.

sumaDelilaca(N, S) :- sumaPom(N, S, 1).

sumaPom(N, 0, I) :- I > N//2.
sumaPom(N, S, I) :- I =< N//2, N mod I =:= 0, I1 is I+1, sumaPom(N, S1, I1), S is S1+I.
sumaPom(N, S, I) :- I =< N//2, N mod I =\= 0, I1 is I+1, sumaPom(N, S, I1).