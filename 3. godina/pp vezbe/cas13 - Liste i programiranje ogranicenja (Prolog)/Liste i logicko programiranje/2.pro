% Napisati sledece predikate:
% (a) dodajPocetak(X, L, NL) - dodaje X na pocetak liste L
dodajPocetak(X, L, [X|L]).

% (b) dodajKraj(X, L, NL) - dodaje X na kraj liste L 
dodajKraj(X, [], [X]).
dodajKraj(X, [G|R], [G|NL]) :- dodajKraj(X, R, NL).

% (c) obrisiPrvi(L, NL) - brise prvi element, tj. glavu liste 
obrisiPrvi([_|R], R).

% (d) obrisiPoslednji(L, NL) - brise poslednji element liste
obrisiPoslednji([_], []) :- !. % lista jednog elementa
obrisiPoslednji([G|R], [G|R1]) :- obrisiPoslednji(R, R1).

% (e) obrisi(X, L, NL)- brise sva pojavljivanja elementa X u listi L
obrisi(_, [], []).
obrisi(X, [X|R], R1) :- obrisi(X, R, R1), !.
obrisi(X, [G|R], [G|R1]) :- G \== X, obrisi(X, R, R1).

% (f) obrisiPrvo(X, L, NL)- brise samo prvo pojavljivanje elementa X u listi L
obrisiPrvo(_, [], []).
obrisiPrvo(X, [X|R], R) :- !.
obrisiPrvo(X, [G|R], [G|R1]) :- G \== X, obrisiPrvo(X, R, R1).

% (g) obrisiK(L, K, NL)- brise K-ti element liste L 
obrisiK([], K, []) :- K > 0.
obrisiK([_|R], 1, R) :- !.
obrisiK([G|R], K, [G|R1]) :- K>1, K1 is K-1, obrisiK(R, K1, R1).