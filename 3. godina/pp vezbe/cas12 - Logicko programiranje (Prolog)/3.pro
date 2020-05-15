/* Unifikacija, Jednakost
        = da li su unifikabilni
        \= nisu unifikabilni
        == identicno jednaki termovi
        \== nisu identicno jednaki
*/

uni(X, Y) :- X = Y.
jed(X, Y) :- X == Y.

/* Aritmeticki operatori
        is - aritmeticko izracunavanje
        =:= - aritmeticka jednakost
        =\= - aritmeticki nisu jednaki
        <, <=, >, >=
        +, -, *, /, // (celobrojno deljenje)
        div, mod, ** (stepenovanje) 
*/

op1(X, Y) :- X is Y.
% ako je X promenljiva: X <- Y
% inace, vrsi se poredjenje X =:= Y

abs(X, X) :- X >= 0.
abs(X, Y) :- X < 0, Y is -X.
% Drugi nacin:
abs1(X, X) :- X >= 0, !.
abs1(X, Y) :- Y is -X.

/* Rekurzivni predikati (porodicno stablo) */

% cinjenice

musko(mihajlo).
musko(stevan).
musko(petar).
musko(mladen).
musko(rajko).

zensko(milena).
zensko(milica).
zensko(jelena).
zensko(mina).
zensko(maja).
zensko(senka).

roditelj(mihajlo, milica). % mihajlo je roditelj milice
roditelj(mihajlo, senka).
roditelj(milena, rajko).
roditelj(maja, petar).
roditelj(maja, mina).
roditelj(stevan, mladen).
roditelj(stevan, jelena).
roditelj(milica, mladen).
roditelj(milica, jelena).

% pravila

% X je majka od Y
majka(X, Y) :- roditelj(X, Y), zensko(X).
% X je otac od Y
otac(X, Y) :- roditelj(X, Y), musko(X).
% Y je brat od X
brat(X, Y) :- musko(Y), roditelj(Z, X), roditelj(Z, Y), X \== Y, !.
% Y je sestra od X
sestra(X, Y) :- zensko(Y), roditelj(Z, X), roditelj(Z, Y), X \== Y, !.
% Y je ujak od X
ujak(X, Y) :- brat(Z, Y), majka(Z, X).
% Y je tetka od X
tetka(X, Y) :- sestra(Z, Y), roditelj(Z, X).

% Rekurzivna pravila:
% Y je predak od X
predak(X, Y) :- roditelj(Y, X).
predak(X, Y) :- roditelj(Z, X), predak(Z, Y).
