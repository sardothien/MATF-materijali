% Formirati M-fajl koeficijenti.m sa funkcijom koeficijenti(d, t, n)
% koja odredjuje koeficijente Ai gore napisane kvadraturne formule. 
% Dozvoljeno je koriscenje operatora n za resavanje sistema.
function rez = koeficijenti(d, t, n)

[M, V] = sistem(d, t, n);
rez = M\V;