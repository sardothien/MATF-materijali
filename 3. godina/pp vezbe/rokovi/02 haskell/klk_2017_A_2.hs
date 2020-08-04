-- Grupa hakera je osmislila poseban algoritam za sifrovanje podataka. 
-- Podaci predstavljaju listu celih brojeva. Sifrovanje funkcionise 
-- tako sto se hakeri dogovore oko tajnog broja k pomocu koga racunaju 
-- kontrolnu cifru koja se salje nakon svakih k brojeva. Kontrolna cifra 
-- se racuna na sledeci način:
-- • ukoliko je broj k deljiv sa 2, kontrolna cifra se racuna kao zbir 
--   prethodnih k brojeva
-- • ukoliko je broj k nije deljiv sa 2, kontrolna cifra se racuna kao 
--   proizvod prethodnih k brojeva
-- Napisati funkciju:
-- sifruj lista k
-- sifruj :: [Int] -> Int -> [Int]
-- koja kao argumente dobija listu brojeva koje hakeri zele da posalju 
-- i broj k, a kao rezultat vraca listu sifrovanih podataka. Podaci se
-- sifruju tako sto se nakon svakih k brojeva salje kontrolna cifra 
-- (koja se racuna pomocu netransformisanih brojeva), a tih k brojeva se 
-- transformise tako sto se pozitivnim brojevima dodaje 1 a negativnim oduzima 1.

sifruj [] _ = []
sifruj lista 0 = lista
sifruj lista k = pocetak ++ [kont] ++ sifruj ostatak k
    where s = take k lista
          pocetak = map (\x -> if x > 0 then x+1 else x-1) s
          kont = if (mod k 2) == 0 then sum s else product s
          ostatak = drop k lista