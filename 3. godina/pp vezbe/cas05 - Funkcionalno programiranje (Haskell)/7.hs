-- Napisati funkciju lista a b koja pravi listu celih brojeva
-- iz segmenta [a, b]. U slucaju da granice segmenta nisu
-- ispravne, rezultat je prazna niska.

{- Operacije:
    (:) konstrukcija liste
    (++) konkatenacija liste
    (!!) indeksiranje liste
    [a..b] raspon
-}

{- Korisne funkcije:
    head - glava liste
    tail - rep liste
    length - duzina liste
    take - uzima zadati broj elem. sa pocetka liste
    drop - izbacuje zadati broj elem. sa pocetka liste
    null - testira da li je lista prazna
    elem - elementi se porede po jednakosti (EQ)
-}

lista :: Int -> Int -> [Int]
lista a b = [a..b]