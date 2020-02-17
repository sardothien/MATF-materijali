% Napisati M-fajl nule.m sa funkcijom [K,X]=nule(n)
% koja vraca koeficijente Lezandrovog polinoma 
% stepena n (vektor K) i nule tog polinoma sortirane
% u rastucem poretku i zaokruzene na cetiri decimale
% (vektor X).
function [K, X] = nule(n)

% Lezandrovi polinomi preko eksplicitne formule
L = 1;
for i = 1:n % (x^2 - 1)^n
   L = conv(L, [1 0 -1]);
end
for i = 1:n % n-ti izvod 
   L = polyder(L); 
end
L = L ./ (2^n*factorial(n));
K = L;

X = sort(round(roots(K).*10^4)./10^4);
X = X';