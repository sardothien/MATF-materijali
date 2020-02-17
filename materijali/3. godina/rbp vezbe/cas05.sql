-- 1. Za svakog studenta iz Beogradaa izdvojiti podatke o ispitima koje je polozio
--	  sa ocenom 9. Izdvojiti indeks, ime i prezime studenta, broj osvojenih bodova
--    na ispitu i naziv predmeta.
select dosije.indeks, ime, prezime, ispit.bodovi, predmet.naziv
from dosije left join ispit on dosije.indeks = ispit.indeks 
		and ispit.ocena = 9
	 left join predmet on ispit.id_predmeta = predmet.id_predmeta
where mesto_rodjenja = 'Beograd';
-- kod spoljasnjeg spajanja paziti sta ide gore kao uslov spajanja, a sta u where

-- 2. Izdvojiti nazive predmeta koje je polagao student sa indeksom 22/2014.
select naziv
from predmet join ispit
	on predmet.id_predmeta = ispit.id_predmeta
where indeks = 20140022;

-- where izraz in (select kolona from ...)

-- drugi nacin - koristimo podupit:
select naziv
from predmet
where id_predmeta in (select id_predmeta 
					  from ispit 
					  where indeks = 20140022);

-- treci nacin:
select naziv
from predmet
where 20140022 in (select indeks 
					from ispit 
					where predmet.id_predmeta = ispit.id_predmeta);

-- 3. Izdvojiti indekse studenata koji su polozili bar jedan predmet koji nije
--	  polozio student sa indeksom 22/2014.
-- treba not in jer student moze jednom da padne, pa posle polozi
select distinct indeks
from ispit
where ocena > 5 and id_predmeta not in (select id_predmeta
				 						from ispit
				 						where ocena > 5
				 							and ispit.indeks = 20140022);

-- WHERE exists (podupit) - vraca tacno ako je rezultat podupita ne prazan
				 							
-- 4. Izdvojiti nazive predmeta koje je polozio student sa indeksom 22/2014.
select naziv
from predmet
where exists (select *
			  from ispit
			  where ispit.id_predmeta = predmet.id_predmeta
			    and ocena > 5 and indeks = 20140022);

-- 5. Pronaci nazive predmeta koje su polagali svi studenti.

-- px.naziv
-- where not exists dx (not exists ix (uslovi spajanja))
select naziv
from predmet p
where not exists (select *
				  from dosije d
				  where not exists (select *
				  					from ispit i
				  					where i.indeks = d.indeks
				  						and p.id_predmeta = i.id_predmeta));

-- 6. Pronaci nazive ispitnih rokova u kojima su polagali svi studenti.
select naziv
from ispitni_rok ir
where not exists (select *
				  from dosije d
				  where not exists (select *
				                    from ispit i
				                    where d.indeks = i.indeks
				                       and i.oznaka_roka = ir.oznaka_roka
				                       and i.godina_roka = ir.godina_roka));
				                    
-- 7. Izdvojiti nazive predmeta koje su polagali svi studenti iz Beograda.
select naziv
from predmet p
where not exists (select *
				  from dosije d
				  where mesto_rodjenja = 'Beograd' and not exists (
				  					select *
				  					from ispit i
				  					where i.id_predmeta = p.id_predmeta
				  					   and i.indeks = d.indeks));
				  					   
-- u relacionom racunu:
-- forall x (if uslov1 then uslov2)
-- not exists x (not (if uslov1 then uslov2))
-- not exists x (not (not uslov1 or uslov2))
-- not exists x (uslov1 and not uslov2)
-- p => q = not p or q

-- 8. Izdvojiti podatke o studentima koji su polagali sve predmete ciji nazivi
--    pocinju na Ge.
select d.*
from dosije d
where not exists (select *
			  from predmet p
			  where naziv like 'Ge%' and not exists (
					  select *
					  from ispit i
					  where i.id_predmeta = p.id_predmeta 
					  and i.indeks = d.indeks));

-- izraz > (select ... from ...)
-- izraza relacije kvantifikator podupit

-- 9.  Pronaci predmete sa najvecim bojem bodova.
select *
from predmet
where bodovi >= all (select bodovi
					from predmet);
					
-- 10. Izdvojiti sve studente osim najstarijih.
select *
from dosije
where not datum_rodjenja <= all (select datum_rodjenja
							 from dosije
							 where datum_rodjenja is not null);
		
-- drugi nacin:					 
select *
from dosije
where datum_rodjenja > some (select datum_rodjenja
							 from dosije
							 where datum_rodjenja is not null);