% Napisati M-fajl integrals.m sa funkcijom 
% [I, briter] = integrals(a, b, tol) koja sa
% tacnoscu tol racuna i vraca vrednost odredjenog
% integrala funkcije f (granice integracije su a i b)
% koriscenjem uopstene Simpsonove kvadraturne formule. 
% Funkcija vraca vrednost integrala i broj iteracija.
function [I, briter] = integrals(a, b, tol)

n = 3;
funkcija;

h = (b-a) / (n-1);
X = a:h:b;
Y = f(X);
I0 = h/3 * (Y(1) + 4*sum(Y(2:2:end-1)) + 2*sum(Y(3:2:end-1)) + Y(end));

h = h/2;
X = a:h:b;
Y = f(X);
I = h/3 * (Y(1) + 4*sum(Y(2:2:end-1)) + 2*sum(Y(3:2:end-1)) + Y(end));

briter = 2;
while abs(I - I0)/15 > tol
   I0 = I;
   h = h/2;
   X = a:h:b;
   Y = f(X);
   I = h/3 * (Y(1) + 4*sum(Y(2:2:end-1)) + 2*sum(Y(3:2:end-1)) + Y(end));
   briter = briter + 1;
end