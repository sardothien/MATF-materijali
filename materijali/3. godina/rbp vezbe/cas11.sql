-- 1. Pronaæi poslednji položeni ispit za svakog studenta. Izdvojiti indeks
--    studenta i datum polaganja poslednjeg ispita.
select d.indeks, max(coalesce(datum_usmenog, datum_pismenog)) "Datum polaganja"
from dosije d left join ispit i
		on d.indeks = i.indeks
		and ocena > 5
		and status_prijave = 'o'
group by d.indeks;

-- 2. Za svaki smer na osnovnim akademskim studijama izdvojiti obavezne
--    predmete i, ako imaju, njihove uslovne predmete. Izdvojiti naziv
--    smera, naziv obaveznog predmeta i naziv uslovnog predmeta. 
select trim(s.naziv) smer, trim(p.naziv) obavezni,
	   trim(coalesce(p1.naziv, 'nema uslovnog')) uslovni
from nivo_kvalifikacije nk join smer s
		on nk.id_nivoa = s.id_nivoa
	join obavezan_predmet op
		on s.id_smera = op.id_smera
	join predmet p
		on p.id_predmeta = op.id_predmeta
	left join uslovni_predmet up
		on up.id_predmeta = op.id_predmeta
	left join predmet p1
		on p1.id_predmeta = up.id_predmeta
where nk.naziv = 'Osnovne akademske studije';

-- 3. Za svakog studenta smera Informatika na osnovnim akademskim studijama,
--    koji je fakultet upisao 2009. godine, pronaæi koje obavezne predmete 
--    nije položio. Izdvojiti ime i prezime studeta i naziv predmeta.
select ime, prezime, p.naziv
from nivo_kvalifikacije nk join smer s
		on s.id_nivoa = nk.id_nivoa
	join dosije d
		on d.id_smera = s.id_smera
	join obavezan_predmet op
		on op.id_smera = s.id_smera
	join predmet p
		on p.id_predmeta = op.id_predmeta
where nk.naziv = 'Osnovne akademske studije'
	and s.naziv = 'Informatika'
	and year(d.datum_upisa) = 2009
	
except 

select ime, prezime, p.naziv
from nivo_kvalifikacije nk join smer s
		on nk.id_nivoa = s.id_nivoa
	join dosije d
		on d.id_smera = s.id_smera
	join obavezan_predmet op
		on op.id_smera = d.id_smera
	join predmet p
		on p.id_predmeta = op.id_predmeta
	join ispit i 
		on i.id_predmeta = p.id_predmeta
		and i.indeks = d.indeks
		and i.ocena > 5
		and status_prijave = 'o'
where nk.naziv = 'Osnovne akademske studije'
	and s.naziv = 'Informatika'
	and year(d.datum_upisa) = 2009;
	
-- 4. Za svaki smer pronaæi studenta koji je položio najveæi broj bodova
--    na smeru. Izdvojiti naziv smera, indeks, ime i prezime studenta i
--    broj položenih bodova.
with student_polozeno as
(
 select s.naziv, s.id_smera, d.indeks, ime, prezime, sum(p.bodovi) espb
 from smer s join dosije d
 		on s.id_smera = d.id_smera
 	join ispit i
 		on i.indeks = d.indeks
 		and ocena > 5
 		and status_prijave = 'o'
 	join predmet p
 		on i.id_predmeta = p.id_predmeta
 group by s.naziv, d.indeks, ime, prezime, s.id_smera
),
smer_max as
(
 select id_smera, max(espb) max_polozeno
 from student_polozeno
 group by id_smera
)
select naziv, indeks, ime, prezime, espb
from student_polozeno sp join smer_max sm
	on sp.id_smera = sm.id_smera
	and espb = max_polozeno;

-- 5. Kreirati pogled kojim se izdvajaju svi ispitni rokovi poèev od 2011. godine. 
create view ispitni_rokovi_2011 as
select *
from ispitni_rok
where godina >= 2011;

--drop view ispitni_rokovi_2011;

-- 6. Kreirati pogled sa svim prijavljenim ispitima Marka Petroviæa.
create view ispiti_MP as
select i.*
from ispit i join dosije d
	on i.indeks = d.indeks
where ime = 'Marko'
	and prezime = 'Petrovic';

--drop view ispiti_MP;
	
-- 7. Kreirati pogled kojim se izdvajaju sva polaganja studenata koji se zovu 
--    Marko ili Maja, a u aprilskom ispitnom roku 2008. godine su položili
--    barem jedan predmet.
create view marko_i_maja as
select *
from ispit i 
where exists (select *
			  from dosije d
			  where i.indeks = d.indeks
			  	and ime = 'Marko' or ime = 'Maja')
  and exists (select *
  			  from ispit i1
  			  where i1.indeks = i.indeks
  			  	and i1.godina_roka = 2008
  			  	and oznaka_roka = 'apr'
  			  	and i1.ocena > 5
  			  	and i1.status_prijave = 'o')
with check option;

--drop view marko_i_maja;