% Napisati M-fajl vredizvod.m sa funkcijom vredizvod(x) koja
% za uneti argument x vraca pribliznu vrednost prvog izvoda 
% funkcije f izracunatu koriscenjem Njutnovog interpolacionog 
% polinoma sa podeljenim razlikama konstrusanog na osnovu svih
% vrednosti iz tablice iz fajla izvod.m.
function vr = vredizvod(x)

[X, Y, Yi] = izvod();
n = length(Yi);

tab = zeros(n-1);
pod = Yi;
X1 = X(2:end-1);

for i = 1:n-1
   pod = diff(pod) ./ (X1(i+1:n) - X1(1:n-i));
   tab(1:n-i, i) = pod;
end


s = Yi(1);
proizvod = 1;
for i = 1:n-1
   proizvod = proizvod * (x - X1(i)); 
   s = s + proizvod*tab(1, i);
end

vr = s;