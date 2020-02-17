-- 1. Napisati SQL upit koji za sve studente rodjene u istom mestu prikazuje 
--    njihov broj, prosecnu ocenu i standradnu devijaciju. Izvestaj treba da
--    se odnosi na sve studente iz tog mesta, bez obzira da li su do sada 
--    polozili neki ispit ili ne. Pri izracunavanju uzeti u obzir ocene samo
--    iz predmeta koje su polozili.
select count(d.indeks), coalesce(dec(avg(ocena*1.0), 4, 2), 0) prosek, 
	coalesce(dec(stddev(ocena), 4, 2), 0) sd
from dosije d left join ispit i
		on d.indeks = i.indeks
		and status_prijave = 'o'
group by d.mesto_rodjenja;

-- 2. Napisati SQL upit koji za studente rodjene na petak 13. prikazuje indeks,
-- 	  koliko je dana proteklo od njihovog rodjenja do danas, kao i trenutnu
--	  prosecnu ocenu. Ako student nije polozio nijedan predmet, kao prosek ocena 
--    treba prikazati -1, a ako nije polagao nijedan predmet kao prosek treba
--    prikazati poruku 'Do sada nije polagao ispit'.
select d.indeks, days(current date) - days(datum_rodjenja) broj_dana,
	   case 
	   		when d.indeks not in (select indeks
	   							  from ispit)
	   			then 'Do sada nije polagao ispit'
	   		when avg(ocena*1.0) is null then -1
	   		else dec(avg(ocena*1.0), 4, 2)
	   end prosek
from dosije d join ispit i
		on i.indeks = d.indeks
where day(d.datum_rodjenja) = 13 
	and dayname(d.datum_rodjenja) = 'Friday'
	and status_prijave = 'o'
group by d.indeks, datum_rodjenja;

-- 3. Na nivou fakulteta doneta je odluka da se prebrojavaju studenti koji se
--    upisuju na studije. Pri tome, prvi naredni upisani sudent treba da ima
--    redni broj 1001, student upisan posle njega 1002, itd. Napisati SQL naredbu 
--    kojom se formira tabela dosije1 koja pored istih atributa kao i tabela dosije
--    ima i atribut rbr koji sadrzi redni broj novoupisanih studenata, i zabraniti
--    brisanje tako formirane tabele.
create table dosije1 like dosije;

alter table dosije1
add rbr	integer 
constraint uslov check (rbr >= 1001);

alter table dosije1
add restrict on drop;

create trigger dosije_nov
before insert on dosije1
referencing new as nova
for each row
set nova.rbr = (select coalesce(max(rbr), 1001)
				from dosije1) + 1;

alter table dosije1
drop restrict on drop;
drop table dosije1;

-- 4. Ne koristeci WITH naredbu napisati pogled koji sadrzi naziv smera, 
--    godinu upisa, broj studenata na tom smeru koji su upisani te godine, 
--    i maksimalnu vrednost trenutne prosecne ocene svakog od studenata 
--    upisanih u toj godini na tom smeru. 
create view pogled (naziv, godina, broj, prosek_max)
as
(
 select s.naziv, year(d.datum_upisa), count(d.indeks),
 	max((select avg(ocena*1.0) prosek
 		from ispit i join dosije d1
 			on i.indeks = d1.indeks
 		where ocena > 5
 			and status_prijave = 'o'
 			and year(d1.datum_upisa) = year(d.datum_upisa)
 			and d1.id_smera = d.id_smera
 			and d1.indeks = d.indeks
 		group by i.indeks))
 from smer s join dosije d
 	on s.id_smera = d.id_smera
 group by s.id_smera, s.naziv, year(d.datum_upisa)
);

drop view pogled;

-- 5. Formirati tabelu Dosije_nov koja sadrzi iste atribute kao i tabela 
--    dosije. Definisati jmbg kao primarni kljuc tabele Dosije_nov. Prosiriti
--    tabelu Dosije_nov atributom srednje_slovo koji treba da sadrzi srednje
--    slovo (ako postoji) studenta iz tabele. U slucaju da srednje slovo ne 
--    postoji, vrednost atributa treba da bude "nepoznato". Napuniti tabelu
--    Dosije_nov podacima iz tabele dosije, pri cemu se analizira sadrzaj
--    atributa prezime, i ako njemu postoji srednje slovo tada se taj sadrzaj 
--    razdvaja na dva dela: srednje slovo i ostatak prezimena koji se upisuju 
--    u atribute srednje_slovo i prezime tabele Dosije_nov. Srednje slovo je
--    karakter za kojim sledi ".".
create table dosije_nov like dosije;

alter table dosije_nov
add constraint pk primary key (jmbg);

alter table dosije_nov
add srednje_slovo char;

insert into dosije_nov (indeks, id_smera, jmbg, pol, datum_rodjenja,
mesto_rodjenja, drzava_rodjenja, ime_oca, ime_majke, ulica_stanovanja, 
kucni_broj, mesto_stanovanja, postanski_broj, drzava_stanovanja, telefon, 
mobilni_telefon, email, "www uri", datum_upisa, ime, prezime, srednje_slovo)
select indeks, id_smera, jmbg, pol, datum_rodjenja, mesto_rodjenja, 
	drzava_rodjenja, ime_oca, ime_majke, ulica_stanovanja, kucni_broj, 
	mesto_stanovanja, postanski_broj, drzava_stanovanja, telefon, 
	mobilni_telefon, email, "www uri", datum_upisa, ime, 
	case locate(prezime, '.')
		when 0 then prezime
		else substr(prezime, locate(prezime, '.')+1)
	end prezime,
	case locate(prezime, '.')
		when 0 then '?' -- 'Nepoznato'
		else substr(prezime, 1, locate(prezime, 1)-1)
	end srednje_slovo
from dosije d;

drop table dosije_nov;

-- 6. Napisati SQL naredbu za formiranje tabele kurs_domen koja implementira 
--    ogranicenja domena.
create table kurs_domen(
	id_predmeta		integer 	not null,
	godina			smallint	not null,
	semestar		smallint	not null,
	primary key (id_predmeta, godina, semestar),
	foreign key fk (id_predmeta)
		references predmet,
	constraint chk_semestar check (semestar in (1, 2))
);

drop table kurs_domen;

-- 7. Neka je PS prosecna ocena svih studenata na smeru S, i SDS standardna 
--    devijacija prosecne ocene svih studenata na smeru S. Formirati MQT 
--    Van_intervala koja sadrzi broj indeksa, ime i prezime, naziv smera i
--    prosecnu ocenu studenata cija je prosecna ocena van intervala 
--    [PS - SDS, PS + SDS]. Pri tome se PS i SDS odnose na smer koji
--    student studira. Prikazati, iz tabele Van_intervala, cetvrtog i petog 
--    studenta sa najvecim prosekom koji studira smer Informatika.
create table Van_intervala as
(
 with smerovi_ps as
 (
  select d.id_smera, avg(ocena*1.0) prosek
  from dosije d join ispit i
  	on i.indeks = d.indeks
  	and i.ocena > 5
  	and status_prijave = 'o'
  group by d.id_smera
 ),
 devijacija as
 (
  select d.id_smera, avg(ocena*1.0) prosek
  from dosije d join ispit i
  	on i.indeks = d.indeks
  	and i.ocena > 5
  	and status_prijave = 'o'
  group by d.id_smera, d.indeks
 ),
 dev2 as
 (
  select id_smera, stddev(prosek) dev
  from devijacija
  group by id_smera
 ),
 rez as
 (
  select d.id_smera, prosek-dev levo, prosek+dev desno
  from smerovi_ps sps join dev2 d
  	on sps.id_smera = d.id_smera
 ),
 std as
 (
  select d.indeks, s.naziv, s.id_smera, avg(ocena*1.0) prosek
  from dosije d join smer s
  		on s.id_smera = d.id_smera
  	join ispit i
  		on i.indeks = d.indeks
  		and ocena > 5
  		and status_prijave = 'o'
  group by d.indeks, s.id_smera, s.naziv
 )
 select indeks, naziv, prosek
 from std s join rez r
 	on s.id_smera = r.id_smera
 where prosek < levo or prosek > desno
)
data initially deferred
refresh deferred;

with pomocna as 
(
 select dense_rank() over(order by prosek desc) as rbr,
 	vi.indeks, vi.naziv
 from Van_intervala vi
 where naziv = 'Informatika'
) 
select *
from pomocna p
where p.rbr in (4, 5);

drop table Van_intervala;

-- 8. Definisati pogled duzine(tabela, korisnik, broj atributa,
--    duzina_sloga) koji sadrzi naziv tabele, identifikaciju korisnika 
--    koji je formirao tu tabelu, broj atributa u toj tabeli i duzinu 
--    sloga tabele (zbir duzina svih atributa u tabeli).
create view duzine(tabela, korisnik, broj_atributa, duzina_sloga) as
(
	select t.name, t.creator, t.colcount, sum(t1.length)
	from sysibm.systables t join sysibm.syscolumns t1
		on t.name = t1.tbname
	group by t.name, t.creator, t.colcount
);

drop view duzine;

-- 9. Napisati SQL upit koji prikazuje prvih 10 studenata sa najvecim prosekom 
--    ocena koji do sada nisu diplomirali.
with prosek as
(
 select d.indeks, coalesce(avg(ocena*1.0), 0) pr
 from dosije d left join ispit i
 		on i.indeks = d.indeks
 	join status s
 		on s.indeks = d.indeks
 		and s.status <> 'diplomirao'
 group by d.indeks
 order by pr desc
)
select p.indeks, p.pr
from prosek p
fetch first 10 rows only;

-- 10. Napisati SQL upit koji prikazuje naziv smera za koji vazi da su svi studenti 
--     koji ga studiraju polozili sve predmete koji mogu da budu uslovni za neki
--     drugi predmet u toku studija.
select distinct s.naziv
from smer s
where not exists (select indeks
				  from dosije d
				  where d.id_smera = s.id_smera
				  	and not exists (select up.id_uslovnog
				  					from uslovni_predmet up join obavezan_predmet op
				  						on up.id_predmeta = op.id_predmeta
				  					where op.id_smera = s.id_smera
				  						and exists (select i.id_predmeta
				  									from ispit i
				  									where i.indeks = d.indeks
				  										and ocena > 5
				  										and status_prijave = 'o'
				  										and i.id_predmeta = up.id_uslovnog)));

-- 11. Na SQL jeziku definisati funkciju ciji je argument tipa character(20),
--     a rezultat ulazna niska u kojoj su sva mala slova zamenjena velikim, i 
--     sva velika slova zamenjena malim, dok se karakteri koji nisu slova ne menjaju.
create function moja_fja(niska char(20))
returns char(20)
return translate(niska, 'abcdef...ABCD...', 'ABCD...abcdef...');

-- 12. Napisati upit kojim se primarni kljuc tabele dosije definise nad atributom
--     jmbg umesto postojeceg kljuca nad atributom indeks.
alter table dosije 
drop primary key;

alter table dosije
add constraint pk primary key (jmbg);

-- 13. Napisati SQL upit koji formira tabelu Dosije2013 koja ima iste atribute kao 
--     i tabela Dosije. Prosiriti tabelu atributom prosek koji treba da sadrzi trenutni 
--     prosek ocena studenta zaokruzen na dve decimale, i atributom redosled koji sadrzi
--     trenutni redosled tog studenta po proseku u okviru smera koji studira. Upisati u 
--     tabelu Dosije2013 podatke koji se odnose na studente upisane 2013. godine i popuniti
--     vrednosti atributa prosek i redosled.
create table dosije2013 like dosije;

alter table dosije2013
add constraint pk primary key (indeks);

alter table dosije2013
add prosek dec(4, 2);

alter table dosije2013
add redosled smallint;
    
insert into dosije2013
with pom as
(
 select d.indeks, dec(coalesce(avg(ocena*1.0), 0), 4, 2) prosek
 from dosije d left join ispit i
	on i.indeks = d.indeks
	and ocena > 5
	and status_prijave = 'o'
 where year(datum_upisa) = 2013
 group by d.indeks
)
select d.*, prosek, rank() over (order by prosek desc) redosled
from pom p join dosije d
	on d.indeks = p.indeks;
		
drop table dosije2013;

-- 14. (62)
--create view polaganje (rbr, ime, prezime, naziv_smera, najvise_polagan, 
--br_polaganja, poslednja_ocena, preth_ocena) as 
--(
-- with student as
-- (
--  select i.indeks, i.id_predmeta, count br
--  from ispit i
--  group by i.indeks, i.id_predmeta
-- ),
-- pol as
-- (
--  select indeks, id_predmeta, br
--  from student s
--  where br >= all(select br
--  				  from student s1
--  				  where s.indeks = s1.indeks)
-- )
-- select ime, prezime, naziv, id_predmeta, br, 
-- 	(select ocena
-- 	 from ispit i
-- 	 where i.indeks = d.indeks
-- 	 	and i.id_predmeta = p.id_predmeta
-- 	 	and br_polaganja = p.br),
-- 	 case when br > 1 then (select char(ocena) 
-- 	 					    from ispit i
-- 	 					    where i.indeks = d.indeks
-- 	 					    	and i.id_predmeta = p.id_predmeta
-- 	 					    	and br_polaganja = br-1)
-- 	 				  else '----'
-- 	 end 	 	
-- from pol p join dosije d
-- 		on p.indeks = d.indeks
-- 	join smer s 
-- 		on s.id_smera = d.id_smera
--);

-- 15. Napisati SQL upit koji prikazuje komentare koji se odnose na tabele
--     koje je napravio korisnik koji izvrsava upit.
select comments
from user_tab_comments;

-- ili

select remarks
from sysibm.systables
where creator = user;


-- 16. Napisati deklaraciju tabele izborni_predmet koja sadrzi informacije
--     o studentima koji su se prijavili za pohadjanje pojedinih izbornih
--     predmeta. Tabela treba da sadrzi informacije koje jednoznacno odredjuju
--     prijavljenog studenta, izborni predmet, kao i redosled, vreme i datum 
--     prijavljivanja. Redosled prijavljivanja je odredjen redosledom upisa u
--     tabelu, i kao i vreme i datum treba da se upisuju automatski, bez unosenja
--     podataka od strane studenta. U tabeli definisati odgovarajuce primarne i 
--     spoljasnje kljuceve.
create table izborni_predmet (
	indeks		integer		not null,
	id_predmeta integer 	not null, 
	rbr			integer		not null 	generated always as identity(start with 1),
	vreme		time		with default current time,
	datum		date		with default current date,
	primary key (indeks, id_predmeta, rbr),
	foreign key (indeks) references dosije,
	foreign key (id_predmeta) references predmet
);

drop table izborni_predmet;

-- 17. Napisati korinsnicki definisanu funkciju isecak(poluprecnik, ugao) ciji
--     su argumenti velicina poluprecnika kruga i broj stepni kruznog isecka, a 
--     rezultat povrsina tog isecka zapisana kao realan broj u pokretnom zarezu 
--     pomocu dekadne osnove.
create function isecak(poluprecnik float, ugao float)
returns float
return poluprecnik * poluprecnik * radians(180) * ugao / 360;

-- 18. Napisati upit kojim se prikazuje, po korisnicima, broj tabela koje je taj
--     korisnik napravio, broj atributa u tim tabelama, kao i prosecna vrednost
--     i standardna devijacija duzine atributa u tabelama.
select char(creator, 20) korisnik, count(distinct t.name) broj,
	sum(t.colcount) kolone, dec(avg(t1.length*1.0), 7, 2) prosek,
	dec(stddev(t1.length*1.0), 7, 2) stand_dev
from sysibm.systables as t join sysibm.syscolumns t1
	on t.name = t1.tbname
group by creator;

-- 19. (70)
--create view ocene (indeks, ime, prezime, naziv_smera, najcesca_ocena, br_ocena,
-- poslednji_datum) as
--(
-- with br_ocena as
-- (
--  select indeks, ocena, count(*) br
--  from ispit
--  where ocena is not null
--  group by indeks, ocena
-- ),
-- najcesca_ocena as
-- (
--  select distinct indeks, br, 
--  	(select max(ocena)
--  	 from br_ocena br1
--  	 where br1.indeks = br2.indeks)
--  from br_ocena br2
-- )
-- select distinct d.indeks, ime, prezime, naziv, najcesca, noc.br,
-- 	(select max(coalesce(datum_usmenog, datum_pismenog))
-- 	 from ispit i1
-- 	 where noc.indeks = i1.indeks	
-- 	 	and najcesca = ocena)
-- from najcesca_ocena noc join dosije d
-- 		on d.indeks = noc.indeks
-- 	 join smer s
-- 	 	on s.id_smera = d.id_smera;
--)

-- 20. Formirati pogled preostalo(broj_indeksa, ime, prezime, 
--     naziv_smera_koji_student_studira, broj_bodova) koji sadrzi 
--     informacije o broju bodova koji je preostao svakom od studenata 
--     do zavrsetka studija. Napisati i SQL upit kojim se daje dozvola
--     korisnicima STUDENT i NASTAVNIK za brisanje pogleda preostalo uz
--     mogucnost prenosenja dozvole na druge korisnike.
create view preostalo (br_indeksa, ime, prezime, naziv_smera, br_bodova)  as
(
 select d.indeks, ime, prezime, s.naziv,
 	case
 		when sum(p.bodovi) is null 
 			then s.bodovi
 			else s.bodovi - sum(p.bodovi)
 	end
 from dosije d join smer s
 		on d.id_smera = s.id_smera
 	left join ispit i
 		on i.indeks = d.indeks
 		and ocena > 5
 		and status_prijave = 'o'
 	left join predmet p
 		on p.id_predmeta = i.id_predmeta
 group by d.indeks, ime, prezime, s.naziv, s.bodovi
);

grant delete on table preostalo to STUDENT, NASTAVNIK with grant option;

drop view preostalo;

-- 21. Napisati upit kojim se formira pogled mesto_rodjenja(broj_indeksa,
--     ime, prezime,mesto_rodjenja) koji sadrzi broj indeksa, ime i prezime 
--     studenta, JMBG i mesto rodjenja svih studenata koji su upisani na 
--     studije 2012. godine ili kasnije i koji su rodjeni u petak 13. Pri tome,
--     u pogled treba izdvojiti samo one studente cije je ime i prezime zapisano
--     velikim pocetnim slovom. Pogled oformiti tako da bude onemogucen unos slogova 
--     u tabelu dosije koji ne zadovoljavaju definiciju pogleda.
create view mesto_rodjenja (br_indeksa, ime, prezime, jmbg, mesto_rodjenja) as
(
 select indeks, ime, prezime, jmbg, mesto_rodjenja
 from dosije d
 where year(datum_upisa) >= 2012
 	and day(datum_rodjenja) = 13
 	and dayname(datum_rodjenja) = 'Friday'
 	and substr(ime, 1, 1) = upper(substr(ime, 1, 1))
 	and substr(prezime, 1, 1) = upper(substr(prezime, 1, 1))
)
with check option;

drop view mesto_rodjenja;

-- 22. Napisati SQL upite pomocu kojih se daje dozvola za formiranje i brisanje 
--     spoljasnjih kljuceva nad tabelom ispit svim korisnicima sem korisniku STUDENT.
grant references on table ispit to public;
revoke references on table ispit from student;

-- 23. Formirati MQT duplikat koji sadrzi iste podatke kao i pogled definisan u
--     prethodnom pitanju uz uslov da je prosecna ocena povecana za 1 na predmetima
--     koje je polozio bar jedan student. Napuniti tako definisanu tabelu.
create table duplikat (naziv, prosek, devijacija, broj) as
(
 select naziv_predmeta, case
 			when prosek_ocena > -1
 				then prosek_ocena+1
 				else prosek_ocena
 			end, standradna_devijacija, br_studenata
 from najlaksi_i_najtezi
)
data initially deferred
refresh deferred;

-- 24. Napisati korisnicki definisanu funkciju ciji su argumenti niska maksimalne 
--     duzine 30000 i niska maksimalne duzine 10, a rezultat broj pojavljivanja 
--     druge niske u prvoj.
create function niske(s1 varchar(30000), s2 varchar(10))
returns int
return (length(trim(s1)) - length(replace(trim(s1), s2, ''))) / length(trim(s2));

drop function niske;

-- 25. Formirati tabelu ispit_januar koja ima iste atribute kao i tabela ispit. 
--     Upisati u formiranu tabelu podatke o polaganim ispitima u januarskom 
--     ispitnom roku, bez obzira na godinu polaganja, a zatim definisati primarne
--     i spoljasnje kljuceve tabele ispit_januar.
create table ispit_januar like ispit;

insert into ispit_januar
select i.*
from ispit i
where oznaka_roka = 'jan';

alter table ispit_januar
add constraint pk primary key (indeks, id_predmeta, godina_roka, oznaka_roka)
add constraint s1 foreign key (id_predmeta) references predmet
add constraint s2 foreign key (indeks) references dosije
add constraint s3 foreign key (godina_roka, oznaka_roka) references ispitni_rok;

drop table ispit_januar;

-- 26. Napisati SQL naredbu kojom se korisniku STUDENT daje dozvola za 
--     promenu vrednosti atributa ime i prezime iz prethodnog pitanja.
grant update (ime, prezime) on table dosije to student;

-- 27. Formirati pogled ispisani(ime, prezime, naziv_smera, datum_upisa,
--     naziv_predmeta, prosek_ocena, broj_polozenih_predmeta) koji sadrzi 
--     informacije o ispisanim studentima. Ukoliki student nije polozio 
--     nijedan predmet, kao broj polozenih ispita treba da stoji tekst
--     'nije polozio nijedan predmet'.
create view ispisani (ime, prezime, naziv_smera, datum_upisa, naziv_predmeta,
prosek_ocena, br_polozenih) as
(
 select ime, prezime, s.naziv, d.datum_upisa, p.naziv,
 	coalesce(dec(avg(ocena*1.0), 4, 2), 0.0) prosek,
 	case when count(distinct i.id_predmeta) = 0
 		then 'nije polozio nijedan predmet'
 		else char(count(distinct i.id_predmeta))
 	end br_polozenih
 from dosije d join smer s
 		on s.id_smera = d.id_smera
 	join status st
 		on st.indeks = d.indeks
 		and st.status = 'ispisan'
 	left join ispit i 
 		on i.indeks = d.indeks
 		and ocena > 5
 		and status_prijave = 'o'
 	left join predmet p
 		on p.id_predmeta = i.id_predmeta
 group by ime, prezime, s.naziv, datum_upisa, p.naziv
);

drop view ispisani;

-- 28. Formirati MQT ispisani_2015 koja sadrzi podatke kao i pogled 
--     definisan u prethodnom pitanju i dodatni atribut rbr koji 
--     predstavlja redni broj ispisanog studenta u 2015. godini. 
--     Vrednost atributa rbr treba da se automatski poveca za svakog 
--     ispisanog studenta.
create table ispisani_2015 (ime, prezime, naziv_smera, datum_upisa, naziv_predmeta,
prosek_ocena, br_polozenih, rbr) as
(
	select i.*, rank() over (order by datum desc) ebe
	from ispisani i join status s
		on s.indeks = i.indeks
	where year(i.datum) = 2015
)
data initially deferred
refresh deferred;

drop table ispisani_2015;

-- 29. Definisati korisnicki defnisan tip podataka UGAO koji predstavlja mogucu 
--     velicinu ugla u trouglu. Defnisiati korisnicki definisanu funkciju ciji
--     su argumenti ostar ugao u pravouglom trouglu i velicina katete naspram
--     tog ugla, a rezultat velicina hipotenuze tog pravouglog trougla. 
--     Argument koji predstavlja ugao je tipa UGAO.
create distinct type ugao as double
with comparisons;

create function ostar (alfa ugao, a double)
returns double
return a / sin(radians(double(ugao)));

drop type ugao;
drop function ostar;

-- 30. Neka korisnik STUDENT ima dozvolu za citanje kompletne tabele ispit.
--     Napisati naredbe kojima mu se oduzima dozvola za citanje vrednosti 
--     atributa semestar i brojpol.
revoke select on table ispit from student;

create view ispit1 (indeks, id_predmeta, godina_roka, oznaka_roka, godina, 
datum_prijave, nacin_prijave, status_prijave, datum_usmenog, datum_pismenog,
bodovi_usmenog, bodovi_pismenog, bodovi, ocena, nastavnik, napomena) as
(
 select indeks, id_predmeta, godina_roka, oznaka_roka, godina, 
	datum_prijave, nacin_prijave, status_prijave, datum_usmenog, datum_pismenog,
	bodovi_usmenog, bodovi_pismenog, bodovi, ocena, nastavnik, napomena
 from ispit
);

grant select on ispit1 to student;

drop view ispit1;

-- 31. Neka tabela I_godina sadrzi podatke o studentima koji su upisani u I 
--     godinu studija. Struktura tabele je ista kao i struktura tabele dosije.
--     Napisati upit koji koriscenjem naredbe MERGE unosi u tabelu dosije podatke
--     o novim studentima. U slucaju da je neki od vec aktivnih studenata ponovo 
--     polagao prijemni radi upisa na studije, u vecpostojecim podacima u tabeli 
--     dosijea zameniti samo broj indeksa i datum upisa, ali ne i ostale podatke.
create table I_godina like dosije;

insert into I_godina
select *
from dosije;
-- where I godina 

merge into dosije d using
(
 select ig.*
 from I_godina ig
) as t
on d.indeks = t.indeks
when matched
	then 
		update
		set (d.indeks, d.datum_upisa) = (t.indeks, t.datum_upisa)
when not matched
	then 
		insert
		values(t.indeks, t.id_smera, t.ime, t.prezime, t.pol, t.jmbg, 
			t.datum_rodjenja, t.mesto_rodjenja, t.drzava_rodjenja,
			t.ime_oca, t.ime_majke, t.ulica_stanovanja, t.kucni_broj,
			t.telefon, t.mobilni_telefon, t.postanski_broj, t.email,
			t."www uri", t.datum_upisa);
			
-- 32. Formirati MQT ime_deo_prezimena koja sadrzi ime, prezime, broj indeksa, 
--     smer studija, broj polozenih ispita i poziciju imena u prezimenu, pri
--     cemu vazi da se ime nalazi u prezimenu pocev od navedene pozicije.
create table ime_deo_prezimena(ime, prezime, indeks, id_smera, br_polozenih, poz_imena)
as
(
 select ime, prezime, d.indeks, id_smera, count(id_predmeta) br_polozenih,
 	locate(ime, prezime) poz_imena
 from dosije d join ispit i
 		on d.indeks = i.indeks
 		and ocena > 5
 		and status_prijave = 'o'
 group by ime, prezime, d.indeks, id_smera
)
data initially deferred
refresh deferred;

drop table ime_deo_prezimena;

-- 33. Napisite naredbu kojom se korisniku STUDENT daje dozvola da azurira 
--     atribute ime i prezime u tabeli dosijea.
grant update (ime, prezime) on dosije to student;
 
-- 34. Formirati pogled upisani(rbr, ime, prezime, naziv, smera, datum_upisa,
--     broj polozenog predmeta) koji sadrzi informacije o studentima koji su 
--     upisani 2009. ili 2010. godine, i imaju bar 3 polozena ispita. Atribut
--     rbr automatski dobija vrednost prema datumu upisa studenta (najranije
--     upisani student dobija rbr=1).
create view upisani(rbr, ime, prezime, naziv_smera, datum_upisa, br_polozenih) as
(
 select rank() over (order by datum_upisa asc) rbr, ime, prezime, s.naziv, 
 	datum_upisa, count(id_predmeta) br_polozenih
 from dosije d join smer s
 		on s.id_smera = d.id_smera
 	join ispit i	
 		on i.indeks = d.indeks
 		and ocena > 5
 		and status_prijave = 'o'
 where year(datum_upisa) in (2009, 2010)
 group by ime, prezime, s.naziv, datum_upisa
 having count(id_predmeta) >= 3
);

drop view upisani;

-- 35. Napisati sql naredbu kojom se korisniku STUDENT oduzima dozvola za 
--     promenu tipa nekog atributa tabele dosije.
revoke alter on dosije from student;

-- 36. Napisati sql naredbu kojom se korisniku STUDENT daje dozvola za brisanje 
--     tabele dosije uz mogucnost prenosenja dozvole na druge korisnike.
grant delete on table dosije to student with grant option;

-- 37. Napisati SQL upit pomocu kojih se korisniku KOR1 daje dozvola da cita
--     atribute broj indeksa i datum rodjenja studenata u tabeli dosije.
create view dozvola (indeks, datum_rodjenja) as
select indeks, datum_rodjenja
from dosije;

revoke select on dosije from kor1;
grant select on dozvola to kor1;

-- 38. Napisati SQL upit pomocu kojih se korisniku KOR1 omogucava da brise 
--     sadrzaj tabele semestar uz mogucnost prenosenja dozvole na druge korisnike.
grant delete on semestar to kor1 with grant option;

-- 39. Formirati pogled kandidati koji sadrzi sve podatke iz tabele dosijea o 
--     studentima koji su upisani u prosloj kalendarskoj godini, imaju mobilne
--     telefone i cija glavna strana na sajtu nema adresu koja sadrzi vise od 
--     2 znaka '%'.
create view kandidati(ime, prezime, indeks) as
(
 select ime, prezime, d.indeks
 from dosije d
 where year(datum_upisa) = year(current date)-1
 	and d.mobilni_telefon is not null
 	and d.mobilni_telefon <> ''
 	and length("www uri") - length(replace(trim("www uri"), '%', '')) <= 2
);

drop view kandidati;

-- 40. Napisati SQL upit kojim se prikazuju, bez koriscenja WITH naredbe, imena,
--     prezimena i prosek prvih 5 studenata sa najvecim prosekom koji imaju to
--     ime i prezime. Pri tome su podaci koji se odnose na jednog studenta razdvojeni
--     uspravnom crtom ('|') od podataka za drugog studenta.
select listagg(ime_prezime || ' ' || char(prosek), ' | ')
from (select trim(ime) || ' ' || trim(prezime) ime_prezime,
	   		dec(avg(ocena*1.0), 4, 2) prosek
	  from dosije d join ispit i 
	  	on i.indeks = d.indeks
	  	and ocena > 5
	  	and status_prijave = 'o'
	  group by ime, prezime
	  order by 2 desc
	  fetch first 5 rows only);
