% Napisati M-fajl Njutn1.m sa funkcijom y=Njutn1(x,tol) koja
% na izlazu stampa sve kolone konacnih razlika, a zatim racuna 
% i vraca pribliznu vrednost funkcije f (iz M-fajla podaci.m) u
% tacki x, izracunatu koriscenjem I Njutnovog interpolacionog polinoma.
% Elementi ekvidistantnog niza X iz M-fajla podaci.m su cvorovi 
% interpolacije. Za formiranje interpolacionog polinoma koristiti one 
% kolone konacnih razlika ?^k f_i za koje vazi da je 
% max_i|?^k f_i| > 2^k * tol.
function y = Njutn1(x, tol)

podaci;
Y = f(X);
n = length(X);

krazlike = zeros(n-1);
krazlike(:, 1)=diff(Y);

for j = 2:n-1
    for i = 1:n-j
        krazlike(i, j)=krazlike(i+1, j-1)-krazlike(i, j-1);
    end
end

disp('Tablica podeljenih razlika:');
disp(krazlike);

j = 1;
while j <= n-1
   if 2^j * tol > max(abs(krazlike(:,j)))
      break; 
   end
   j = j+1;
end

j = j-1;

y = Y(1);
q = (x-X(1)) / (X(2)-X(1));
Q = q;

for i = 1:j
   y = y + krazlike(1, i)*Q / factorial(i);
   Q = Q*(q-1);
end