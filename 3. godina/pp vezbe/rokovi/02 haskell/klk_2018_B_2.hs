-- (a)
manji lista = if length (filter (==0) lista) > length (filter (==1) lista) then 1 else 0

poz [] _ _ = []
poz lista x i = if head lista == x then [i] ++ poz (tail lista) x (i+1) else poz (tail lista) x (i+1) 

compress lista = [(manji a, poz a (manji a) 0) | a <- lista]

-- (b)
dekomp par i n 
    | i > n = []
    | elem i (snd par) = fst par : dekomp par (i+1) n
    | otherwise = abs (fst par - 1) : dekomp par (i+1) n

decompress lista n = [dekomp s 0 (n-1) | s <- lista] 