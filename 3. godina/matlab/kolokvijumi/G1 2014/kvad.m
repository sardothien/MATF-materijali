% Napisati M-fajl kvad.m sa funkcijom I=kvad(a,b,C) 
% koja izracunava vrednost odredjenog integrala 
% funkcije g na proizvoljnom intervalu (a, b) 
% koristeci koeficijente C kvadraturne formule dobijene
% pod 2 ako se za cvorove uzmu nule Lezandrovog polinoma 
% stepena n.
function I = kvad(a, b, C)

funkcija;
[c, d] = smena(a, b);
[K, X] = nule(length(C));

t = @(x) c.*x+d;
I = sum((C'*g(t(X))))*c;