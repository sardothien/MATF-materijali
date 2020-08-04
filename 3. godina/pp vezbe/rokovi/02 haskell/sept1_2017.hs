-- Napisati funkcije:

-- (a) uzastopni S
--     uzastopni :: [Char] -> [Char]
-- koja vraca nisku koja sadrzi sekvencu karaktera iste 
-- velicine sa pocetka niske S. Pretpostaviti da niska 
-- sadrzi samo velike i male karaktere.
jeMalo x = x >= 'a' && x <= 'z'
jeVeliko x = x >= 'A' && x <= 'Z'

uzastopni [] = []
uzastopni (x:xs) = if jeMalo x then takeWhile jeMalo (x:xs) else takeWhile jeVeliko (x:xs)

-- (b) sekvence S
--     sekvence :: [Char] -> [Int]
-- koja razlaze nisku S na podniske takve da svaka podniska predstavlja
-- sekvencu uzastopnih karaktera iste velicine i kao rezultat vraca listu 
-- brojeva koji redom predstavljaju duzine tih podniski.
sekvence [] = []
sekvence lista = broj : ostatak
    where broj = length(uzastopni lista)
          ostatak = sekvence (drop broj lista)

-- (c) listaSekvenci L
--     listaSekvenci :: [[Char]] -> [[Int]]
-- koja svaku nisku iz liste L razlaze na nacin opisan u delu pod b).
listaSekvenci [] = []
listaSekvenci (x:xs) = (sekvence x) : (listaSekvenci xs)