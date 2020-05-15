% Napisati predikate za sortiranje liste rastuce:

/* (a) insertionSort(L, SL)- insertion sort algoritam se zasniva 
       na ubacivanju redom svakog elementa liste na svoje pravo
       mesto (mesto u sortiranoj listi). */
ubaciS(X, [], [X]). % X u praznu listu
ubaciS(X, [G|R], [X, G|R]) :- X=<G, !.
ubaciS(X, [G|R], [G|SL]) :- ubaciS(X, R, SL).

insertionSort([], []).
insertionSort([G|R], SL) :- insertionSort(R, S1), ubaciS(G, S1, SL).       
       
/* (b) mergeSort(L, SL)- merge sort algoritam se zasniva na dekompoziciji
       liste, tj. listu delimo na dva jednaka dela, te delove sortiramo 
       i posle toga ih objedinjujemo. */
mergeSort([], []).
mergeSort([X], [X]) :- !.
mergeSort(L, NL) :- podeli(L, A, B), mergeSort(A, NA), mergeSort(B, NB), objedini(NA, NB, NL).

podeli([], [], []).
podeli([X], [X], []).
podeli([G1, G2|R], [G1|R1], [G2|R2]) :- podeli(R, R1, R2).

objedini(L, [], L).
objedini([], L, L).
objedini([G1|R1], [G2|R2], [G1|R]) :- G1<G2, objedini(R1, [G2|R2], R).
objedini([G1|R1], [G2|R2], [G2|R]) :- G1>=G2, objedini([G1|R1], R2, R).