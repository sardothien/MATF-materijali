% Napisati M-fajl izvod2.m sa funkcijom izvod2(x) koja racuna
% vrednost drugog izvoda tabelirane funkcije u tacki x koristeci
% diferenciranje I Njutnovog interpolacionog polinoma zakljucno
% sa konacnim razlikama reda 4.
function vr2 = izvod2(x)

tablica;

n = length(Y);
kon = Y;
tabk = zeros(n-1);

for i = 1:n-1
   kon = diff(kon);
   tabk(1:n-i, i) = kon;
end

h = X(2) - X(1);
q = (x - X(1)) / h;

vr2 = (tabk(1,2) + (tabk(1,3) * (6*q-6)/6) + (tabk(1,4) * (12*q*q-36*q+22)/24)) / (h*h);