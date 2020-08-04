% Napisati sledece predikate:
% (a) sumaCifara(N, SC) - odredjuje sumu cifara prirodnog broja N
sumaCifara(N, N) :- N < 10, !.
sumaCifara(N, SC) :- N1 is N div 10, sumaCifara(N1, S), SC is S + (N mod 10).

% (b) brojCifara(N, BC) - odredjuje broj cifara prirodnog broja N
brojCifara(N, 1) :- N < 10, !.
brojCifara(N, BC) :- N1 is N div 10, brojCifara(N1, B), BC is B+1.

% (c) maxCifra(N, MC) - odredjuje maksimalnu cifru prirodnog broja N
max(A, B, A) :- A >= B, !.
max(_, B, B).

maxCifra(N, N) :- N < 10, !.
maxCifra(N, MC) :- N1 is N div 10, maxCifra(N1, M), K is N mod 10, max(M, K, X), MC is X.

% (d) sumaKvadrata(N, SK) - racuna sumu kvadrata prvih N prirodnih brojeva
sumaKvadrata(1, 1) :- !.
sumaKvadrata(N, SK) :- N1 is N-1, sumaKvadrata(N1, S), SK is S + N*N.

% (e) fakt(N, F) - racuna faktorijel prirodnog broja N
fakt(1, 1) :- !.
fakt(N, F) :- N1 is N-1, fakt(N1, F1), F is F1*N.

% (g) sumaDel(X, D) - racuna sumu pravih delilaca broja X
suma(_, 1, 0) :- !.
suma(N, K, S) :- N mod K =:= 0, K1 is K-1, suma(N, K1, S1), S is S1+K, !.
suma(N, K, S) :- N mod K =\= 0, K1 is K-1, suma(N, K1, S1), S is S1, !.

sumaDel(N, S) :- suma(N, N-1, S).