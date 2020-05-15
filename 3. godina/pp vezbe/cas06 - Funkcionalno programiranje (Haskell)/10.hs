{- Napisati funkciju parni a b koja generise listu parnih
   celih brojeva iz segmenta [a,b] i funkciju neparni a b
   koja generise listu neparnih celih brojeva iz [a,b]. -}

parni :: Int -> Int -> [Int]
parni a b = [x | x <- [a..b], even x]

neparni :: Int -> Int -> [Int]
neparni a b = [x | x <- [a..b], odd x]