% Napisati M-fajl nula.m sa funkcijom nula(a, b, n) koja
% metodom inverzne interpolacije priblizno odredjuje nulu
% funkcije f na intervalu [c, d], koristeci II Njutnov 
% interpolacioni polinom zakljucno sa konacnim razlikama
% reda 3. Kriterijum zaustavljanja iterativnog niza: 
% abs(q_i - q_i-1) <= 10^-4, i = 2, 3...
function x = nula(a, b, n)

[c, d] = promenaZnaka(a, b, n);
X = linspace(c, d, n);

funkcija;
Y = f(X);

krazlike = zeros(n-1, n-1);

for i = 1:n-1
    krazlike(i, 1) = Y(i+1) - Y(i);
end

for j = 2:n-1
   for i = 1:n-j
      krazlike(i, j) = krazlike(i+1, j-1) - krazlike(i, j-1); 
   end
end

% transformisemo polinom i formiramo iterativni niz
fi = @(q) (-1/krazlike(end, 1)) * (Y(end) + q*(q+1)/2 * krazlike(end-1, 2) + q*(q+1)*(q+2)/6 * krazlike(end-2, 3));
q0 = 0;
q1 = fi(0);

while abs(q1 - q0) > 1e-4
   q0 = q1;
   q1 = fi(q0);
end

q = q1;
x = q*(X(2)-X(1)) + X(end);