{- Napisati funkciju poslednji l koja odredjuje poslednji
   element proizvoljne liste l. -}

poslednji :: [a] -> a
poslednji lista = lista !! poz
    where poz = length lista - 1