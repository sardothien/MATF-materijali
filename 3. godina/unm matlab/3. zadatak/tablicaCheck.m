% Napisati M-fajl tablicaCheck.m sa funkcijom t = tablicaCheck() 
% koja vrsi proveru da li je tablica u komandnom fajlu tablica.m
% ekvidistantna i da li je niz X zadat u strogo rastucem poretku.
% Ukoliko su oba uslova ispunjena funkcija vraca vrednost 1, u 
% suprotnom vraca vrednost 0 i u oba slucaja ispisuje odgovarajucu poruku.
function t = tablicaCheck()

tablica;

% funkcija diff racuna rastojanje izmedju svaka dva susedna cvora
% pravimo vektor koraka
h = diff(X); 

% ispitujemo da li je tablica ekvidistantna
% ovaj nacin radi samo za celobrojne vrednosti koraka h
% e = all(h == h(1));

% Bolji nacin:
e = all(abs(h-h(1)) < eps*10);

% da li je vektor rastuci?
r = all(h > 0);

% racunamo rezultat ispitivanja i ispisujemo poruku
t = e && r;
if t == 1
    disp('Tablica zadovoljava navedene uslove.')
else
    disp('Tablica ne zadovoljava navedene uslove.')
end