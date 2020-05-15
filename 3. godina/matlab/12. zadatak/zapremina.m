% Napisati M-fajl zapremina.m sa funkcijom zapremina(a, b, tol)
% koja koristeci uopstenu Simpsonovu kvadraturnu formulu vraca
% zapreminu tela nastalog obrtanjem figure ogranicene pravama
% y = 0; x = a; x = b i funkcijom f oko ose Ox izracunatu sa
% tacnoscu tol. (Za ocenu tacnosti koristiti funkciju Runge.)
function V = zapremina(a, b, tol)

funkcija;
% zapremina figure
f = @(x) pi*f(x).^2;

n = 3;
h = (b-a) / (n-1);
X = a:h:b;
Y = f(X);
S1 = h/3 * (Y(1) + 4*sum(Y(2:2:end-1)) + 2*sum(Y(3:2:end-1)) + Y(end));

h = h/2;
X = a:h:b;
Y = f(X);
S2 = h/3 * (Y(1) + 4*sum(Y(2:2:end-1)) + 2*sum(Y(3:2:end-1)) + Y(end));

vr = Runge(S1, S2);
while vr > tol
   S1 = S2;
   h = h/2;
   X = a:h:b;
   Y = f(X);
   S2 = h/3 * (Y(1) + 4*sum(Y(2:2:end-1)) + 2*sum(Y(3:2:end-1)) + Y(end));
   vr = Runge(S1, S2);
end

V = S2;