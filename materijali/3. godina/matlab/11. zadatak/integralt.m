% Napisati M-fajl integralt.m sa funkcijom 
% [I, briter] = integralt(a, b, tol) koja sa
% tacnoscu tol racuna i vraca vrednost odredjenog
% integrala funkcije f (granice integracije su a i b) 
% koriscenjem uopstene Trapezne kvadraturne formule.
% Funkcija vraca vrednost integrala i broj iteracija.
function [I, briter] = integralt(a, b, tol)

% briter - broj iteracija
funkcija;

% ako u zadatku nije receno, n = 3!
n = 3;

h = (b-a) / (n-1);
X = a:h:b;
Y = f(X);
I0 = h/2 * (Y(1) + 2*sum(Y(2:end-1)) + Y(end));

% polovimo korak
h = h/2;
X = a:h:b;
Y = f(X);
I = h/2 * (Y(1) + 2*sum(Y(2:end-1)) + Y(end));

briter = 2;

%koristimo Rungeovu ocenu greske
while abs(I - I0)/3 > tol
   I0 = I;
   h = h/2;
   X = a:h:b;
   Y = f(X);
   I = h/2 * (Y(1) + 2*sum(Y(2:end-1)) + Y(end));
   briter = briter + 1;
end