-- 1. Izdvojiti podatke o studentu koji je predmet, koji u nazivu na 4. i 5.
--    poziciji sadrži nisku 'gr' i koji ima izmeðu 5 i 9 bodova, polagao dva 
--    puta u roku od 20 dana. Izdvojiti naziv predmeta, indeks studenta koji 
--    je polagao predmet i broj dana izmeðu ispita. Kolonu sa brojem dana
--    izmeðu ispita nazvati 'Broj dana'. 
select p.naziv, i1.indeks,
	   i2.datum_ispita - i1.datum_ispita "Broj dana"
from ispit i1 join ispit i2
		on i1.indeks = i2.indeks
		and i1.datum_ispita < i2.datum_ispita
		and i1.datum_ispita + 20 days >= i2.datum_ispita
		and i1.id_predmeta = i2.id_predmeta
	join predmet p
		on p.id_predmeta = i1.id_predmeta
where p.naziv like '___gr%'
	and p.bodovi between 5 and 9;

-- 2. Izdvojiti predmet koji je polagan u samo jednom ispitnom 
--    roku. Izdvojiti naziv ispitnog roka, naziv predmeta, indeks,
--    ime i prezime studenta koji je polagao taj predmet u tom 
--    ispitnom roku.
select ir.naziv, p.naziv, 
	   d.indeks, d.ime, d.prezime
from dosije d join ispit i1
		on d.indeks = i1.indeks
	join predmet p
		on p.id_predmeta = i1.id_predmeta
	join ispitni_rok ir
		on ir.godina_roka = i1.godina_roka
		and ir.oznaka_roka = i1.oznaka_roka
where not exists (select *
				  from ispit i2
				  where i2.id_predmeta = i1.id_predmeta
				  		and (i2.oznaka_roka <> i1.oznaka_roka
				  		or i2.godina_roka <> i1.godina_roka));

-- 3. Studentima koji su položili neki ispit, izdvojti pored imena
--    i prezimena, naziv predmeta koji su položili iz prvog pokušaja.
select ime, prezime, p.naziv
from dosije d join ispit i
		on i.indeks = d.indeks
		and ocena > 5
	join predmet p
		on p.id_predmeta = i.id_predmeta
where not exists (select *
				  from ispit i2
				  where i2.id_predmeta = i.id_predmeta
				  	  and i2.indeks = d.indeks
				 	  and i2.datum_ispita < i.datum_ispita);

-- 4. Za najmlaðeg upisanog studenta na fakultet izdvojiti nazive
--    predmeta koje je položio. Ukoliko student nije položio nijedan
--    ispit umesto naziva predmeta ispisati nisku koja sadrži karakter
--    * onoliko puta koliko ima karaktera u prezimenu studenta.
select coalesce(p.naziv, repeat('*', length(prezime)))
from dosije d left join ispit i
		on d.indeks = i.indeks
		and ocena > 5
	left join predmet p
		on p.id_predmeta = i.id_predmeta
where datum_upisa - datum_rodjenja <= all (select datum_upisa - datum_rodjenja
							  				from dosije 
							  				where datum_upisa - datum_rodjenja is not null);

-- 5. Izdvojiti podatke o parovima studenata koji su fakultet upisali
--    2010, 2014. ili 2015. godine i koji su roðeni u istom mestu koje 
--    u svom nazivu sadrži podnisku 'evo' poèevši od 6. pozicije. 
--    Izdvojiti indekse studenata i mesto roðenja. 
select d1.indeks, d2.indeks, d1.mesto_rodjenja
from dosije d1 cross join dosije d2
where d1.indeks < d2.indeks
	and d1.mesto_rodjenja = d2.mesto_rodjenja
	and d1.mesto_rodjenja like '_____evo%'
	and d1.indeks/10000 in (2010, 2014, 2015)
	and d2.indeks/10000 in (2010, 2014, 2015);

-- 6. Za svaki predmet izdvojiti naziv predmeta i 
--    indeks najboljeg studenta sa tog predmeta.
select naziv, indeks
from predmet p left join ispit i
	on p.id_predmeta = i.id_predmeta
where i.ocena >= all (select ocena
					  from ispit i2
					  where i2.id_predmeta = p.id_predmeta);
					  
-- 7. Izdvojiti podatke o ispitima za koje važi da je broj dobijenih 
--    bodova na ispitu 6 puta veæi od broja bodova koje nosi predmet 
--    koji je polagan na ispitu. Izdvojiti indeks, ime i prezime studenta
--    koji je polagao ispit, naziv polaganog predmeta, bodove polaganog 
--    predmeta, naziv ispitnog roka u kome je polagan ispit i dobijenu ocenu.
select d.indeks, ime, prezime, p.naziv, p.bodovi,
	ir.naziv, ocena
from ispit i join predmet p
		on i.id_predmeta = p.id_predmeta
		and i.bodovi > 6*p.bodovi
	join dosije d
		on i.indeks = d.indeks
	join ispitni_rok ir
		on ir.godina_roka = i.godina_roka
		and ir.oznaka_roka = i.oznaka_roka;