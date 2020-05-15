-- Napisati funkciju harm n koja pravi listu prvih n
-- elemenata harmonijskog reda.

-- harm :: Int -> [Double]
harm n
    | n == 1 = [1.0]
    | otherwise = harm (n-1) ++ [recip n']
    where n' = fromIntegral n