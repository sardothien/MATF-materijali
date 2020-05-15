{- Ucesnici nagradne igre Sedmica mogu proveriti dobitak putem 
   sajta, gde se dobitna kombinacija objavljuje odmah nakon 
   izvlacenja. Brojevi iz dobitne kombinacije se, radi jednostavnije 
   provere pogodaka, uvek prikazuju u rastucem redosledu. Napisati 
   funkciju qsort l koja rastuce sortira listu l algoritmom qsort. -}

qsort :: Ord a => [a] -> [a]
qsort [] = []
qsort (x:xs) = qsort manji ++ [x] ++ qsort veci
    where manji = [a | a <- xs, a <= x]
          veci = [b | b <- xs, b > x]