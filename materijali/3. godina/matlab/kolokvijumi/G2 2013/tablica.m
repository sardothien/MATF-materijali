% Napisati M-fajl tablica.m sa funkcijom [X, Y] = tablica()
% koja od vektora v iz komandnog fajla podaci.m formira
% vektor X takav da su mu svi elementi medjusobno razliciti,
% nenegativni i sortirani u rastucem redosledu. Vektor Y se
% dobija kao vrednost funkcije f iz komandnog fajla
% podaci.m u svim tackama formiranog vektora X.
function [X,Y] = tablica()

podaci;
n = length(v);
n1 = 1;
pom = 0;

for i = 1:n
   if(v(i) >= 0)
       for j = 1:i-1
           if(v(i) == v(j))
               pom = 1;
           end
       end
       if pom == 0
          Z(n1) = v(i);
          n1 = n1 + 1;
       end
   end
   pom = 0;
end

X = sort(Z);
Y = f(X);