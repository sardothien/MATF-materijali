-- Napisati funkciju sumaPrvih n koja racuna sumu prvih
-- n prirodnih brojeva (rekurzivno, bez koriscenja formule).

-- blokovi se moraju lepo poravnati!

-- uslovni izraz (mora da ima else granu)
sumaPrvih n = 
    if n == 0 then 0
    else n + sumaPrvih(n-1)

-- Drugi nacin (ogradjene jednacine - guards)
--  otherwise slucaj uvek ide na kraju
sumaPrvih' n
    | n == 0 = 0
    | otherwise = n + sumaPrvih'(n-1)

-- Treci nacin
sumaPrvih'' n = sum[1..n]