{- Napisati funkciju magicniParovi l koja pravi listu parova ciji su 
   prvi elementi, elementi liste prirodnih brojeva l, a drugi elementi 
   odgovarajuci magicni brojevi elemenata liste l. Magican broj prirodnog 
   broja n se dobija kao proizvod njegovih cifara. -}
proizvod n = if n < 1 then 1 else (mod n 10) * proizvod (div n 10)

magicniParovi lista = [(x, proizvod x) | x <- lista]