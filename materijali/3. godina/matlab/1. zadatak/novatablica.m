% Napisati M-fajl novatablica.m u kom se prethodna 
% tablica prosiruje do nove dodavanjem cvorova
% (x_i + x_i+1)/2 i racunanjem vrednosti funkcije f
% u njima, koriscenjem formule: 
% f((x_i + x_i+1)/2) = (f(x_i+1)+f(x_i))/2.

tablica;

n = length(X);

% prepisujemo elemente iz X i F na svaku drugu poziciju
X1(1:2:2*n-1) = X;
F1(1:2:2*n-1) = F;

% dodajemo nove clanove
X1(2:2:2*n-1) = (X(1:n-1) + X(2:n))/2;
F1(2:2:2*n-1) = (F(1:n-1) + F(2:n))/2;