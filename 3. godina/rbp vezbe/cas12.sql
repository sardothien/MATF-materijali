-- 1. Za sve studente èije ime poèinje na slovo P i roğeni su izmeğu februara 
--    i jula izdvojiti podatke o poloenim ispitima. Izdvojiti indeks, ime i 
--    prezime studenta, naziv predmeta, dobijenu ocenu i kategoriju poloenog 
--    predmeta. Poloeni predmet spada u kategoriju: 
--       obavezan, ako je obavezan predmet na smeru koji student studira 
-- 		 izborni, ako nije obavezan predmet na smeru koji student studira.
select d.indeks, ime, prezime, p.naziv, i.ocena, 
	case when p.id_predmeta in (select op.id_predmeta
							    from obavezan_predmet op
							    where op.id_smera = d.id_smera) 
		then 'obavezan'
		when p.id_predmeta is not null
		then 'izborni'
		else 'nema polozenih'
	end kategorija
from dosije d left join ispit i
		on i.indeks = d.indeks
		and ocena > 5
		and status_prijave = 'o'
	left join predmet p
		on p.id_predmeta = i.id_predmeta 
where ime like 'P%'
	and month(datum_rodjenja) between 2 and 7;
	
-- 2. Kreirati indeks tabele dosije po imenu i prezimenu u opadajucem 
--    redosledu. Zatim ga obrisati.
create index dosije_ime_prezime on dosije
(ime desc, prezime desc);

drop index dosije_ime_prezime;

-- 3. Napisati naredbu na SQL-u koja: 
-- a) pravi tabelu predmet_student koja èuva podatke koliko studenata
--    je poloilo koji predmet. Tabela ima kolone: id_predmeta (tipa integer)
--    i student (tipa smallint). 
-- b) unosi u tabelu predmet_student podatke o obaveznim predmetima na smeru 
--    Informatika na osnovnim akademskim studijama (moe se uzeti da je id_smera 201).
--    Za svaki predmet uneti podatak da ga je poloilo 5 studenata. 
-- c) aurira tabelu predmet_student, tako što predmetima o kojima postoji 
--    evidencija aurira broj studenata koji su ga poloili, a za predmete o kojima 
--    ne postoji evidencija unosi podatke.
-- (a)
create table predmet_student (
	id_predmeta 	integer		not null,
	student 		smallint
);

-- (b)
insert into predmet_student
select id_predmeta, 5
from obavezan_predmet
where id_smera = 201;

-- (c)
merge into predmet_student ps
using (
	select id_predmeta, count n
	from ispit 
	where ocena > 5
		and status_prijave = 'o'
	group by id_predmeta
) as t
on ps.id_predmeta = t.id_predmeta 
when matched then
	update
	set student = t.n
when not matched then
	insert
	values(t.id_predmeta, t.n);

-- 4. Napisati naredbu na SQL-u koja: 
-- a) pravi tabelu student_podaci sa kolonama: indeks (tipa integer), 
--    broj _predmeta (tipa smallint), prosek (tipa float) i dat_rodjenja (tipa date). 
-- b) u tabelu student_podaci unosi indeks, broj poloenih predmeta i prosek za 
--    studente koji imaju prosek iznad 8 i za studente koji su diplomirali. Za 
--    studente koji su diplomirali kao broj predmeta uneti vrednost 10, a kao prosek
--    vrednost 10. 
-- c) aurira tabelu student_podaci tako što studentima o kojima u tabeli postoje
--    podaci i koji su: 
--		diplomirali aurira datum roğenja 
--		trenutno na budetu aurira broj poloenih predmeta i prosek. 
-- Naredba podatke o studentima koji su se ispisali briše iz tabele, a unosi podatke
-- o studentima koji se nisu ispisali i o njima ne postoje podaci u tabeli 
-- student_podaci. Za studente o kojima nema podataka uneti indeks, broj poloenih 
-- predmeta i prosek.
-- (a)
create table student_podaci (
	indeks			integer,
	broj_predmeta 	smallint,
	prosek			float,
	dat_rodjenja	date
);

-- (b)
insert into student_podaci
select indeks, count, avg(ocena*1.0), null
from ispit i
where ocena > 5
	and status_prijave = 'o'
	and exists (select *
				from status s
				where s.indeks = i.indeks
					and s.status = 'diplomirao')
group by indeks
having avg(ocena*1.0) > 8

union

select indeks, 10, 10, null
from status s
where s.status = 'diplomirao';

-- (c)
merge into student_podaci sp
using (
	select d.indeks, d.datum_rodjenja, s.status, count brp,
		   avg(ocena*1.0) prosek
	from dosije d join status s
			on d.indeks = s.indeks
	  	left join ispit i
	  		on i.indeks = d.indeks
	  		and ocena > 5
	  		and status_prijave = 'o'
	where s.datum = (select max(datum)
					 from status s1
					 where s1.indeks = d.indeks)
	group by d.indeks, d.datum_rodjenja, s.status
) as t
on sp.indeks = t.indeks
when matched and t.status = 'diplomirao'
	then
		update
		set dat_rodjenja = t.datum_rodjenja
when matched and t.status = 'budzet'
	then
		update
		set (broj_predmeta, prosek) = (t.brp, t.prosek)
when matched and t.status = 'ispisan' 
	then
		delete
when not matched and t.status <> 'ispisan'
	then
		insert(indeks, broj_predmeta, prosek)
		values(t.indeks, t.brp, t.prosek);

-- 5. Napisati na SQL-u upit koji izraèunava statistiku o polaganju ispita u rokovima
--    odranim od 2005. do 2009. godine po predmetima. Izdvojiti naziv roka, naziv 
--    predmeta, broj studenata koji su prijavili ispit iz tog predmeta u tom roku, 
--    koliko studenata ga je poloilo, koji je procenat studenata koji ga je poloio
--    u odnosu na broj prijavljenih, koliko studenata je poništilo dobijenu ocenu, 
--    koji je to procenat u odnosu na broj studenata koji su ga prijavili i prolaznost 
--    rangirati prema procentu poloenosti (uzimajuæi u obzir i studente koji su 
--    poništili ispit) kao:
--			odlièna - ako je prolaznost veæa od 70% 
--			srednja - ako je prolaznost izmeğu 40% i 70% 
--			loša - ako je manja od 40% 
-- Rezultat ureditii prema rangu.
with prolaznost as
(
 select ir.naziv nazivr, p.id_predmeta, p.naziv nazivp, count(i.indeks) prijavilo,
 		sum(case 
 			   when status_prijave = 'o' and ocena > 5
 			   		then 1
 			   		else 0
 			   end) polozilo,
 		sum(case
 				when status_prijave = 'x' and ocena > 5
 					then 1
 					else 0
 				end) ponistilo
 from ispitni_rok ir left outer join ispit i
 		on i.godina_roka = ir.godina
 		and i.oznaka_roka = ir.oznaka
 	left outer join predmet p
 		on i.id_predmeta = p.id_predmeta
 where ir.godina between 2005 and 2009 
 group by ir.naziv, ir.godina, p.id_predmeta, p.naziv
)
select nazivr, nazivp, prijavilo, polozilo,
	   case when prijavilo > 0
	   		then polozilo*100.0 / prijavilo 
	   		else 0
	   	end "Procenat polozenih",
	   case when prijavilo > 0
	   		then ponistilo*100.0 / prijavilo 
	   		else 0
	   	end "Procenat ponistenih",
	   	case 
	   		when prijavilo > 0 and (polozilo+ponistilo)*100.0 / prijavilo > 80
	   			then 'odlicna'
	   		when prijavilo > 0 and (polozilo+ponistilo)*100.0 / prijavilo > 40
	   			then 'srednja' 
	   		else 'losa'
	   	end rang
from prolaznost
order by rang;

-- 6. Napisati naredbu SQL-a koja studentima osnovnih akademskih studija koji su 
--    upisali 2010/2011. školsku godinu aurira broj upisanih bodova na ukupan 
--    broj bodova upisanih kurseva, a broj overenih bodova na ukupan broj poloenih 
--    bodova u toj školskoj godini. Aurirati datum upisa na 20. septembar 2010, 
--    a datum overe na 25. septembar 2011.
update upis_godine ug
set upisano_bodova = (select coalesce(sum(p.bodovi), 0)
					  from upisan_kurs uk join predmet p
					  		on p.id_predmeta = uk.id_predmeta
					  where uk.indeks = ug.indeks
					  	and uk.godina = ug.godina),
	overeno_bodova = (select coalesce(sum(p.bodovi), 0)
					  from ispit i join predmet p
					  		on i.id_predmeta = p.id_predmeta
					  where i.indeks = ug.indeks
					  	and i.godina = ug.godina
					  	and ocena > 5
					  	and status_prijave = 'o'),
	datum_upisa = '20.9.2010',
	datum_overe = '25.9.2011'
where ug.godina = 2010
	and indeks in (select indeks
				   from dosije d join smer s
				   		on d.id_smera = s.id_smera
				   	  join nivo_kvalifikacije nk	
				   	  	on nk.id_nivoa = s.id_nivoa
				   where nk.stepen = 'I');

-- 7. Napisati upit na SQL-u koji za školsku 2006/2007. i svaki smer osnovnih
--    studija izraèunava koliki je procenat studenata koji su te godine upisali
--    fakultet, upisan upravo na taj smer, kao i koja je proseèna ocena na smeru
--    za tu generaciju te školske godine. Izdvojiti oznaku i naziv smera, ukupan 
--    broj upisanih studenata na fakultet te godine, ukupan broj upisanih studenata
--    na smer te godine i proseènu ocenu smera u toj generaciji. Izveštaj urediti
--    po proseènoj oceni.
with na_smeru as
(
 select s.id_smera, count(distinct d.indeks) n,
 		avg(ocena*1.0) ocena
 from smer s join nivo_kvalifikacije nk
 		on s.id_nivoa = nk.id_nivoa
 		and nk.stepen = 'I'
 	left outer join dosije d
 		on d.id_smera = s.id_smera
 		and year(datum_upisa) = 2006
 	left outer join ispit i
 		on d.indeks = i.indeks
 		and ocena > 5
 		and status_prijave = 'o'
 		and godina = 2006
 group by s.id_smera
),
svi as 
(
 select sum(n) n
 from na_smeru
)
select s.oznaka, s.naziv, svi.n ukupno, ns.n na_smeru,
	   ns.n*100.0 / svi.n, ocena
from smer s join na_smeru ns
	on s.id_smera = ns.id_smera, svi
order by ocena;