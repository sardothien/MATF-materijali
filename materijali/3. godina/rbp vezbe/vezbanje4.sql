-- JANUAR 1 2019

-- 1. Написати упит на SQL-у коjим се издваjаjу идентификатори и називи предмета
--    коjи задовољаваjу бар jедан од услова:
--     • предмет jе обавезан на М смеру и неки студент М смера jе таj предмет положио 
--       cа оценом већом од 7 у последње 3 године;
--     • предмет има више од 2 условна предмета.
--    Извештаj уредити у опадаjућем поретку према називу предмета.
select p.id_predmeta, p.naziv
from predmet p
where p.id_predmeta in (select op.id_predmeta
						from obavezan_predmet op join smer s
							on s.id_smera = op.id_smera
						where s.oznaka = 'M'
							and exists (select *
										from ispit i join dosije d
											on i.indeks = d.indeks
										where d.id_smera = s.id_smera
											and ocena > 7
											and status_prijave = 'o'
											and coalesce(datum_pismenog, datum_usmenog) > current date - 3 years))
	or (select count(id_uslovnog)
		from uslovni_predmet up
		where p.id_predmeta = up.id_predmeta) > 2
order by p.naziv desc;

-- 2. Написати упит на SQL-у коjим се за студенте коjи су током школовања 
--    више пута прелазили на буџет него на самофинансирање издваjаjу информациjе 
--    о њиховим првим неуспешним полагањима предмета коjи нису обавезни на њиховом 
--    смеру. Издвоjити име и презиме студента, назив полаганог предмета као и броj 
--    освоjених бодова на испиту.
with a as
(
 select indeks, datum d1, status s1,
 	lead(datum) over (order by indeks, datum) d2,
 	lead(status) over (order by indeks, datum) s2
 from status
 order by indeks, datum 
),
b as
(
 select indeks, max(datum) max_datum
 from status
 group by indeks
 order by indeks
),
c as 
(
 select a.indeks, d1, s1, d2, s2
 from a join b
 	on a.indeks = b.indeks
 
 minus
 
 select a.indeks, d1, s1, d2, s2
 from a join b
 	on a.indeks = b.indeks
 where d1 = max_datum
 order by 1, 2
),
studenti as
(
 select indeks, 
 	sum(case when s1 = 'samofinansiranje' and s2 = 'budzet'
 			then 1
 			else 0
 	end) na_budzet,
 	sum(case when s1 = 'budzet' and s2 = 'samofinansiranje'
 			then 1
 			else 0
 	end) na_samofin
 from c
 group by indeks
 order by indeks
),
neobavezni as
(
 select d.indeks, uk.id_predmeta
 from dosije d join upisan_kurs uk
 	on d.indeks = uk.indeks
 where uk.id_predmeta not in (select id_predmeta
 							  from obavezan_predmet op
 							  where op.id_smera = d.id_smera)
)
select distinct ime, prezime, p.naziv, i.bodovi
from dosije d join studenti st
		on d.indeks = st.indeks
	join neobavezni n
		on n.indeks = d.indeks
	join predmet p
		on p.id_predmeta = n.id_predmeta
	join ispit i
		on i.indeks = d.indeks
		and i.id_predmeta = n.id_predmeta
where ocena = 5 and status_prijave = 'o'
	and coalesce(datum_pismenog, datum_usmenog) = 
		(select min(coalesce(datum_pismenog, datum_usmenog))
		 from ispit 
		 where indeks = d.indeks
		 	and id_predmeta = i.id_predmeta
		 	and ocena = 5
		 	and status_prijave = 'o');
		 	
-- 3. Факултет организуjе путовање за студенте. Пуна цена путовања jе 25000 рсд.
-- (a) Направити табелу putovanje коjа чува податке о студентима заинтересованим
--     за путовање. Табела има колоне: indeks - индекс студента; cena - цена путовања 
--     за студента; status_placanja - статус плаћања. Дефинисати примарни кључ табеле 
--     putovanje, као и страни кључ на табелу dosije.
create table putovanje (
	indeks				integer		not null,
	cena				integer		default 25000,
	status_placanja		varchar(15)			,
	primary key (indeks),
	foreign key (indeks) references dosije
);

-- (b) Написати наредбу коjа у табели putovanje поставља ограничење да вредност 
--     kолоне status_placanja може бити ’placeno’, ’oslobodjen’, ’neplaceno’ и да 
--     jе подразумевана вредност колоне status_placanja ’neplaceno’.
alter table putovanje
add constraint provera_statusa
	check (status_placanja in ('placeno', 'oslobodjen', 'neplaceno'))		
alter status_placanja set default 'neplaceno';

-- (c) Написати наредбу коjа у табелу putovanje уноси податке за студенте коjи 
--     су у 2012/2013 школскоj години положили бар половину уписаних ЕСПБ у тоj
--     школскоj години. Напомена: Немаjу сви студенти оверену школску годину 
--     2012/2013, тj. податак у колони overeno_bodova не одговара броjу положених
--     ЕСПБ за сваког студента. Унети само индекс студента.
insert into putovanje (indeks)
with upisani as
(
 select d.indeks, uk.id_predmeta, ug.datum_upisa, ug.datum_overe
 from dosije d join upisan_kurs uk	
 		on d.indeks = uk.indeks
 	join upis_godine ug
 		on ug.indeks = d.indeks
 	join predmet p
 		on p.id_predmeta = uk.id_predmeta
 where uk.godina = 2012
),
a as
(
 select u.indeks, sum(p.bodovi) polozeno
 from upisani u join ispit i
 		on i.indeks = u.indeks
 	join predmet p
 		on u.id_predmeta = p.id_predmeta
 where p.id_predmeta = u.id_predmeta
 	and ocena > 5
 	and status_prijave = 'o'
 	and coalesce(datum_pismenog, datum_usmenog) > u.datum_upisa
 	and coalesce(datum_pismenog, datum_usmenog) < u.datum_overe
 group by u.indeks
),
b as 
(
 select d.indeks, sum(p.bodovi) upisano
 from dosije d join upisan_kurs uk
 		on uk.indeks = d.indeks
 	join predmet p
 		on p.id_predmeta = uk.id_predmeta
 where uk.godina = 2012
 group by d.indeks
)
select a.indeks
from a join b
	on a.indeks = b.indeks
where polozeno >= upisano / 2;

-- (d) Написати наредбу коjа мења табелу putovanje тако да садржи приjаве за путовање 
--     свих студената коjи нису дипломирали. Студентима о коjима постоjе подаци у табели 
--     putovanje ажурирати податке на следећи начин:
--     - ако jе студент бар на половини положених испита добио оцену 10 ослобођен jе плаћања
--       путовања. Поставити цену на 0 и статус плаћања на ’oslobodjen’
--     – осталим студентима израчунати цену према формули: цена путовања се умањуjе за проценат
--       коjи одговара проценту испита коjе jе студент положио са оценом 10 у односу на његов броj
--       положених испита.
--      За студенте о коjима не постоjе подаци у табели putovanje унети податке. Унети индекс и цену.
--      Пуну цену путовања умањити за проценат коjи одговара проценту испита коjе jе студент положио
--      са оценом 10.
merge into putovanje put
using
(
 select distinct st.indeks, 
 	case when
	 	(select count(*) 
	 	 from ispit i
	 	 where i.indeks = st.indeks
	 	 	and ocena = 10
	 	 	and status_prijave = 'o') 
	 	 >= 
	 	 (select count(*)
	 	  from ispit i
	 	  where i.indeks = st.indeks
	 	  	and ocena > 5
	 	  	and status_prijave = 'o') / 2
 	  then 0.0
 	  else dec((select count(*)
 	  			from ispit i
 	  			where i.indeks = st.indeks
 	  				and ocena = 10
 	  				and status_prijave = 'o')*100.0 / (select count(*)
 	  												   from ispit i
 	  												   where i.indeks = st.indeks
 	  												   	and ocena > 5
 	  												   	and status_prijave = 'o'), 5, 2)
 	 end cena
 from status st
 where st.indeks not in (select indeks
 						 from status
 						 where status = 'diplomirao')) se
on (se.indeks = put.indeks)
when matched then
	update
	set put.cena = case when se.cena = 0.0
						then 0
						else floor(25000-25000/100.0*se.cena)
				   end,
		put.status_placanja = case when se.cena = 0
							then 'oslobodjen'
							else 'neplaceno'
						end
when not matched then
	insert 
	values (se.indeks, case when se.cena = 0.0 
						then 0
						else floor(25000 - 25000/100.0*se.cena)
						end,
						case when se.cena = 0.0
						then 'oslobodjen'
						else 'neplaceno'
						end);

-- (e) Написати наредбу за брисање табеле putovanje.
drop table putovanje;
