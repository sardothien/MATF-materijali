-- 1. Napraviti tabelu polozeni_predmeti u kojoj æe se nalaziti podaci o 
--    položenim predmetima studenata. Tabela ima iste kolone kao i tabela ispit.
create table polozeni_predmeti(
	indeks integer not null,
	id_predmeta   integer     not null,
	godina_roka   smallint    not null,
	oznaka_roka   char(5)     not null,
	ocena 		  smallint	  not null,
	datum_ispita  date 				  ,
	bodovi 		  smallint			  ,
	primary key (indeks, id_predmeta, godina_roka, oznaka_roka),
	foreign key fk_ispit (indeks, id_predmeta, godina_roka, oznaka_roka)
	references ispit,
	constraint vrednost_ocene check (ocena between 6 and 10)
);

insert into polozeni_predmeti
select *
from ispit
where ocena > 5;

-- 2. Iz tabele polozeni_predmeti ukloniti kolonu datum_ispita.
alter table polozeni_predmeti
drop datum_ispita;

-- 3. Postaviti uslov da se u tabeli polozeni_predmeti mogu nalaziti samo 
--    podaci o ispitima na kojima je student dobio izmeðu 51 i 100 bodova
--    i da je podrazumevana ocena 6.
alter table polozeni_predmeti
add constraint bodovi_ispit check (bodovi between 51 and 100)
alter column ocena set default 6;

-- 4. Ukloniti tabelu polozeni_predmeti. 
drop table polozeni_predmeti;

-- 5. Napraviti tabelu student_ispiti koja ima kolone: 
--		indeks – indeks studenta; 
--		polozeni_ispiti – broj položenih ispita; 
--		prosek – prosek studenta. 
--	  Definisati primarni kljuè i strani kljuè na tabelu dosije.
create table student_ispiti (
	indeks			integer 	not null,
	polozeni_ispiti smallint			,
	prosek			double				,
	primary key (indeks),	
	constraint si_d foreign key (indeks) 
	references dosije
);

-- 6. Tabeli student_ispiti dodati kolonu broj_ispita koja predstavlja broj 
--    polaganih ispita. Dodati i ogranièenje da broj polaganih ispita mora 
--    biti veæi ili jednak od broja položenih ispita. 
alter table student_ispiti
add broj_ispita smallint
add constraint broj_polaganja check (broj_ispita >= polozeni_ispiti);

-- 7. U tabelu student_ispiti uneti podatke na osnovu podataka u tabeli ispit.
insert into student_ispiti
select indeks, 
	   sum(case
	   	     when ocena > 5 then 1
	   	     else 0
	   	   end),
	   dec(avg(case
	   			when ocena > 5 then ocena*1.0
	   			else null
	   		   end), 4, 2),
	   count
from ispit
group by indeks;