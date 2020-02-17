% Napisati M-fajl integral.m sa funkcijom I = integral(n, m, tol)
% koja sa tacnoscu tol priblizno odredjuje i kao rezultat vraca
% vrednost integrala integral_-1^1(P(x)e^xdx). Integral racunati
% koriscenjem uopstene Simpsonove formule. Polinom P(x) je polinom
% dobijen pod (2).
function I = integral(n, m, tol)

a = -1;
b = 1;

P = polinom(n, m);
f = @(x) polyval(P, x).*exp(x);

h = (b-a) / (n-1);
X = a:h:b;
Y = f(X);
S1 = h/3 * (Y(1) + 4*sum(Y(2:2:end-1)) + 2*sum(Y(3:2:end-1)) + Y(end));

h = h/2;
X = a:h:b;
Y = f(X);
S2 = h/3 * (Y(1) + 4*sum(Y(2:2:end-1)) + 2*sum(Y(3:2:end-1)) + Y(end));

while abs(S1-S2)/15 > tol
   S1 = S2;
   h = h/2;
   X = a:h:b;
   Y = f(X);
   S2 = h/3 * (Y(1) + 4*sum(Y(2:2:end-1)) + 2*sum(Y(3:2:end-1)) + Y(end));
end

I = S2;