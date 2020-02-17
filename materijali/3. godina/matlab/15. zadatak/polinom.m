% Napisati M-fajl polinom.m sa funkcijom P = polinom(n, m)
% koja kao rezultat vraca polinom P dobijen preko date formule
% gde je Ln(x) Lezandrov polinom stepena n za -1<=x<=1.
function P = polinom(n, m)

L = legendre(n);

% m-ti izvod polinom L
for i = 1:m
   L = polyder(L); 
end

P = conv([-1, 0, 1], L);