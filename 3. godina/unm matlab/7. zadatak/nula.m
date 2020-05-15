% Napisati M-fajl nula.m sa funkcijom nula() koja metodom 
% inverzne interpolacije priblizno odredjuje i vraca jednu
% nulu prvog izvoda funkcije f koriscenjem Njutnovog
% interpolacionog polinoma sa podeljenim razlikama (pretpostavka
% je da je prvi izvod monotona funkcija).
function x = nula()

[X, Y, I] = izvod();
y = 0;

[X1, ind] = sort(I);
Y1 = X(2:end-1);
Y1 = Y1(ind);
n = length(Y1);

tab = zeros(n-1);
pod = Y1;

for i = 1:n-1
   pod = diff(pod) ./ (X1(i+1:n) - X1(1:n-i));
   tab(1:n-i, i) = pod;
end

% Odredjivanje nule funkcije
s = Y1(1);
r = 1;
for i = 1:n-1
   r = r * (y - X1(i));
   s = s + (tab(1, i) * r);
end

x = s;