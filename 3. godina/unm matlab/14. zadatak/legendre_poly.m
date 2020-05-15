% Napisati M-fajl legendre_poly.m sa funkcijom L = legendre_poly(n)
% koja formira i vraca niz svih Lezandrovih polinoma do stepena n 
% na intervalu [-1, 1]. Nacrtati grafik svih formiranih
% Lezandrovih polinoma.
function L = legendre_poly(n)

L = zeros(n+1);

% U prvu vrstu upisujemo koeficijente polinoma nultog stepena
L(1, n+1) = 1;
% U drugu vrstu upisujemo koeficijente polinoma prvog stepena
L(2, n) = 1; 

for i = 2:n
   L(i+1, :) = ((2*i-1)*[L(i, 2:end), 0] - (i-1)*L(i-1, :)) / i; 
end

% Iscrtavanje grafika
boje = 'cmykrgb';
X = linspace(-1, 1);

plot(X, polyval(L(1,:), X), boje(1));
hold on
    for i = 2:n+1
       plot(X, polyval(L(i, :), X), boje(mod(i,7)+1)); 
    end
hold off

% DRUGI NACIN
% function L = legendre_poly(n)
% L=cell(n+1,1);  %ovaj red nije obavezan, promenljive tipa cell se ne moraju inicijalizovati
% L{1}=1;
% L{2}=[1 0];
% for i=2:n
%     L{i+1}=((2*i-1)*[L{i} 0]-(i-1)*[0 0 L{i-1}])/i;
% end
% boje='rgycmkb';
% X=linspace(-1,1);
% hold on
% for i=1:n+1
%     plot(X,polyval(L{i},X),boje(mod(i,7)+1));
% end
% hold off
% celldisp(L)