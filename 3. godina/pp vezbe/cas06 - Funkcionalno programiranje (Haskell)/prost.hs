-- Ako zelimo da dozvolimo i za Int i za Integer,
-- mozemo da koristimo tipski razred Integral
prost :: Int -> Bool
-- specijalan slucaj
prost 1 = False
prost n = prostTest n 2
    where prostTest n k
            | k == n = True
            | mod n k == 0 = False
            | otherwise = prostTest n (k+1)

-- Drugi (bolji) nacin:
-- list comprehension: [ x | x <- [1..10], x > 5]
prost' :: Int -> Bool
prost' 1 = False
-- null testira listu da li je prazna
-- prost' n = null (listaDelilaca n)
-- $ nam kaze da se fja primeni na sve desno od $
prost' n = null $ listaDelilaca n
    where listaDelilaca n = [x | x <- [2..n-1], mod n x == 0]