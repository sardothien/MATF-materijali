{- Napisati funkciju bezbedanRep l koja ukoliko je 
   lista l prazna vraca praznu listu, inace vraca 
   rep liste l, koristeci: a) uslovne izraze,
   b) ogradjene jednacine, c) uparivanje sablona. -}

-- (a)
bezbedanRep1 :: [a] -> [a]
bezbedanRep1 xs = if null xs then [] else tail xs

-- (b)
bezbedanRep2 :: [a] -> [a]
bezbedanRep2 xs
    | xs == [] = []
    | otherwise = tail xs

-- (c)
bezbedanRep3 :: [a] -> [a]
bezbedanRep3 [] = []
bezbedanRep3 (_:xs) = xs