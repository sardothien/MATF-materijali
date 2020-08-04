{- Napisati funkciju brojDelilaca n koja vraca broj pravih
   delilaca prirodnog broja n. -}

brojDelilaca n
    | otherwise = br n 2
    where br n k
            | k == n = 0
            | (mod n k) == 0 = 1 + br n (k+1)
            | otherwise = br n (k+1)