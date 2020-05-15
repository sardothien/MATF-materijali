{- Napisati funkciju savrseni n koja pravi listu savrsenih
   brojeva manjih od n. Broj je savrsen ako je jednak sumi 
   svojih faktora, ne ukljucujuci taj broj. -}

savrseni :: Int -> [Int]
savrseni n = [x | x <- [1..n-1], sum (faktori x) == x]
    where faktori x = [i | i <- [1..x-1], mod x i == 0]