% Napisati M-fajl njutn1.m sa funkcijom koef=njutn1() koja
% vraca koeficijente I Njutnovog interpolacionog polinoma
% funkcije f po promenljivim q. U komandnom prozoru stampati
% tablicu konacnih razlika.
function koef = njutn1()

tablica;
n = length(X);

% I Njutnov interpolacioni polinom sa konacnim razlikama
krazlike = zeros(n, n+1);

krazlike(:, 1) = X;
krazlike(:, 2) = F;
for i = 1:n-1
     krazlike(1:n-i, i+2) = diff(krazlike(1:n-i+1, i+1));
end
 
disp(krazlike);

% koeficijenti
razlike = krazlike(1, 2:end);
polinom = [1 0]; % x
koef = [zeros(1, n-1) razlike(1)];

for i = 2:n
   koef = koef + [zeros(1, n-i) (razlike(i)/factorial(i-1))*polinom];
   polinom = conv(polinom, [1 1-i]);
end