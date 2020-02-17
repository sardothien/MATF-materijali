-- upit1 op upit2 
-- union (all), intersect (all), except (all)

-- 1. Izdvojiti indekse studenata koji su 
--   a) roðeni u Beogradu ili imaju ocenu 10. Rezultat urediti u opadajuæem poretku. 
--   b) roðeni u Beogradu i imaju ocenu 10. Rezultat urediti u opadajuæem poretku. 
--   c) roðeni u Beogradu i nemaju ocenu 10. Rezultat urediti u opadajuæem poretku. 

-- a)
select indeks
from dosije
where mesto_rodjenja='Beograd'

union all

select indeks
from ispit
where ocena=10
order by indeks desc;

-- b)
select indeks
from dosije
where mesto_rodjenja='Beograd'

intersect all

select indeks
from ispit
where ocena=10
order by indeks desc;

-- c)
select indeks
from dosije
where mesto_rodjenja='Beograd'

except all

select indeks
from ispit
where ocena=10
order by indeks desc;

-- 2. Za svaki ispit izdvojiti indeks, id_predmeta i dobijenu ocenu. Vrednost ocene
--    ispisati i slovima. Ako je predmet nepoložen umesto ocene ispisati nepoložen. 

-- Prvi oblik
select indeks, id_predmeta, ocena,
	case ocena
	 	when 10 then 'deset'
	 	when 9 then 'devet'
	 	when 8 then 'osam'
	 	when 7 then 'sedam'
	 	when 6 then 'sest'
	 	else 'nepolozen'  
	 end ocena_slovima
from ispit;

-- Drugi oblik
select indeks, id_predmeta, ocena,
	case 
	 	when ocena=10 then 'deset'
	 	when ocena=9 then 'devet'
	 	when ocena=8 then 'osam'
	 	when ocena=7 then 'sedam'
	 	when ocena=6 then 'sest'
	 	else 'nepolozen'  
	 end ocena_slovima
from ispit;

-- 3. Klasifikovati predmete prema broju bodova na sledeæi naèin: 
-- ako predmet ima više od 7 bodova tada pripada I kategoriji 
-- ako je broj bodova predmeta u intervalu [5,7] tada pripada II kategoriji 
-- inaèe predmet pripada III kategoriji.
select naziv, 
	case
		when bodovi>7 then 'I kategorija'
		when bodovi between 5 and 7 then 'II kategorija'
		else 'III kategorija'
	end kategorija
from predmet;

-- Drugi nacin
select naziv, 
	case
		when bodovi>7 then 'I kategorija'
		when bodovi>=5 then 'II kategorija'
		else 'III kategorija'
	end kategorija
from predmet;

--values 'a', 'b', 'c'
--values ('a', 1), ('b', 2), ('c', 3)

-- 4. Ispisati trenutno vreme.
-- Prvi nacin
select current time
from sysibm.sysdummy1;

-- Drugi nacin
values current time;

-- 5. Ispisati trenutnog korisnika.
values user;
-- ili
select user
from sysibm.sysdummy1;

-- 6. Izraèunati koji je dan u nedelji (njegovo ime) bio 4.11.2015.
-- Prvi nacin
select dayname(current date)
from sysibm.sysdummy1;

-- Drugi nacin
values dayname(date('4.11.2019'));

-- 7. Za današnji datum izraèunati koji je dan u godini; u kojoj je nedelji u 
--    godini; koji je dan u nedelji; ime dana; ime meseca. 
values 
	(dayofyear(current date),
	week(current date),
	dayofweek(current date),
	dayname(current date), -- greska jer nije istog tipa kao prethodni (mora zagrade)
	monthname(current date));
	
-- 8. Izdvojiti sekunde iz trenutnog vremena.
values second(current time);

-- 9. Izraèunati koliko vremena je prošlo izmeðu 6.8.2005. i 11.11.2008. 
values date('11.11.2008') - date('6.8.2005');

-- 10. Izraèunati koji æe datum biti za 12 godina, 5 meseci i 25 dana.
values current date + 12 years + 5 months + 25 days;

-- 11. Izdvojiti ispite koji su održani posle 28. januara 2015. godine.
select *
from ispit
where datum_ispita > date('28.1.2015');
-- moze samo i niska, bez date

-- 12. Pronaæi ispite koji su održani u poslednjih 8 meseci.
select *
from ispit
where current_date - datum_ispita < 800;

-- 13. Za sve ispite koji su održani u poslednjih 5 godina izraèunati koliko 
--     je godina, meseci i dana prošlo od njihovog održavanja. Izdvojiti indeks, 
--     naziv predmeta, ocenu, broj godina, broj meseci i broj dana.
select indeks, naziv, ocena, 
	   year(current date - datum_ispita) godina,
	   month(current date - datum_ispita) meseci,
	   day(current date - datum_ispita) dani,
	   days(current date) - days(datum_ispita) "ukupan broj dana"
from ispit, predmet
where ispit.id_predmeta = predmet.id_predmeta
	and current_date - datum_ispita < 50000;
	
-- 14. Izdvojiti indeks, ime, prezime, mesto roðenja i inicijale studenata.
--     Ime i prezime napisati u jednoj koloni, a za studente roðene u Beogradu 
--     kao mesto roðenja ispisati Bg.
select indeks, ime || ' ' || prezime ime_prezime, 
	   replace(mesto_rodjenja, 'Beograd', 'Bg') mesto_rodjenja,
	   substr(ime, 1,1) || substr(prezime,1,1) inicijali
from dosije;

-- 15. Izdvojiti indeks, ime, prezime i mesto roðenja za svakog studenta. Ako je
--     mesto roðenja nepoznato, umesto NULL vrednosti ispisati Nepoznato. 

select indeks, ime, prezime,
	   coalesce(mesto_rodjenja, 'Nepoznato') mesto_rodjenja
from dosije;

-- 16. Prikazati trenutno vreme u ISO formatu, USA formatu, EUR formatu.
values (char(current date, EUR),
		char(current time, EUR)),
	   (char(current date, USA),
		char(current time, USA)),
	   (char(current date, ISO),
		char(current time, ISO));

values trunc(586.25589, 1);
values round(586.25589, 1);
values dec(round(586.25589, 2), 6, 2);

-- 17. Ako je predmetima potrebno uveæati broj bodova za 20% 
--     a) prikazati koliko æe svaki predmet imati bodova nakon uveæanja. 
--		  Uveæani broj bodova prikazati sa dve decimale. 
--	   b) prikazati koliko æe bodova imati predmeti koji nakon uveæanja 
--		  imaju više od 8 bodova. Uveæani broj bodova zaokružiti na veæu ili 
--		  jednaku celobrojnu vrednost.
-- a)
select predmet.*,
	   dec(bodovi*1.2, 5, 2) nakon_uvecanja
from predmet;

-- b)
select predmet.*,
	   ceil(bodovi*1.2) nakon_uvecanja
from predmet
where ceil(bodovi*1.2) > 8;

-- KRAJ ZA KOLOKVIJUM

-- 18. Pronaæi koji studenti su jedini dobili 10 iz nekog predmeta. Za studenta sa
--     brojem indeksa GGGGBBBB izdvojiti indeks u formatu BBBB/GGGG. 
select substr(indeks, 5) || '/' || substr(indeks, 1, 4)
from ispit i1
where ocena = 10
	  and not exists (select *
	  				  from ispit i2
	  				  where i2.ocena = 10 
	  				  		and i1.id_predmeta = i2.id_predmeta
	  				  		and i1.indeks <> i2.indeks);

-- 19. Za svaki ispitni rok koji je održan izmeðu 2000. i 2015. godine izdvojiti imena dana 
--     u kojima su polagani ispiti u tom roku. Izdvojiti naziv ispitnog roka i ime dana. Za 
--     ispitne rokove u kojima nije polagan nijedan ispit ili je datum polaganja nepoznat 
--     umesto dana ispisati 'nije bilo ispita ili je nepoznat datum'.
select naziv, coalesce(dayname(datum_ispita), 'nije bilo ispita ili je nepoznat datum')
from ispit i right join ispitni_rok ir
	on i.godina_roka = ir.godina_roka 
	and i.oznaka_roka = ir.oznaka_roka
where ir.godina_roka between 2000 and 2015;