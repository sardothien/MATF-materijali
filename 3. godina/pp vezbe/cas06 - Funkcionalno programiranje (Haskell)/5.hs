{- Definisati funkciju sum lista koja racuna sumu 
   elemenata celobrojne liste koriscenjem fje foldr. -}

sum1 lista = foldr (+) 0 lista
sum2 lista = foldl (+) 0 lista