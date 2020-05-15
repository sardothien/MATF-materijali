/* Ako je data baza znanja:
    * automobil(SifraAutomobila, NazivAutomobila)
    * vlasnik(ImeVlasnika, SifraAutomobila)
    * brziSifra(SX, SY) - automobil sifre SX je brzi 
        od automobila sifre SY
   Napisati predikate: */

automobil(a1, audi).
automobil(h1, honda).
automobil(m1, mercedes).
automobil(m2, mercedes).
automobil(c1, citroen).
automobil(c2, citroen).

vlasnik(milan, h1).
vlasnik(maja, m1).
vlasnik(nemanja, m2).
vlasnik(aleksandar, a1).
vlasnik(andjela, c1).
vlasnik(petar, c2).

brziSifra(a1, c1).
brziSifra(m1, c1).
brziSifra(m2, h1).
brziSifra(a1,c2).

% (a) brziNaziv(X, Y) - automobil naziva X je brzi od automobila naziva Y 
brziNaziv(X, Y) :- automobil(SX, X), automobil(SY, Y), brziSifra(SX, SY).

% (b) imaAutomobil(X) - X je vlasnik nekog automobila
imaAutomobil(X) :- vlasnik(X, _).

% (c) imaBrzi(X, Y) - X je vlasnik brzeg automobila od onog ciji je vlasnik Y
imaBrzi(X, Y) :- vlasnik(X, SX), vlasnik(Y, SY), brziSifra(SX, SY).