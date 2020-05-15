-- Napisati funkciju nadovezi l1 l2 n koja nadovezuje 
-- na listu l1 n puta l2.

nadovezi :: [a] -> [a] -> Int -> [a]
nadovezi l1 l2 n = l1 ++ rep
    where rep = concat $ replicate n l2