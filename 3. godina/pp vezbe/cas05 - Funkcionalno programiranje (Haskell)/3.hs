-- Napisati funkciju ostatak3 n koja racuna ostatak 
-- pri deljenju broja n brojem 3.

ostatak3 :: Int -> Int
ostatak3 n = mod n 3

-- Drugi nacin:
ostatak3' n = n `mod` 3