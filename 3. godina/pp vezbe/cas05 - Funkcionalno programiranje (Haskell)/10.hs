-- Napisati funkciju nzd a b koja racuna nzd brojeva a i b
-- (koristiti Euklidov algoritam).

nzd a b
    | b == 0 = a
    | otherwise = nzd b (mod a b)

-- nzd' = gcd