% Napisati M-fajl Cebisev_poly.m sa funkcijom C = Cebisev_poly(n)
% koja formira i vraca niz svih Cebisevljevih polinoma do stepena
% n na intervalu [-1, 1]. Nacrtati grafik svih formiranih
% Cebisevljevih polinoma.
function C = Cebisev_poly(n)

C = zeros(n+1);
C(1, n+1) = 1;
C(2, n) = 1;

for i = 2:n
   C(i+1,:) = 2*[C(i, 2:end), 0] - C(i-1,:); 
end

% Iscrtavanje grafika
boje = 'cmykrgb';
X = linspace(-1, 1);

plot(X, polyval(C(1,:), X), boje(1));
hold on
    for i = 2:n+1
       plot(X, polyval(C(i,:), X), boje(mod(i, 7)+1));    
    end
hold off

% DRUGI NACIN
% function C=cebisev_poly(n)
% C=cell(n+1,1); %ovaj red nije obavezan, promenljive tipa cell se ne moraju inicijalizovati
% C{1}=1;
% C{2}=[1 0];
% for i=2:n
%     C{i+1}=2*[C{i} 0]-[0 0 C{i-1}];
% end
% boje='rgycmkb';
% X=linspace(-1,1);
% hold on
% for i=1:n+1
%     plot(X,polyval(C{i},X),boje(mod(i,7)+1));
% end
% hold off
% celldisp(C)