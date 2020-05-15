% Napisati M-fajl inverz.m sa funkcijom inverz(y) koja 
% za zadatu vrednost y inverznom interpolacijom priblizno
% odredjuje x za koje je f(x) = y. Tablica nece biti 
% ekvidistantna, pa koristimo Lagranzov interpolacioni polinom.
function x = inverz(y)

[X1, Y1] = tablica();
n = length(X1);
L = 0;

for i = 1:n
   proizvod = 1;
   for j = 1:n
      if i ~= j
         proizvod = proizvod * (y - Y1(j))/(Y1(i) - Y1(j)); 
      end
   end
   L = L + proizvod*X1(i);
end

x = L;