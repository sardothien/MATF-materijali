-- Napisati funkciju ceoDeo x koja racuna ceo deo
-- korena pozitivnog broja x (bez koriscenja sqrt).

ceoDeo :: (Ord a, Num a) => a -> a
ceoDeo x = ceoDeo' x 1
    where ceoDeo' x i
            | (i*i) > x = (i-1)
            | otherwise = ceoDeo' x (i+1)