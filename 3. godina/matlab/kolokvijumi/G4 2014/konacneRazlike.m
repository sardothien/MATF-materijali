% Napisati M-fajl konacneRazlike.m sa funkcijom 
% kR = konacneRazlike(a,b,n,m) koja formira i 
% vraca matricu konacnih razlika zakljucno sa
% redom m koriscenjem svih vrednosti tablice
% formirane u prethodnom delu (matrica konacnih 
% razlika ne sadrzi kolone X i Y).
function kR = konacneRazlike(a, b, n, m)

[X, Y] = tablica(a, b, n);

kR = zeros(n-1, m);
kR(:, 1) = diff(Y);
for i = 2:m
   kR(1:n-i, i) = diff(kR(1:n-i+1, i-1)); 
end