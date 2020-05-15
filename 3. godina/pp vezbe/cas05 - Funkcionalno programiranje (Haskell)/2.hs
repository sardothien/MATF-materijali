-- Napisati funkciju duplo n koja racuna dvostruku
-- vrednost celog broj n.

{- Pokretanje: 
    ghci
    :load 2.hs
    duplo 4
-}

duplo :: Int -> Int
duplo a = a*2

-- Drugi nacin - Karijev postupak od (*)
duplo' :: Int -> Int
duplo' = (*2)