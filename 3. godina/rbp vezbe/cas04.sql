-- 1. Prikazati podatke o ispitima ciji je datum nepoznat.
select *
from ispit
where datum_ispita is null;

-- 2. Prikazati podatke o studentima i ispitima
select *
from dosije, ispit
 ili
from dosije cross join ispit;

-- 3. Prikazati podatke o studentima i njihovim ispitima koji su odrzani
--    28.1.2015. Izdvojiti indeks, ime, prezime, id predmeta i ocenu.
select dosije.indeks, ime, prezime, id_predmeta, ocena
from dosije, ispit
where dosije.indeks = ispit.indeks and datum_ispita = '28.1.2015';

-- 4. Za svakog studenta izdvojiti predmete koje je polozio. Prikazati ime,
-- 	  prezime, indeks, naziv predmeta i ocenu.
select ime, prezime, dosije.indeks, naziv, ocena
from dosije, ispit, predmet
where dosije.indeks = ispit.indeks 
	  and ispit.id_predmeta = predmet.id_predmeta
	  and ispit.ocena > 5;
	 
-- drugi nacin:
select ime, prezime, dosije.indeks, naziv
from dosije join ispit on dosije.indeks = ispit.indeks
	 join predmet on ispit.id_predmeta = predmet.id_predmeta
where ispit.ocena > 5;
	  
-- 4a.
select ime, prezime, dosije.indeks, predmet.naziv as "Predmet",
	  ocena, ispitni_rok.naziv as "Ispitni rok"		
from dosije, ispit, predmet, ispitni_rok
where dosije.indeks = ispit.indeks 
	  and ispit.id_predmeta = predmet.id_predmeta
	  and ispit.ocena > 5
	  and ispit.godina_roka = ispitni_rok.godina_roka
	  and ispit.oznaka_roka = ispitni_rok.oznaka_roka;

-- 5. Izdvojiti podatke o studentima cije prezime sadrzi malo slovo a 
--    na 4. poziciji i zavrsava se na malo slovo c i koji ima ocenu 
--    6, 8 ili 10 iz predmeta cija je sifra u intervalu [M105, P103].
select dosije.*
from dosije join ispit on dosije.indeks = ispit.indeks
		and prezime like '___a%c' 
	  	and ocena in (6, 8, 10)
	 join predmet on ispit.id_predmeta = predmet.id_predmeta
		and sifra between 'M105' and 'P103';

-- drugi nacin - Dekartov proizvod:
select dosije.*
from dosije cross join ispit cross join predmet
where dosije.indeks = ispit.indeks
	  and ispit.id_predmeta = predmet.id_predmeta
	  and prezime like '___a%c' 
      and ocena in (6, 8, 10)
      and sifra between 'M105' and 'P103';

-- 6. Izdvojiti parove predmeta koji imaju isti broj bodova. Izdvojiti sifre
-- 	  predmeta i broj bodova.
select p1.sifra "P1 sifra", predmet.sifra "P2 sifra", p1.bodovi
from predmet as p1, predmet
where p1.bodovi = predmet.bodovi
	  and p1.id_predmeta < predmet.id_predmeta;

-- 7. Za svaki predmet izdvojiti naziv, godinu i oznaku roka u kojima je taj 
--    predmet polagan. Rezultat urediti prema nazivu predmeta.
select naziv, godina_roka, oznaka_roka
from ispit right join predmet on ispit.id_predmeta = predmet.id_predmeta
order by naziv;

-- 8. Za svaki ispitni rok izdvojiti naziv ispitnog roka i ocene koje su
--    dobijene u tom roku. Rezultat urediti prema nazivu ispitnog roka.
select distinct naziv, ocena
from ispit right join ispitni_rok 
	 on ispit.godina_roka = ispitni_rok.godina_roka
	 and ispit.oznaka_roka = ispitni_rok.oznaka_roka
order by naziv;

-- 9. Izdvojiti parove student - ispit takve da je student rodjen kada je odrzan
--    ispit. Izdvojiti indeks, datum rodjenja, oznaku i godinu roka. Prikazati  i 
--    studente i ispite koji nemaju odgovarajuceg para i za njih umesto podataka o
--    paru ispisati null vrednosti.
select dosije.indeks, datum_rodjenja, oznaka_roka, godina_roka
from dosije full join ispit 
	on datum_rodjenja = datum_ispita;