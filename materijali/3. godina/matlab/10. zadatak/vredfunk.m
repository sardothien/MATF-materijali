% Napisati M-fajl vredfunk.m sa funkcijom [X, Y] = vredfunk(k, p)
% koja priblizno izracunava vrednost funkcije
% I(x) = integral^x_1(f(t)dt), kada se x krece od 2 do k, k >= 2
% sa korakom 1. Ukoliko je p = 1 integrale racunati koristeci 
% uopstenu Simpsonovu kvadraturnu formulu (sa n = 9 cvorova),
% a u slucaju kada je p = 2 uopstenu Trapeznu kvadraturnu formulu
% (sa n = 9 cvorova). Funkcija vraca dva niza: X sa vrednostima xi
% i Y sa izracunatim vrednostima funkcije I(x) u tackama xi.
function [X, Y] = vredfunk(k, p)

X = 2:k;
Y = X;

if p == 1
    for i = 1:k-1
       Y(i) = simps(1, X(i)); 
    end    
elseif p == 2
    for i = 1:k-1
       Y(i) = trapez(1, X(i)); 
    end 
else
    disp('Greska!')
end