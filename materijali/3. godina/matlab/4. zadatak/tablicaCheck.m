% Napisati M-fajl tablicaCheck.m sa funkcijom t = tablicaCheck() 
% koja vrsi proveru da li je niz X zadat u strogo rastucem poretku
% i da li je niz Y monoton. Ukoliko su oba uslova ispunjena funkcija 
% vraca vrednost 1, u suprotnom vraca vrednost 0. Ukoliko neki od uslova
% nije ispunjen funkcija ispisuje odgovarajucu poruku.
function t = tablicaCheck()

tablica;

HX = diff(X);
tx = all(HX > 0);

HY = diff(Y);
ty = all(HY >= 0) || all(HY <= 0);

t = tx && ty;