{- Napisati funkciju zavisnoY a b koja generise listu
   parova celih brojeva (x,y) za koje x pripada [a,b],
   a y pripada [x,b]. -}

zavisnoY :: Int -> Int -> [(Int, Int)]
zavisnoY a b = [(x,y) | x <- [a..b], y <- [x..b]]