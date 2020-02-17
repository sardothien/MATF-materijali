----------------- JAN1 2019 ------------------------

-- I grupa

-- 5. Na ovu foru. Samo videti kako se tacno zovu polja koja nam trebaju
--    Moze se naci u DataStudio.
select rank() over (order by tablename) as redosled
from sysibm.systables
where creator = user
    and (tablename like '%' 
    or tablename like '%a%'
    or tablename like '%a%a%')
    and tablename not like '%a%a%a%'
    and date < 2014 -- dodati i dan
order by tablename;

-- 7. a)
alter table dosije
    alter column jmbg bigint;

alter table dosije 
    add primary key (jmbg);

-- 7. v)
select indeks as "Indeks",
    XMLQUERY('$PODATAK/student/ime/text()') as "Ime",
    XMLQUERY('$PODATAK/student/prezime/text()') as "Prezime",
    XMLQUERY('$PODATAK/student/prosek/text()') as "Prosek"
from dosije_xml
where XMLEXISTS('$PODATAK/student[ime = "Milos"]')
    and XMLEXISTS('$PODATAK/student[godina_studija = 3]');
    
-- II grupa
-- 4. v) Ideja:
create trigger Azur update on dosije 
referencing new as nova
when (nova.ocena > 5)
update dosije
set prosek = avg(ocena*1.0);

-- 7. a)
grant alter on column jmbg to public;
revoke all privileges on column ispit from user; 
-- 7. v) Slicno kao u I grupi
    
--------------------------- JAN 2 2019. -----------------------------------

-- I grupa

-- 1. v) Slicna ideja kao 5. u jan1
-- 2. 
create function Povrsina_Trougla(str1 float, str2 float, ugao float)
return float
return 1/2 * (str1*str2*sin(ugao));

-- 4. v) Slicno kao i 7.v) u jan1

-- II grupa - sve slicno
