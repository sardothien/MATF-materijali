% Napisati M-fajl grafik.m sa funkcijom grafik(a, b)
% koja prikazuje grafik zavisnosti brzine 
% konvergencije Simpsonove kvadraturne formule (plavo)
% i Trapezne kvadraturne formule (crveno), za
% razlicite tolerancije (tol = 10^-1,..., 10^-6).
function grafik(a, b)

% x-osa
tol = 10.^(-(1:6));
% y-osa
brt = tol;
brs = tol;

for i = 1:6
   [I, brt(i)] = integralt(a, b, tol(i));
   [I, brs(i)] = integrals(a, b, tol(i));
end

plot(tol, brt, 'r', tol, brs, 'b');

legend('trapezna', 'Simsponova')