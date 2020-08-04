% benzin: 2dolar/galon, min 150 000galona
% dizel: 1dolar/galon, max 325 000galona
% max 600 000 galona
% min 2galona dizela za 1galon benzina

rafinerija(Vars) :- Vars = [B, D],
                    D :: 1..325000,
                    B :: 150000..600000,
                    B+D #< 600000,
                    2*B #=< D,
                    labeling([maximize(2*B+D)], Vars),
                    K is 2*B+D,
                    write('Maksimalna zarada: '), write(K), write(' dolara.'), nl,
					write('Benzina ima: '), write(B), write(' galona.'), nl,
					write('Dizela ima: '), write(D), write(' galona.'), nl.