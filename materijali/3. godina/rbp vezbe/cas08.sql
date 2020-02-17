-- 1. Izdvojiti ukupan broj studenata.
select count(*) "Broj studenata"
from dosije;

-- 2. Izdvojiti ukupan broj studenata koji bar iz jednog predmeta imaju ocenu 10. 
select count "Broj studenata"
from dosije d
where exists (select *
			  from ispit i
			  where i.indeks = d.indeks
			  	and ocena = 10);
			  	
-- ili

select count(distinct indeks) "Broj studenata"
from ispit
where ocena = 10;

-- 3. Izdvojiti ukupan broj položenih predmeta i položenih bodova za studenta 
--    sa indeksom 25/2014.
select count "Broj polozenih predmeta", sum(p.bodovi) "Polozeni bodovi"
from ispit i join predmet p
	on i.id_predmeta = p.id_predmeta
where indeks = 20140025 and ocena > 5; 

-- 4. Izlistati ocene dobijene na ispitima i ako je ocena jednaka 5 ispisati NULL . 
select nullif(ocena, 5) "Ocene"
from ispit;

-- 5. Koliko ima razlièitih ocena dobijenih na ispitima, a da ocena nije 5?
select count(distinct ocena) "Broj razlicitih ocena"
from ispit
where ocena <> 5;

-- ili 
select count(distinct nullif(ocena, 5)) "Broj razlicitih ocena"
from ispit;

-- 6. Izdvojiti šifre, nazive i bodove predmeta èiji je broj bodova veæi od proseènog
--     broja bodova svih predmeta.
select p.sifra, p.naziv, p.bodovi
from predmet p
where p.bodovi > all (select avg(bodovi)
					  from predmet
					  where id_predmeta <> p.id_predmeta);
					  
-- ili 
select p.sifra, p.naziv, p.bodovi
from predmet p
where p.bodovi > (select avg(bodovi)
				  from predmet);
				  
-- 7. Za svaki predmet izraèunati koliko studenata ga je položilo. 
select count "Broj studenata po predmetu"
from ispit
where ocena > 5
group by id_predmeta;

-- 8. Za svakog studenta roðenog 1995. godine, koji ima bar jedan položen ispit, 
--    izdvojiti broj indeksa, proseènu ocenu, najmanju ocenu i najveæu ocenu iz 
--    položenih ispita. 
select i.indeks, dec(avg(ocena*1.0), 4, 2) "Prosek", 
	   min(ocena) "Najmanja ocena", max(ocena) "Najveca ocena"
from dosije d join ispit i
	on d.indeks = i.indeks
where year(datum_rodjenja) = 1995 and ocena > 5
group by i.indeks;

-- 9. Za svaku godinu ispitnog roka i predmet polagan u toj godini, pronaæi najveæu
--    ocenu dobijenu na ispitima tog predmeta u toj godini. Izdvojiti godinu roka, 
--    naziv predmeta i najveæu ocenu. 
select godina_roka, p.naziv, max(ocena) "Najveca ocena"
from ispit i join predmet p
	on i.id_predmeta = p.id_predmeta
group by godina_roka, p.id_predmeta, p.naziv;

-- 10. Izdvojiti nazive predmeta koje je polagalo više od 5 razlièitih studenata. 
select naziv
from predmet p join ispit i
	on p.id_predmeta = i.id_predmeta
group by naziv
having count(distinct indeks) > 5;

-- 11. Za svaki rok koji je održan u 2015. godini i u kome su svi polagani ispiti i
--     položeni, tj. nema ispita koji nije položen, izdvojiti oznaku roka, broj položenih 
--     ispita u tom roku i broj studenata koji su položili ispite u tom roku.
select oznaka_roka, count "Broj polozenih ispita", count(distinct indeks) "Broj studenata"
from ispit
where godina_roka = 2015
group by oznaka_roka
having min(ocena) > 5;

-- 12. Za svaki predmet izdvojiti broj studenata koji su ga polagali. Izdvojiti naziv 
--     predmeta i broj studenata. Rezultat urediti prema broju studenata koji su polagali
--     predmet u opadajuæem poretku.
select naziv, count(distinct indeks) "Broj studenata"
from predmet p left join ispit i
	on i.id_predmeta = p.id_predmeta
group by naziv, p.id_predmeta
order by count(distinct indeks) desc;

-- 13. Za svakog studenta izdvojiti broj indeksa i mesec u kome je položio više od dva ispita
--    (nije važno koje godine). Izdvojiti indeks studenta, ime meseca i broj položenih predmeta.
--    Rezultat urediti prema broju indeksa i mesecu polaganja.
select indeks, monthname(datum_ispita) "Mesec", count(distinct id_predmeta) "Broj polozenih ispita"
from ispit
where ocena > 5
group by indeks, monthname(datum_ispita)
having count > 2
order by indeks, monthname(datum_ispita);

-- 14. Koliko ima studenata koji su položili više od 10 bodova?
select count "Broj studenata"
from (
		select indeks, sum(p.bodovi)
		from ispit i join predmet p
			on i.id_predmeta = p.id_predmeta
			and ocena > 5
		group by indeks
		having sum(p.bodovi) > 10) as t;
		
-- ili 

with student_bodovi as
(select indeks, sum(p.bodovi) "Polozeno" -- svaka kolona mora da ima ime
 from ispit i join predmet p
 	on i.id_predmeta = p.id_predmeta
 	and ocena > 5
 group by indeks
 having sum(p.bodovi) > 10)
 select count "Broj studenata"
 from student_bodovi;