-- (a)
uporedi lista1 lista2
    | (length lista1) < (length lista2) = -1
    | (length lista1) == (length lista2) = 0
    | otherwise = 1

-- (b)
qsort [] = []
qsort (x:xs) = qsort manje ++ [x] ++ qsort vece
    where manje = [y | y <- xs, length (y) < length (x)]
          vece = [y | y <- xs, length (y) >= length (x)]