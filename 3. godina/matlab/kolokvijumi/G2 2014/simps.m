% Napisati M-fajl simps.m sa funkcijom y=simps() koja
% izracunava vrednost odredjenog integrala funkcije f 
% date M-fajlom tablica.m na segmentu odredjenom krajevima
% vektora X koristeci Simpsonovu kvadraturnu formulu i sve
% vrednosti iz tablice. Ispisati poruku ukoliko nisu ispunjenu
% uslovi za primenu metode.
function y = simps()

tablica; 

n = length(X);
a = X(1);
b = X(end);
h = (b-a)/(n-1);

y = h/3 * (F(1) + 4*sum(F(2:2:n-1)) + 2*sum(F(3:2:end-1)) + F(end));