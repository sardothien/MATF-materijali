% Napisati M-fajl simps.m sa funkcijom I = simps(a, b, n)
% koja racuna vrednost integrala od a do b f(x)dx (f je iz
% fajla podaci.m) koriscenjem Simpsonove kvadraturne formule 
% sa n cvorova.
function I = simps(a, b, n)

podaci;
X = linspace(a, b, n);
Y = f(X);

h = (b-a) / (n-1);

I = h/3 * (Y(1) + 4*sum(Y(2:2:end-1)) + 2*sum(Y(3:2:end-1)) + Y(end));