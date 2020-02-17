% Neka je funkcija f zadata tablicno M-fajlom tablica.m koji
% generise dva niza X = [x1,..., xn] i Y = [y1,..., yn] (od kojih
% je prvi strogo rastuci) za tu tablicno zadatu funkciju. Tablica
% mora biti ekvidistantna (sa korakom h).
X = linspace(1,2,6);
f = @(x) exp(x)-15.*x;
Y = f(X);