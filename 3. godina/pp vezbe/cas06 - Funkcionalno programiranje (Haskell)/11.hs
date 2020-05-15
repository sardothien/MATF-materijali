{- Napisati funkciju parovi a b c d koja generise
   listu parova celih brojeva (x,y), za koje x pripada
   [a, b], a y pripada [c,d]. -}

parovi :: Int -> Int -> Int -> Int -> [(Int, Int)]
parovi a b c d = [(x,y) | x <- [a..b], y <- [c..d]]