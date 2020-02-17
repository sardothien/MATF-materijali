function [y,L]=vredfunc(x)

tablica;

n=length(X);

prazlike=zeros(n-1,n-1);

for i=1:n-1
   prazlike(i,1) = (Y(i+1)-Y(i)) / (X(i+1)-X(i));
end

for j=2:n-1
    for i=1:n-j
        prazlike(i,j) = (prazlike(i+1,j-1) - prazlike(i,j-1)) / (X(i+j) - X(i));
    end
end

prazlike

L = Y(1);
proizvod = 1;

for i=1:n-1
    proizvod = conv(proizvod,[1, -X(i)]);
    L = [0,L] + proizvod*prazlike(1, i);
end

y = polyval(L, x);