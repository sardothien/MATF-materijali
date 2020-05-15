% Napisati M-fajl izvod.m sa funkcijom [X, Y, Yi] = izvod() 
% u kom se na osnovu prethodne tablice formira tablica prvog
% izvoda funkcije f u tackama x2,..., x_n-1 koriscenjem sledece
% formule: f'(xi) = (f(x_i+1)-f(x_i-1)) / (x_i+1-x_i-1),
% gde je Yi = [f'(x2),..., f'(x_n-1)].
function [X, Y, Yi] = izvod()

tablica;
n = length(X);

Yi(1:n - 2) = (Y(3:n) - Y(1:n-2)) ./ (X(3:n) - X(1:n-2));