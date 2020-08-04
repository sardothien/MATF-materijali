{- Definisati funkciju prefiks l koja odredjuje sve prefikse date
   liste l (dozvoljena je rekurzija). -}

prefiks [] = [[]]
prefiks (x:xs) = [] : map (x:) (prefiks xs)
