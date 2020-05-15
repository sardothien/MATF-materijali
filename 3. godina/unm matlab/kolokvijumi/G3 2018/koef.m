% Napisati M-fajl koef.m sa funkcijom C=koef(L,p,a,b) koja vraca
% koeficijente ci kvadraturne formule datog oblika, tako da  ona 
% bude tacna za polinome sto je moguce veceg stepena, gde je p(x)
% tezinska funkcija. Cvorovi kvadraturne formule su elementi niza L.
% Integrale racunati koristeci ugradjenu MATLAB funkciju integral(). 
% Dozvoljeno je koriscenje ugradjenog operatora \ za resavanje sistema 
% linearnih jednacina. Funkcija iscrtava i grafik funkcije p^2(x) na
% segmentu [a,b].
function C = koef(L, p, a, b)

n = length(L);

A = ones(n);
B = zeros(n, 1);

for i = 1:n
   f = @(x) x.^(i-1);
   A(i,:) = f(L);
   B(i) = integral(@(x) f(x).*p(x), a, b);
end

C = A\B;

X = linspace(a, b);
Y = p(X).*p(X);
plot(X, Y, 'b');