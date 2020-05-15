% Napisati M-fajl izvod1.m sa funkcijom izvod1(x) koja racuna
% vrednost prvog izvoda tabelirane funkcije u tacki x koristeci
% diferenciranje I Njutnovog interpolacionog polinoma zakljucno
% sa konacnim razlikama reda 4.
function vr1 = izvod1(x) 

tablica;

n = length(Y);
kon = Y;
tabk = zeros(n-1);

for i = 1:n-1
   kon = diff(kon);
   tabk(1:n-i, i) = kon;
end

% disp([X', Y', [tabk; zeros(1, n-1)]]);

h = X(2) - X(1);
q = (x - x(1)) / h;

vr1 = (tabk(1,1) + (tabk(1,2) * (2*q-1)/2) + (tabk(1,3) * (3*q*q-6*q+2)/6) + (tabk(1,4) * (4*q*q*q-18*q*q+22*q-6)/24)) / h;