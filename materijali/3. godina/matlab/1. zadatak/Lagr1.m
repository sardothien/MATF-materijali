% Napisati M-fajl Lagr1.m sa funkcijom L = Lagr1(x)
% koja za uneti argument x vraca pribliznu vrednost
% funkcije f u toj tacki izracunatu pomocu Lagranzovog
% interpolacionog polinoma L, koriscenjem svih vrednosti
% iz nove tablice.

function L = Lagr1(x)

novatablica;

suma = 0;
n = length(X);

for i = 1:n
   proizvod = 1;
   for j = 1:n
      if j ~= i
          proizvod = proizvod * (x - X1(j))/(X1(i) - X1(j)); 
      end 
   end
   suma = suma + proizvod*F1(i);
end

L = suma