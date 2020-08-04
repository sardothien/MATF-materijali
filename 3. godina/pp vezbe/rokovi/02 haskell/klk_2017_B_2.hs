-- Grupa hakera je osmislila poseban algoritam za sifrovanje podataka. 
-- Podaci predstavljaju listu celih brojeva. Sifrovanje funkcionise 
-- tako sto se hakeri dogovore oko tajnog broja k pomocu koga racunaju 
-- kontrolnu cifru koja se salje nakon svakih k brojeva. 
-- Napisati funkciju:
-- desifruj lista k
-- desifruj :: [Int] -> Int -> [Int]
-- koja kao argumente dobija listu brojeva koje hakeri zele da posalju 
-- i broj k, a kao rezultat vraca desifrovanu listu brojeva koja ne 
-- sadrzi kontrolne cifre. Brojevi su sifrovani tako sto je pozitivnom 
-- broju oduzeta 1, a negativnom dodata 1.

desifruj [] _ = []
desifruj lista 0 = lista
desifruj lista k = pocetak ++ desifruj ostatak k
    where s = take k lista
          pocetak = map (\x -> if x > 0 then x-1 else x+1) s
          ostatak = drop (k+1) lista