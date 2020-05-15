/* Liste - niz elemenata (termova)
    * []
    * .(G, R) - G je glava, R je rep liste

    * jednoclana lista
        .(a, [])
        [a]
    * dvoclana lista
        .(a, .(b, []))
        [a, b]

    * [G|R] = [a, b, c] -> G = a, R = [b, c]
    * [G, RG|RR] = [a, b, c, d]
*/

/* 1. Napisati predikat sadrzi koji proverava da li element pripada listi. */
sadrzi(X, [X|_]) :- !. % element X je u glavi liste
sadrzi(X, [_|R]) :- sadrzi(X, R). % inace, nalazi se u repu
% ! operator vraca True i odseca pretragu

% drugi nacin - pomocu disjunkcije
sadrzi1(X, [G|R]) :- G == X; sadrzi1(X, R).


/* 2. Napisati predikat duzina koji odredjuje duzinu liste. */
duzina([], 0).
duzina([_|R], D) :- duzina(R, D1), D is 1+D1.

/* 3. Napisati predikat suma koji racuna zbir elemenata liste. */
suma([], 0).
suma([G|R], S) :- number(G), suma(R, S1), S is S1+G.

/* 4. Napisati predikat koji racuna aritmeticku sredinu A liste L. */
aritm(L, A) :- duzina(L, D), D>0, suma(L, S), A is S/D.

/* 5. Predikat ucitava listu duzine N ciji elementi mogu biti proizvoljni
      termovi. Za negativno N ne ucitava listu. */
ucitaj(N, _) :- N<0, !. % cut operator ovde nije obavezan
ucitaj(0, []). % 0 elemenata -> prazna lista
ucitaj(N, [G|R]) :- N>=1, write('element: '), read(G), nl, N1 is N-1, ucitaj(N1, R).
% novi red pri pokretanju je sa tackom: 1.