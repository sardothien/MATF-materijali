% Napisati M-fajl skrati.m sa funkcijom [T, maks]=skrati(A,k)
% koja za ulaznu matricu A=(aij)nxn i realan broj k vraca sve
% kolone j matrice A za koje vazi nejednakost:
% suma_{i=1}^{n-j+1} (abs(aij) <= k(n-j+1)), 1<=j<=n
% Kolone smestiti redom u matricu T. Funkcija vraca i niz maks,
% gde su elementi niza maks redom maksimumi elemenata po vrstama
% matrice T.
function [T, maks] = skrati(A, k)

n = length(A);
T = zeros(n);

i = 1;
for j = 1:n
    if sum(abs(A(1:n-j+1, j))) / (n-j+1) <= k
       T(:, i) = A(:, j);
       i = i+1;
    end
end

T = T(:, 1:i-1);
maks = max(T');