% NapisatiM-fajl integrali.m sa funkcijom integrali(f)
% koja koriscenjem ugradjene MATLAB funkcije quad()
% racuna i stampa vrednosti datih integrala, gde je Li(x)
% Lezandrov polinom stepena i. Prosledjena funkcija f 
% moze biti slozena funkcija.
function integrali(f, a, b)

I1 = integral(f, a, b)

g = @(x) f(x).*sin(x);
I2 = integral(g, a, b)

L = legendre_poly(5);
I3 = quad(@(x) f(x).*polyval(L(6,:),x), a, b)

I4 = quad(@(x) polyval(L(6,:),x).*polyval(L(4,:),x), a, b)