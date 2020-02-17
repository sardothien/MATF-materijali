% Napisati M-fajl trapez.m sa funkcijom I = trapez(a, b) 
% koja priblizno racuna i vraca vrednost odredjenog
% integrala funkcije f (granice integracije su a i b) 
% koriscenjem uopstene Trapezne kvadraturne formule sa 
% n = 9 cvorova.
function I = trapez(a, b)

funkcija;
n = 9;

X = linspace(a, b, n);
F = f(X);

h = (b-a) / (n-1);

I = h/2 * (F(1) + 2*sum(F(2:end-1)) + F(end));