-- 1. Ispisati sva muška imena koja postoje meðu studentima, prebrojati ih i
--    urediti prema zastupljenosti.
select ime, count BROJ_MUSKARACA
from dosije
where pol = 'm'
group by ime
order by BROJ_MUSKARACA desc;

-- 2. Za svakog studenta ispisati njegov indeks, ime i prezime spojene u jednoj 
--    koloni i broj položenih bodova.
select d.indeks, trim(ime) || ' ' || trim(prezime) "Ime i prezime",
       sum(p.bodovi) "ESPB" 
from dosije d join ispit i
		on i.indeks = d.indeks
	join predmet p
		on p.id_predmeta = i.id_predmeta
where status_prijave = 'o'
	and ocena > 5
group by d.indeks, ime, prezime
order by 3 desc;