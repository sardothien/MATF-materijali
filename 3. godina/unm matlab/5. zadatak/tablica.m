% Napisati M-fajl tablica.m sa funkcijom [X1, Y1] = tablica()
% koja formira tablicu gde se vektor X1 sastoji samo od parnih 
% vrednosti vektora X, a vektor Y1 su vrednosti eksplicitno
% zadate funkcije f u cvorovima vektora X1 zaokruzeni na 3 decimale.
function [X1, Y1] = tablica()

podaci;
n = length(X);

X1 = X(mod(X, 2) == 0);
Y1 = f(X1);
Y1 = round(Y1, 3);