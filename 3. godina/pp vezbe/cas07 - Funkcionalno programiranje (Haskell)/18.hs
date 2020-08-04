{- Aleksa i Luka zele da komuniciraju preko sifrovanih poruka 
   koje predstavljaju listom niski. Aleksa sifruje zeljene 
   podatke na sledeci nacin: ukoliko se niska koju salje sastoji
   samo od cifara, na njen pocetak i kraj dodaje karakter C, ako 
   se sastoji samo od malih slova, na njen pocetak i kraj dodaje 
   karakter S, a inace na njen pocetak i kraj dodaje karakter O. 
   Definisati sledece funkcije koje pomazu Aleksi da posalje Luki 
   sifrovanu poruku: -}

-- (a) broj s - za datu nisku s proverava da li su svi njeni karakteri cifre
cifra d = [y | y <- ['a'..'z'], y == d]
broj lista = length( filter (\d -> length (cifra d) == 0) lista ) == length lista

-- (b) mala s - za datu nisku s proverava da li su svi njeni karakteri mala slova
slovo d = [y | y <- ['0'..'9'], y == d]
veliko d = [y | y <- ['A'..'Z'], y == d]
mala lista = length (filter (\d -> length (slovo d ++ veliko d) == 0) lista) == length lista

-- (c) sifruj ls - datu listu niski ls transformise na sledeci nacin: 
--     ukoliko se niska koju salje sastoji samo od cifara, na njen pocetak i 
--     kraj dodaje karakter C, ako se sastoji samo od malih slova, na njen 
--     pocetak i kraj dodaje karakter M, a inace na njen pocetak i kraj dodaje
--     karakter O.
sifruj lista = map (sifr) lista
sifr lista
    | broj lista = 'C' : lista ++ ['C']
    | mala lista = 'M' : lista ++ ['M']
    | otherwise = 'O' : lista ++ ['O']