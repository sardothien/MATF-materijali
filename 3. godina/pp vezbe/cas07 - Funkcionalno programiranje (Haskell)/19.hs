{- Za razliku od Alekse i Luke, Ana i Milica imaju problem desifrovanja 
   podataka. Da bi Ana desifrovala podatke koje joj Milica posalje potrebno 
   je da svaku nisku iz dobijene liste transformise na sledeci nacin: 
   ukoliko dobijena niska pocinje cifrom, sa njenog pocetka izbaciti
   onoliko karaktera koliko ta niska ima cifara, a ukoliko dobijena niska 
   pocinje malim slovom, sa njenog pocetka izbaciti onoliko karaktera koliko 
   ta niska ima malih slova. Pretpostaviti da ce ovakvim desifrovanjem Ana 
   uvek dobiti ispravne izvorne podatke. Definisati sledece funkcije koje
   pomazu Ani da desifruje Milicine poruke: -}

-- (a) cifre s - za datu nisku s vraca broj karaktera niske koji su cifre
cifre lista = length (filter (==True) (map (\a -> elem a ['0'..'9']) lista))

-- (b) mala s - za datu nisku s vraca broj karaktera niske koji su mala slova
mala lista = length (filter (==True) (map (\a -> elem a ['a'..'z']) lista))

-- (c) desifruj ls - datu listu niski ls transformise na sledeci nacin: 
--     ukoliko niska pocinje cifrom, sa njenog pocetka izbacuje onoliko 
--     karaktera koliko ta niska ima cifara, a ukoliko dobijena niska 
--     pocinje malim slovom, sa njenog pocetka izbacuje onoliko karaktera 
--     koliko ta niska ima malih slova.
desifruj lista = map (desif) lista

desif lista
    | head lista >= '0' && head lista <= '9' = drop (cifre lista) lista
    | head lista >= 'a' && head lista <= 'z' = drop (mala lista) lista
    | otherwise = lista