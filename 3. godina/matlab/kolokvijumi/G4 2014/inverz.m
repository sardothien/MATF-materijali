% Napisati M-fajl inverz.m sa funkcijom I=inverz(n,z) koja
% koriscenjem ugradjene Matlab funkcije za LU dekompoziciju
% odredjuje i vraca inverz matrice M. Elemente matrice I 
% zaokruziti na z decimala. Matrica M se dobija pozivanjem
% funkcije M=matrica(n). Nije dozvoljeno koriscenje ugradjenih 
% Matlab funkcija za odredjivanje inverza matrice.
function I = inverz(n, z)

M = matrica(n);
[L, U, P] = lu(M);

jedinicna = P * eye(n);
I = zeros(n);
y = zeros(1, n);
x = zeros(1, n);

for i = 1:n
   b = jedinicna(:,i);
   y(1) = b(1);
   
   for j = 2:n
       y(j) = b(j) - sum(L(j, 1:j-1).*y(1:j-1));
   end
   
   x(n) = round((y(n)/U(n,n))*10^z)/10^z;
   for j = n-1:-1:1
       x(j) = round(((y(j) - sum(U(j, j+1:n).*x(j+1:n)))/U(j,j))*10^z)/10^z;
   end
   
   I(:,i) = x';
end