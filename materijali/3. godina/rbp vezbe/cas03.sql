-- 1. Izdvojiti podatke o svim predmetima.
select *
from predmet;

-- 2. Izdvojiti podatke o svim studentima rodjenim u Beogradu.
select *
from dosije
where mesto_rodjenja = 'Beograd'; 

-- 3. Izdvojiti mesta u kojima su rodjeni studenti.
select distinct mesto_rodjenja
from dosije;

-- 4. Izdvojiti nazive predmeta koji imaju vise od 6 bodova.
select naziv
from predmet
where bodovi > 6;

-- 5. Izdvojiti sifre i nazive predmeta koji imaju izmedju 
--    8 i 15 bodova.
select sifra, naziv
from predmet
where bodovi between 8 and 15;

-- 6. Izdvojiti podatke o ispitima na kojima student ima 
--	  81, 76 ili 59 bodova.
select *
from ispit
where bodovi in (81, 76, 59);

-- 7. Izdvojiti podatke o ispitima na kojima student nema
--    81, 76 ili 59 bodova.
select *
from ispit
where bodovi not in (81, 76, 59);

-- 8. Izdvojiti nazive predmeta i njihovu cenu za samofinansirajuce
--    studente izrazenu u dinarima. Jedan bod kosta 2000din.
select naziv, bodovi*2000 as "Cena"
from predmet;

-- 9. Izdvojiti nazive predmeta i njihovu cenu za samofinansirajuce
--    studente izrazenu u dinarima. Jedan bod kosta 2000din. Izmedju
-- 	  kolone Naziv i kolone Cena dodati kolonu u kojoj ce za svaku
--	  vrstu pisati Cena u dinarima.
select naziv, 'Cena u dinarima' "RSD", bodovi*2000 as Cena
from predmet;

-- 10. Prikazati podatke o studentima koji su rodjeni u mestu ciji naziv
--  	a) sadrzi malo slovo o
-- 		b) sadrzi o kao drugo slovo
-- 		c) se zavrsava sa e
-- 		d) pocinje sa N, a zavrsava sa d
-- a)
select *
from dosije
where mesto_rodjenja like '%o%';
-- b)
select *
from dosije
where mesto_rodjenja like '_o%';
-- c)
select *
from dosije
where mesto_rodjenja like '%e';
-- d)
select *
from dosije
where mesto_rodjenja like 'N%d';

-- 11. Prikazati podatke o predmetima. Rezultat urediti po bodovima
-- 		a) rastuce
-- 		b) opadajuce
-- 		c) rastuce i po nazivu opadajuce
-- a)
select *
from predmet
order by bodovi;
-- b)
select *
from predmet
order by bodovi desc;
-- c)
select *
from predmet
order by bodovi, naziv desc;

-- 12. Prikazati ime, prezime i datum rodjenja studenata koji su rodjeni
-- 	   izmedju 4.2.1995 i 10.10.1995 i urediti rezultat prema prezimenu.
select ime, prezime, datum_rodjenja
from dosije
where datum_rodjenja between '4.2.1995' and '10.10.1995'
order by prezime;

-- 13. Prikazati naziv ispitnog roka koji je odrzan izmedju 2010. i 2015.
-- 	   godine i koji u oznaci sadrzi slovo p. Urediti prema nazivu opadajuce.
select naziv
from ispitni_rok
where godina_roka between 2010 and 2015 
	and oznaka_roka like '%p%'
order by naziv desc;