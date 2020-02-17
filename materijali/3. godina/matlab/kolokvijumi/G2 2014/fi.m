% Napisati M-fajl fi.m sa funkcijom Q=fi(koef,y) koja polinom
% Pn(q) sa koeficijentima koef transformise u funkciju (polinom)
% q = Q(q) sa kojom se moze formirati iterativni niz za odredjivanje
% vrednosti argumenta q za koju je y = Pn(q). (Ova funkcija I Njutnov
% interpolacioni polinom transformise u oblik pogodan za inverznu
% interpolaciju.)
function Q = fi(koef, y)

Q = koef;
Q(end) = Q(end) - y;
Q = Q./(-Q(end-1));
Q(end-1) = 0;