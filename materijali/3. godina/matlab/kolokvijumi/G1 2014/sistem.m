% Napisati M-fajl sistem.m sa funkcijom C=sistem(X) koja 
% formira sistem jednacina za odredjivanje nepoznatih
% koeficijenata ci kvadraturne formule datog oblika tako
% da ona bude tacna za polinome sto je moguce viseg stepena.
% Ulazni argument X predstavlja cvorove kvadraturne formule. 
% Funkcija vraca resenje dobijenog sistema, tj. vrednosti 
% koecijenata, zaokruzene na cetiri decimale. 
function C = sistem(X)

n = length(X);
mat = zeros(n);
vrI = zeros(n, 1);

for i = 1:n
   f = @(x) x.^(i-1);
   vrI(i, 1) = integral(f, -1, 1); % vrednosti integrala
   mat(i, :) = f(X); % vrednosti funkcije
end

disp('Matrica sistema:');
mat

disp('Desna strana sistema:');
C = mat\vrI; % koeficijenti ci
C = round(C.*10^4)./10^4;