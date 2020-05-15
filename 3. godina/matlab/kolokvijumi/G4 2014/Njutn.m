% Napisati M-fajl Njutn.m sa funkcijom [R1, R2] = Njutn(a,b,n,m,x)
% koja stampa vrednost funkcije f eksplicitno zadate fajlom funkcija.m
% u tacki x a zatim, koriscenjem svih vrednosti prethodno odredjene
% tablice kR, odredjuje i stampa vrednost I i II Njutnovog interpolacionog 
% polinoma u tacki x. Funkcija vraca R1 i R2, gde Ri predstvlja razliku 
% izmedju dobijene tacne vrednosti funkcije i dobijene vrednosti odgovarajuceg
% (I/II) interpolacionog polinoma.
function [R1, R2] = Njutn(a, b, n, m, x)

funkcija;

disp('Vrednost funkcije u tacki x:');
F = f(x)

[X, Y] = tablica(a, b, n);
kR = konacneRazlike(a, b, n, m);

% I Njutnov interpolacioni polinom
koef1 = kR(1,:);
L1 = [zeros(1,m) Y(1)];
polinom = [1 0];

for i = 1:m
   L1 = L1 + [zeros(1, m-i) (koef1(i)/factorial(i))*polinom];
   polinom = conv(polinom, [1, -i]);
end

disp('Vrednost I Njutnovog interpolacionog polinoma u x:');
q = (x - X(1)) / (X(2) - X(1));
N1 = polyval(L1, q)

% II Njutnvo interpolacioni polinom
koef2 = zeros(1, m);
for i = 1:m
    koef2(i) = kR(n-i, i);
end

L2 = [zeros(1,m) Y(n)];
polinom = [1 0];

for i = 1:m
   L2 = L2 + [zeros(1, m-i) (koef2(i)/factorial(i))*polinom];
   polinom = conv(polinom, [1, i]);
end

disp('Vrednost II Njutnovog interpolacionog polinoma u x:');
q = (x - X(n)) / (X(2) - X(1));
N2 = polyval(L2, q)

R1 = N1 - F;
R2 = (N2 - F)*(-1.0);