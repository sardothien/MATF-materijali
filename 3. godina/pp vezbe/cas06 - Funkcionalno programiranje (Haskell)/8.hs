{- Definisati rekuryivnu funkciju list_elem x l 
   koja proverava da li lista l sadrzi dati element x.
   Dodatno, definisati prethodnu funkciju koriscenjem
   funkcija or i map. -}

list_elem :: Eq a => a -> [a] -> Bool
list_elem x = or . map (==x)

-- krace:
list_elem' x = any (==x)