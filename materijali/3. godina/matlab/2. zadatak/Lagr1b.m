% Napisati M-fajl Lagr1b.m sa funkcijom [L,y] = Lagr1b(x, a, b, n)
% koji formira i vraca koeficijente Lagranzovog interpolacionog
% polinoma L formiranog koristeci sve vrednosti iz tablice, kao i
% vrednost formiranog polinoma u tacki x.
function [L, y] = Lagr1b(x, a, b, n)

[X, Y] = tablica(a, b, n);
n = length(X);
L = 0;

for i = 1:n
    proizvod = 1;
    for j = 1:n
       if i ~= j
          % conv racuna proizvod dva polinoma
          % proizvod * (x - X(j))
          proizvod = conv(proizvod, [1 -X(j)]/(X(i) - X(j)));  
       end
    end
    L = L + proizvod * Y(i);
end

% vrednost polinoma u tacki
y = polyval(L, x);