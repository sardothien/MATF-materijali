-- Napisati funkcije:

-- (a) sortirana L
--     sortirana :: [Int] -> Bool
-- koja proverava da li je lista L sortirana strogo rastuce.
sortirana [x] = True
sortirana (x:y:xs) = if x >= y then False else sortirana (y:xs)

-- (b) pomeriPocetak L k
--     pomeriPocetak :: [Int] -> Int -> [Int]
-- koja cirkularno pomera elemente iz liste L na kraj sve dok 
-- broj k ne dodje na pocetak liste, ukoliko takav broj postoji
-- u listi.
pomeriPocetak [] _ = []
pomeriPocetak lista k = if elem k lista == False then lista else dropWhile (/= k) lista ++ takeWhile (/= k) lista

-- (c) cirkularnoIste L1 L2
--     cirkularnoIste :: [Int] -> [Int] -> Bool
-- koja proverava da li su liste L1 i L2, sacinjene od istih elemenata, 
-- cirkularno jednake, odnosno da li se cirkularnim pomeranjem elemenata
-- jedne liste moze dobiti druga lista. Pretpostaviti da liste nemaju duplikate.
cirkularnoIste [] [] = True
cirkularnoIste [] _ = False
cirkularnoIste _ [] = False
cirkularnoIste (x:xs) (y:ys) = if xp == (y:ys) then True else False
    where xp = pomeriPocetak (x:xs) y