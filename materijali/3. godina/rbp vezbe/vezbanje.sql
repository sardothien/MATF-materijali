--------- PRVI CAS -------------

--select *
--from predmet

--select *
--from dosije
--where mesto_rodjenja = 'Beograd'

--select distinct mesto_rodjenja
--from dosije

--select naziv
--from predmet
--where bodovi > 6

--select sifra, naziv
--from predmet
--where bodovi between 8 and 15

--select *
--from ispit
--where bodovi in (81, 76, 59)

--select *
--from ispit
--where bodovi not in (81, 76, 59)

--select naziv, bodovi*2000
--from predmet

--select naziv, 'Cena u dinarima', bodovi*2000 "Cena"
--from predmet

--select *
--from dosije
--where mesto_rodjenja like '%o%'

--select *
--from dosije 
--where mesto_rodjenja like '_o%'

--select *
--from dosije
--where mesto_rodjenja like '%e'

--select *
--from dosije
--where mesto_rodjenja like 'N%d'

--select *
--from predmet
--order by bodovi, naziv desc

--select ime, prezime, datum_rodjenja
--from dosije
--where datum_rodjenja between '4.2.1995' and '10.10.1995'
--order by prezime

--select naziv
--from ispitni_rok
--where godina_roka between 2010 and 2015
--	and naziv like '%p%'
--order by naziv desc

--------- DRUGI CAS -------------

--select *
--from ispit
--where datum_ispita is null

--select *
--from dosije, ispit

--select dosije.indeks, ime, prezime, id_predmeta, ocena
--from dosije, ispit
--where datum_ispita = '28.1.2015' and dosije.indeks = ispit.indeks

--select dosije.indeks, ime, prezime, naziv, ocena
--from dosije, ispit, predmet
--where dosije.indeks = ispit.indeks and 
--	ispit.id_predmeta = predmet.id_predmeta
--	and ispit.ocena > 5

--select d.*
--from dosije d join ispit i
--		on d.indeks = i.indeks
--		and prezime like '___a%c'
--		and ocena in (6,8,10)
--	join predmet p
--		on i.id_predmeta = p.id_predmeta
--		and sifra between 'M105' and 'P103'

--select p1.sifra, p1.naziv, p2.sifra, p2.naziv
--from predmet p1, predmet p2
--where p1.bodovi = p2.bodovi 
--	and p1.id_predmeta < p2.id_predmeta

--select naziv, godina_roka, oznaka_roka
--from predmet left join ispit 
-- 	on ispit.id_predmeta = predmet.id_predmeta
--order by naziv

--select distinct naziv, ocena
--from ispitni_rok ir left join ispit i
--	on ir.godina_roka = i.godina_roka
--	and i.oznaka_roka = ir.oznaka_roka
--order by naziv 

--select d.indeks, datum_rodjenja, oznaka_roka, godina_roka
--from dosije d full join ispit i
--	on datum_rodjenja = datum_ispita

--------- TRECI CAS -------------

--select d.indeks, ime, prezime, i.bodovi, naziv
--from dosije d left join ispit i
--		on d.indeks=i.indeks
--		and ocena = 9
--	left join predmet p
--		on i.id_predmeta = p.id_predmeta
--where mesto_rodjenja = 'Beograd'

--select naziv
--from predmet p join ispit i
--	on p.id_predmeta = i.id_predmeta
--where i.indeks = 20140022

--select distinct indeks
--from ispit
--where ocena > 5 and id_predmeta not in (
--	select id_predmeta
--	from ispit
--	where ocena > 5 and ispit.indeks = 20140022)

--select naziv
--from predmet
--where exists (select *
--			 from ispit
--			 where ocena > 5 and indeks = 20140022
--			 and predmet.id_predmeta = ispit.id_predmeta)

--select naziv
--from predmet
--where not exists (select *
--				 from dosije
--				 where not exists (select *
--				 					from ispit
--				 					where ispit.indeks = dosije.indeks
--				 					and ispit.id_predmeta = predmet.id_predmeta))

--select ir.naziv
--from ispitni_rok ir
--where not exists (select *
--				 from dosije d
--				 where not exists (select *
--				 					from ispit i
--				 					where d.indeks = i.indeks
--				 					and i.godina_roka = ir.godina_roka
--				 					and i.oznaka_roka = ir.oznaka_roka))

--select p.naziv
--from predmet p
--where not exists(select *
--				from dosije d
--				where mesto_rodjenja = 'Beograd' and not exists(select *
--																from ispit i
--																where i.indeks = d.indeks
--																and i.id_predmeta = p.id_predmeta))

--select d.*
--from dosije d
--where not exists (select *
--				  from predmet p
--				  where naziv like 'Ge%' and not exists (select *
--				  										 from ispit i
--				  										 where i.indeks = d.indeks
--				  										 and p.id_predmeta = i.id_predmeta))

--select p1.*
--from predmet p1
--where not exists (select *
--				 from predmet p2
--				 where p2.bodovi > p1.bodovi)

--select p1.*
--from predmet p1
--where bodovi >= all (select bodovi
--					 from predmet)

--select *
--from dosije
--where datum_rodjenja > some (select datum_rodjenja
--							from dosije
--							where datum_rodjenja is not null)

--------- CETVRTI CAS -------------

--select indeks
--from dosije
--where mesto_rodjenja = 'Beograd'
--
--union all
--
--select indeks
--from ispit
--where ocena = 10
--order by indeks desc

--select indeks
--from dosije
--where mesto_rodjenja = 'Beograd'
--
--intersect all
--
--select indeks
--from ispit
--where ocena = 10
--order by indeks desc

--select indeks
--from dosije
--where mesto_rodjenja = 'Beograd'
--
--except all
--
--select indeks
--from ispit
--where ocena = 10
--order by indeks desc

--select indeks, id_predmeta, ocena,
--	case ocena
--		when 10 then 'deset'
--		when 9 then 'devet'
--		when 8 then 'osam'
--		when 7 then 'sedam'
--		when 6 then 'sest'
--		else 'nepolozeno'
--	end ocena_slovima	
--from ispit

--select naziv, 
--	case
--		when bodovi > 7 then 'I'
--		when bodovi between 5 and 7 then 'II'
--		else 'III' 
--	end kategorija
--from predmet

--select current time
--from sysibm.sysdummy1;

--select current user
--from sysibm.sysdummy1

--select dayname(date('4.11.2015'))
--from sysibm.sysdummy1;

--select dayofyear(current date),
--	   dayofweek(current date),
--	   week(current date),
--	   dayname(current date),
--	   monthname(current date)
--from sysibm.sysdummy1;

--select second(current time)
--from sysibm.sysdummy1

--values date('11.11.2008') - date('6.8.2005')

--values current date + 12 year + 5 month + 25 day

--select *
--from ispit
--where datum_ispita > '28.1.2015'

--select *
--from ispit
--where current date - datum_ispita < 800

--select indeks, naziv, ocena,
--	   year(current date - datum_ispita) godina,
--	   month(current date - datum_ispita) meseci,
--	   day(current date - datum_ispita) dani,
--	   days(current date) - days(datum_ispita) "ukupan broj dana"
--from ispit i, predmet p
--where i.id_predmeta = p.id_predmeta
--	and current date - datum_ispita < 50000

--select indeks, ime || ' ' || prezime "Ime i prezime", 
--		case mesto_rodjenja
--			when 'Beograd' then 'Bg'
--			else mesto_rodjenja
--		end,
--		substr(ime, 1, 1) || substr(prezime, 1, 1) "Inicijali"
--from dosije

--select indeks, ime, prezime, coalesce(mesto_rodjenja, 'Nepoznato')
--from dosije

--values char(current date, ISO)
--values char(current date, USA)
--values char(current date, EUR)

--select dec(bodovi*1.2,7,2)
--from predmet

--select ceil(dec(bodovi*1.2,5,2))
--from predmet
--where ceil(bodovi*1.2) > 8

--select substr(i1.indeks, 5) || '/' || substr(i1.indeks, 1, 4)
--from ispit i1
--where ocena = 10 and not exists (select *
--								 from ispit i2
--								 where i1.indeks <> i2.indeks
--								 and i2.ocena = 10
--								 and i1.id_predmeta = i2.id_predmeta)

--select naziv, coalesce(dayname(datum_ispita), 'nije bilo ispita ili je nepoznat datum')
--from ispitni_rok ir left join ispit i
--		on ir.godina_roka = i.godina_roka
--		and ir.oznaka_roka = i.oznaka_roka
--where i.godina_roka between 2000 and 2015

-- Domaci - 1. zadatak
--select ime, prezime
--from dosije d1
--where exists (select *
--			  from dosije d2
--			  where d1.indeks <> d2.indeks
--			  and d1.mesto_rodjenja = d2.mesto_rodjenja
--			  and year(d2.datum_rodjenja) - year(d1.datum_rodjenja) = 1 );
			  
-- Domaci - 2. zadatak
--select ir.naziv
--from ispitni_rok ir
--where not exists (select *
--				  from dosije d
--				  where exists (select *
--				  					from ispit i
--				  					where i.indeks = d.indeks
--				  					and i.godina_roka = ir.godina_roka
--				  					and i.oznaka_roka = ir.oznaka_roka
--				  					and ocena = 10))


---------- Primer kolokvijuma -------------------
-- 1. 
--select distinct ir.naziv
--from ispitni_rok ir join ispit i
--		on i.godina_roka = ir.godina_roka
--		and i.oznaka_roka = ir.oznaka_roka
--	join predmet p
--		on i.id_predmeta = p.id_predmeta
--where ocena > 5 and not exists (select *
--							from ispit
--							where id_predmeta = p.id_predmeta
--							and p.bodovi = 8)

-- 2. 
--select p.naziv, case
--	when not exists (select * from dosije where indeks = i.indeks and ocena > 5) then 'Nema studenata'
--	else (ime || ' ' || prezime)
--	end "Student"
--from predmet p left join ispit i
--		on i.id_predmeta = p.id_predmeta
--	left join dosije d
--		on d.indeks = i.indeks
--where ocena > 5
--	and current_date - datum_ispita < 50300
--order by naziv
						