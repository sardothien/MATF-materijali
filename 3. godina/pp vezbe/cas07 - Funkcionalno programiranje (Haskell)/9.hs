{- Data je lista l koja sadrzi liste ocena raznih
   ucenika osnovne skole. Definisati funkciju
   prosekOdlicni l koja racuna prosek svih odlicnih
   ucenika. -}

prosekOdlicni :: [[Integer]] -> Float
prosekOdlicni = prosek . filter (>= 4.5) . map prosek
    where prosek xs = realToFrac (sum xs) / fromIntegral (length xs)