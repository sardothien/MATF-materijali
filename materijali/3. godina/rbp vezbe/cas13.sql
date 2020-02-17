-- 1. Napisati na SQL-u upit koji izdvaja studente koji su sve do sada upisivane 
--	  obavezne predmete i polozili i to sa ocenom bar 8, a da student nijedan ispit 
--    nije pao u poslednjih 6 godina. Za studente izdvojiti ime, srednje slovo i 
--    prezime u formatu ime srednje_slovo. prezime. Srednje slovo se doija na osnovu 
--    imena oca ako postoji u bazi, ukoliko za studenta nije navedeno ime oca koristi
--    se ime majke, a ukoliko nije navedeno nijedno od ta dva ne izdvaja se srednje
--    slovo, niti prateca tacka. Ukoliko su imena roditelja u bazi sastavljena samo 
--    od belina, smatrati ih nenavedenim. 
select trim(ime) || ' ' || (case
		when ime_oca is not null and length(rtrim(ime_oca)) <> 0
			then substr(ime_oca, 1, 1) || '. '
		when ime_majke is not null and length(rtrim(ime_majke)) <> 0
			then substr(ime_majke, 1, 1)
		else ''
		end) || trim(prezime) ime_i_prezime
from dosije  d
where not exists (select *
				  from upisan_kurs uk join obavezan_predmet op
				  		on uk.id_predmeta = op.id_predmeta
				  where uk.indeks = d.indeks
				  	and op.id_smera = d.id_smera
				  	and not exists (select *
				  					from ispit
				  					where indeks = d.indeks
				  						and ocena >= 8
				  						and status_prijave = 'o'
				  						and id_predmeta = uk.id_predmeta))
	and not exists (select *
					from ispit
					where indeks = d.indeks
						and ocena = 5
						and status_prijave = 'o'
						and coalesce(datum_usmenog, datum_pismenog) > current date - 6 years);
						
-- 2. Napisati na SQL-u upit koji pravi statistiku prema imenima studenata: uz ime
--    studenta izdvaja prosecan broj upisivanih godina studenata sa tim imenom izrazen 
--    na 3 decimale, kao i broj proteklih dana od prvog uspesnog polaganja nekog
--    studenta sa tim imenom. Rezultat urediti prema imenu leksikografski.
with godine as
(
 select ime, count god
 from upis_godine ug join dosije d
 	on ug.indeks = d.indeks
 group by d.indeks, ime
),
prosek_godina as
(
 select ime, decimal(avg(god*1.0), 5, 3) pr
 from godine
 group by ime
),
datumi as 
(
 select ime, min(coalesce(datum_usmenog, datum_pismenog)) mindat
 from ispit i join dosije d
 	on i.indeks = d.indeks
 where ocena > 5
 	and status_prijave = 'o'
 group by ime
)
select pg.ime, pg.pr, days(current date) - days(d.mindat) broj_dana
from prosek_godina pg left join datumi d
	on pg.ime = d.ime
order by ime;
						
-- 3. Za svaku pojedinacnu stavku zadatka napisati po jednu SQL naredbu kojom se:
-- a) pravi tabela upisani_kursevi_2016 koja ima isti skup kolona kao tabela 
--    upisan_kurs. Ne kreirati nabrajanjem kolona.
-- b) dodaje prethodno napravljenoj tabeli primarni kljuc koji cine kolone indeks,
--    id_predmeta, godina, semestar i strani kljucevi na tabele dosije i predmet
-- c) studentima upisanim na fakultet posle 2011. godine i koji su upisivali, ali 
--    nisu polozili predmete ciji nazivi pocinju sa Uvod, upisuju kursevi iz tih 
--    predmeta u 2016. skolskoj godini u 2. semestru unoseci ih u tabelu 
--    upisani_kursevi_2016
-- d) studentima osnovnih studija svi upisani kursevi u drugom semestru prebacuju
--    u prvi semestar, a ostali se ne diraju. Koristeci cinjenicu da su osnovne 
--    studije na stepenu I.
-- e) uklanja tabelu upisani_kursevi_2016	
-- (a)		
create table upisani_kursevi_2016 like upisan_kurs;					
						
-- (b)
alter table upisani_kursevi_2016
	add primary key (indeks, id_predmeta, godina, semestar)
	add foreign key fk_dos (indeks) references dosije
	add foreign key fk_pred (id_predmeta) references predmet;
					
-- (c)
insert into upisani_kursevi_2016
select distinct d.indeks, p.id_predmeta, 2016, 2
from dosije d join upisan_kurs uk
		on d.indeks = uk.indeks
	join predmet p
		on p.id_predmeta = uk.id_predmeta 
where year(d.datum_upisa) >= 2011
	and p.naziv like 'Uvod%'
	and not exists (select *
					from ispit
					where ocena > 5
						and status_prijave = 'o'
						and indeks = d.indeks
						and id_predmeta = p.id_predmeta);

-- (d)
update upisani_kursevi_2016
set semestar = 1
where semestar = 2 and indeks in (select indeks
								  from dosije d join smer s
								  	 	on s.id_smera = d.id_smera
								  	join nivo_kvalifikacije nk
								  		on nk.id_nivoa = s.id_nivoa
								  where nk.stepen = 'I');

-- (e)
drop table upisani_kursevi_2016;