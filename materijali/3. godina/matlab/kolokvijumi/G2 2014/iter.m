% Napisati M-fajl iter.m sa funkcijom x=iter(Q) koja
% metodom inverzne interpolacije, koristeci koeficijente
% polinoma dobijene pod 2, priblizno odredjuje x za koje je
% f(x) = y. Iterativni proces zaustaviti kada se ispuni uslov
% abs(qi - q_i-1) <= 10^-5. U komandnom prozoru stampati poslednje qi.
function x = iter(Q)

q0 = 0;
q = polyval(Q, q0);

while abs(q0-q) > 1e-5
   q0 = q;
   q = polyval(Q, q0);
end

disp(q);

tablica;
h = X(2) - X(1);
x = q*h + X(1);