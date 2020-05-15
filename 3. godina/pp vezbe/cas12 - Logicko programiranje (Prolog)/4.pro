% da li je godina prestupna
prestupna(X) :- X mod 4 =:= 0, X mod 100 =\= 0.
prestupna(X) :- X mod 400 =:= 0.

% broj dana u prosledjenom mesecu
% brojdana(mesec, godina, rezultat)
brojdana(januar, _, 31).
brojdana(februar, X, 28) :- not(prestupna(X)).
brojdana(februar, X, 29) :- prestupna(X).
brojdana(mart, _, 31).
brojdana(april, _, 30).
brojdana(maj, _, 31).
brojdana(jun, _, 30).
brojdana(jul, _, 31).
brojdana(avgust, _, 31).
brojdana(septembar, _, 30).
brojdana(oktobar, _, 31).
brojdana(novembar, _, 30).
brojdana(decembar, _, 31).