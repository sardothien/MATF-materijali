% Napisati M-fajl Njutn.m sa funkcijom Njutn(x) koja ukoliko
% su svi uslovi ispunjeni, vraca pribliznu vrednost funkcije
% f u tacki x izracunatu koriscenjem I (II) Njutnovog interpolacionog
% polinoma, ako je vrednost funkcije polozaj u tacki x jednaka 1 (2),
% odnosno izdaje odgovarajucu poruku ukoliko je polozaj(x) = 0.
function y = Njutn(x)

if ~tablicaCheck()
    error('Tablica ne zadovoljava navedene uslove.')
end

p = polozaj(x);
tablica;
n = length(X);

% matrica konacnih razlika
krazlike = zeros(n, n-1);

if p == 1 % I Njutnov interpolacioni polinom
    for i = 1:n-1
       krazlike(i, 1) = (F(i+1) - F(i)); 
    end
    
    for j = 2:n-1
       for i = 1:n-j
          krazlike(i, j) = krazlike(i+1, j-1) - krazlike(i, j-1); 
       end
    end
    
    P = F(1);
    q = (x - X(1))/(X(2) - X(1));
    proizvod = q;
    
    for i = 1:n-1
       P = P + proizvod*krazlike(1, i)/factorial(i);
       proizvod = proizvod * (q-i);
    end
    
    y = P;
elseif p == 2 % II Njutnov interpolacioni polinom
    for i = 1:n-1
       krazlike(i, 1) = (F(i+1) - F(i)); 
    end
    
    for j = 2:n-1
       for i = 1:n-j
          krazlike(i, j) = krazlike(i+1, j-1) - krazlike(i, j-1); 
       end
    end
    
    P = F(end);
    h = X(2) - X(1);
    q = (x - X(end)) / h;
    proizvod = q;
    
    for i = 1:n-1
       P = P + proizvod*krazlike(n-i, i)/factorial(i);
       proizvod = proizvod * (q+i);
    end
    
    y = P;
else
   disp('Ne mozemo primeniti Njutna sa konacnim razlikama.') 
end