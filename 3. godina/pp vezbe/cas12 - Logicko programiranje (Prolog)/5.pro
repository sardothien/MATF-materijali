% Napisati sledece predikate:
% a) maksimum(A, B, M) - odredjuje maksimum za dva broja A i B
maksimum(A, B, M) :- A >= B, M is A.
maksimum(A, B, M) :- A < B, M is B.

maksimum1(A, B, A) :- A >= B.
maksimum1(A, B, B) :- A < B.

maksimum2(A, B, A) :- A >= B, !.
maksimum2(_, B, B).

% b) suma(N, S) - za dati prirodan broj N racuna sumu prvih N brojeva
suma(1, 1).
suma(N, S) :- N > 1, N1 is N-1, suma(N1, S1), S is S1 + N.

% c) sumaParnih(N, S) - za dati paran prirodan broj N racuna sumu parnih brojeva od 2 do N
sumaParnih(2, 2).
sumaParnih(N, S) :- N > 2, N1 is N-2, sumaParnih(N1, S1), S is S1 + N.

% d) proizvod(N, P) - za dati prirodan broj N racuna proizvod prvih N prirodnih brojeva
proizvod(1, 1).
proizvod(N, P) :- N > 1, N1 is N-1, proizvod(N1, P1), P is P1*N.

% e) proizvodNeparnih(N, P) - za dati neparan prirodan broj N racuna proizvod
%    neparnih brojeva od 1 do N
proizvodNeparnih(1, 1).
proizvodNeparnih(N, P) :- N > 1, N1 is N-2, proizvodNeparnih(N1, P1), P is P1*N.

% f) cifre(N) - ispisuje cifre prirodnog broja N recima
cifra(0, nula).
cifra(1, jedan).
cifra(2, dva).
cifra(3, tri).
cifra(4, cetiri).
cifra(5, pet).
cifra(6, sest).
cifra(7, sedam).
cifra(8, osam).
cifra(9, devet).

cifre(N) :- N < 0, !. % fail
cifre(N) :- N >= 0, N < 10, cifra(N, R), write(R), nl, !.
cifre(N) :- N >= 10, N1 is (N//10), cifre(N1), N2 is (N mod 10), cifre(N2).