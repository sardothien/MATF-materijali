% Formirati M-fajl sistem.m sa funkcijom sistem(d, t, n)
% koja formira sistem linearnih jednacina koji se dobija
% prilikom nalazenja koeficijenata kvadraturne formule oblika
% integral_0^d(t(x)f(x)dx) = sum_i=0^n(Ai*f((i*d)/n)) koja
% treba da je tacna za polinome sto je moguce veceg stepena.
% Funkcija treba da vraca matricu sistema i vektor desne strane.
function [M, V] = sistem(d, t, n)

M = zeros(n+1);
V = zeros(1, n+1);

for i = 1:n+1
   for j = 1:n+1
       M(i, j) = ((j-1)*d / n)^(i-1);
   end
   p = @(x) t(x).*x.^(i-1);
   V(i) = integrali(p, 0, d);
end

V = V';