{- Napisati funkciju zbirPar n koja pravi listu parova
   (a,b) takvih da su a i b prirodni brojevi ciji je zbir n. -}

zbirPar :: Int -> [(Int, Int)]
zbirPar n = [(a,b)| a <- [1..n-1], b <- [1..n-1], a + b == n]