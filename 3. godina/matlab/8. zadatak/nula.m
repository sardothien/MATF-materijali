% Napisati M-fajl nula.m sa funkcijom nula() koja metodom 
% inverzne interpolacije priblizno odredjuje nulu drugog
% izvoda funkcije f koriscenjemI  Njutnovog interpolacionog
% polinoma zakljucno sa konacnim razlikama reda 3. Kriterijum
% zaustavljanja iterativnog niza: abs(qi - q_i-1) <= 10^-4, i=2,...
function x = nula()

[X, Y, Y2] = drugiizvod();

n = length(Y2);
X2 = X(2:end-1);
kon = Y2;
tabk = zeros(n-1);

for i = 1:n-1
   kon = diff(kon);
   tabk(1:n-i, i) = kon;
end

g = @(q) ((-1)*(Y2(1) + (tabk(1,2)*q*(q-1)/2) + (tabk(1,3)*q*(q-1)*(q-2)/6)) / (tabk(1,1)));

h = X2(2) - X2(1);
q0 = g(0);
q1 = g(q0);

while abs(q1 - q0) > 1e-4
   q0 = q1;
   q1 = g(q0);
end

x = X2(1) + q1*h;


