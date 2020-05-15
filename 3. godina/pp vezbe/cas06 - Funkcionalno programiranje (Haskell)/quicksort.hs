-- qsort :: Ord a => [a] -> [a]
-- specijalan slucaj
qsort [] = []
-- (x:xs) -> x je glava, a xs rep liste
--        -> : je konstruktor liste
-- sortiramo manje od x + x + sortiramo vece od x
qsort (x:xs) = (qsort manji) ++ [x] ++ (qsort veci)
    where manji = [e | e <- xs, e < x]
          veci = [e | e <- xs, e >= x]