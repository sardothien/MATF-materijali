% Uporediti grafike funkcije f i formiranog interpolacionog polinoma.
function grafik(a, b, n)

[L, y] = Lagr1b(1, a, b, n);

funkcija;
X = linspace(a, b);
Y = f(X);

% zadrzavamo prozor kako bi oba grafika bila na istoj slici
hold on 
    plot(X, Y, 'b'); % grafik funkcija
    plot(X, polyval(L, X), 'r'); % grafik polinoma
hold off

legend('funkcija', 'interpolacioni polinom')