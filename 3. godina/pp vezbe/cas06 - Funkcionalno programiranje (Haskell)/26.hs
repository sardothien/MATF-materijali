{- Definisati rekurzivnu funkciju ukloniDuplikate l koja 
   pomocu funkcija iz familije fold uklanja sve duplikate
   iz liste l. -}

ukloniDuplikate lista = foldr (\a b -> a : (filter (/= a) b)) [] lista
