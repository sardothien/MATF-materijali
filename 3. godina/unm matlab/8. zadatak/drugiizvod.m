% Napisati M-fajl drugiizvod.m sa funkcijom [X, Y, Y2] = drugiizvod() 
% u kom se na osnovu prethodne tablice formira tablica drugog izvoda 
% funkcije f u tackama x2,..., x_n-1 koriscenjem sledece formule: 
% f''(x) = (f(x_i-1)-2f(xi)+f(x_i+1)) / h^2, gde je 
% Y2i = [f''(x2),..., f''(x_n-1)].
function [X, Y, Y2] = drugiizvod()

tablica;

% Y2 = diff(diff(Y)) / h^2; % kraj

n = length(X);
h = X(2) - X(1);

for i = 1:n-2
   Y2(i) = (Y(i) - 2*Y(i+1) + Y(i+2)) / (h^2); 
end