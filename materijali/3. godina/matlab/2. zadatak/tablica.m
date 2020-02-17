% Napisati M-fajl tablica.m sa funkcijom [X, Y] = tablica(a, b, n)
% koja tabelira zadatu funkciju f na intervalu [a, b] sa n cvorova.
function [X, Y] = tablica(a, b, n)

funkcija;

% cvorovi su ekvidistantni na intervalu [a, b]
X = linspace(a, b, n);
Y = f(X);