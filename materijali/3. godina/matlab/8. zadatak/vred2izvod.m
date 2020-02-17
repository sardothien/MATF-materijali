% Napisati M-fajl vred2izvod.m sa funkcijom vred2izvod(x) koja za
% uneti argument x vraca pribliznu vrednost drugog izvoda funkcije
% f izracunatu koriscenjem I Njutnovog interpolacionog polinoma
% konstrusanog na osnovu svih vrednosti iz tablice iz fajla drugiizvod.m.
function vr = vred2izvod(x)

[X, Y, Y2] = drugiizvod();

n = length(Y2);
X2 = X(2:end-1);
kon = Y2;

tabk = zeros(n-1);

for i = 1:n-1
   kon = diff(kon);
   tabk(1:n-i, i) = kon;
end

s = Y2(1);
p = 1;
q = (x - X2(1)) / (X2(2) - X2(1));

for i = 1:n-1
   p = p * (q-i+1); 
   s = s + tabk(1, i) * p / factorial(i);
end

vr = s;