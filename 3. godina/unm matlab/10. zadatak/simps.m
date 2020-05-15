% Napisati M-fajl simps.m sa funkcijom I = simps(a, b)
% koja priblizno racuna i vraca vrednost odredjenog
% integrala funkcije f (granice integracije su a i b)
% koriscenjem uopstene Simpsonove kvadraturne formule
% sa n = 9 cvorova.
function I = simps(a, b)

n = 9;
funkcija;

X = linspace(a, b, n);
F = f(X);

h = (b-a) / (n-1);

I = h/3 * (F(1) + 4*sum(F(2:2:end-1)) + 2*sum(F(3:2:end-1)) + F(end));