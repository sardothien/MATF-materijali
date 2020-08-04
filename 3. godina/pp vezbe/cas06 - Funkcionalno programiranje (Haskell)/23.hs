{- Definisati funkciju delioci n koja pravi listu delilaca datog 
   prirodnog broja n koriscenjem funkcije filter. Koriscenjem 
   prethodne funkcije definisati funkciju prost n koja proverava 
   da li je dati prirodan broj n prost. Dodatno, koristeci funkcije
   prost i generisanje listi definisati funkciju prosti n koja 
   odredjuje sve proste brojeve od 1 do n. -}

-- delioci n = [x | x <- [2..n], mod n x == 0]
delioci n = filter (\d -> mod n d == 0) [2..(n-1)]

prost n = length (delioci n) == 0

prosti n = [y | y <-[2..n], prost y]
