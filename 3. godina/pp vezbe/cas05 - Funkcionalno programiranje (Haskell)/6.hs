-- Napisati funkciju parMax p koja odredjuje veci
-- element iz para realnih brojeva p.

parMax :: (Double, Double) -> Double
parMax p
    | fst p <= snd p = snd p
    | otherwise = fst p

-- Drugi nacin:
parMax' :: (Double, Double) -> Double
parMax' p = max (fst p) (snd p)

-- Treci nacin:
parMax'' :: (Double, Double) -> Double
parMax'' (l, r) = max l r 