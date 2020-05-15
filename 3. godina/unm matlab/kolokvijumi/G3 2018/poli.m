% Napisati M-fajl poli.m sa funkcijom L=poli(n,a)
% koja formira i vraca koeficijente L polinoma stepena 
% n odredjenog datom rekurentnom formulom.
function L = poli(n, a)

L = cell(1, n);
P{1} = 1;
P{2} = [-1 1+a];

for j = 1:n-1
    P{j+2} = (conv([-1 2*j+a+1], P{j+1}) - (j+a)*[0 0 P{j}]) / (j+1);
end

L = P{n+1};