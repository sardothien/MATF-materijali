{- Napisati funkciju spoji l koja spaja listu listi 
   istog tipa l u jednu listu. -}

spoji :: [[a]] -> [a]
spoji [] = []
spoji lista = [x | podlista <- lista, x <- podlista]

-- drugi nacin:
spoji' [] = []
spoji' (x:xs) = x ++ spoji' xs