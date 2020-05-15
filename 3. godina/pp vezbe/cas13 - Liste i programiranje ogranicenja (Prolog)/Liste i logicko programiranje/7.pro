/* Napisati predikat maxEl(L, X) koji odredjuje
   maksimalni element liste L. */
maxEl([X], X) :- !.
maxEl([G|R], X) :- maxEl(R, Y), G<Y, X is Y, !.
maxEl([G|R], X) :- maxEl(R, Y), G>=Y, X is G.