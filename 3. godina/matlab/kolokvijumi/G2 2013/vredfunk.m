% Uz pretpostavku da su svi uslovi za primenu metode ispunjeni,
% napisati M-fajl vredfunk.m sa funkcijom y = vredfunk(x) koja
% vraca pribliznu vrednost funkcije f u tacki x izracunatu
% koriscenjem II Njutnovog interpolacionog polinoma. Koristiti
% tablicu dobijenu pod (1). Formirati i koristiti konacne razlike 
% dokle god postoji bar jedna vrednost po koloni koja je po 
% apsolutnoj vrednosti veca od 10^-2. Odstampati tabelu konacnih razlika.
function y = vredfunk(x)

[X Y] = tablica();

n = length(X);
krazlike = zeros(n, n+1);

krazlike(:, 1) = X';
krazlike(:, 2) = Y';

for i=1:n-1
    krazlike(1:n-i, i+2) = diff(krazlike(1:n-i+1, i+1));
end

krazlike = krazlike(:, 2:end);
pom=1;

while(~isequal(abs(krazlike(:,pom)') > 10^(-2), zeros(1,length(krazlike))))
    pom = pom+1;
end

krazlike = krazlike(:, 1:pom-1);

disp('Tablica konacnih razlika:');
disp(krazlike);

% II Njutnov interpolacioni polinom
q = (x-X(n))/(X(2)-X(1));
p = 1;
y = Y(n);

for i = 1:length(krazlike(1,:))-1
    p = p * (q+i-1);
    y = y + p*krazlike(n-i,i+1)/factorial(i);
end
