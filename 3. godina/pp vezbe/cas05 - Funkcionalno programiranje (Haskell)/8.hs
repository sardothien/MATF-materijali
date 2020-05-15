-- Napisati funkciju proizvodPrvih n koja racuna proizvod
-- prvih n prirodnih brojeva (rekurzivno).

proizvodPrvih n
    | n == 1 = n
    | otherwise = n * proizvodPrvih (n-1)