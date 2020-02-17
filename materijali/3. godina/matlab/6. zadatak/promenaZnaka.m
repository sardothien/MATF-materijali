% Napisati M-fajl promenaZnaka.m sa funkcijom 
% [c, d] = promenaZnaka(a, b, n) koja na osnovu
% nizova X i Y dobijenih pozivanjem funkcije 
% tablica(a, b, n) pronalazi i kao rezultat vraca prvi
% interval [xi, x_i+1] u kome funkcija menja znak 
% (c = xi, d = x_i+1). Pretpostavlja se da takav
% interval postoji.
function [c,d] = promenaZnaka(a, b, n)

[X,Y] = tablica(a, b, n);

% prvi argument - uslov po kome trazimo
% drugi argument - broj elemenata koji zelimo da vrati
k = find(Y(1:end-1).*Y(2:end) <= 0,1);
c = X(k);
d = X(k+1);