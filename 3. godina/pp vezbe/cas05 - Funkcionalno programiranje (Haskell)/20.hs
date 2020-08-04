{- Napisati funkciju osnova x osn1 osn2 koja prebacuje broj x iz 
   osnove osn1 u osnovu osn2. Pretpostaviti da su osn1 i osn2 
   brojevi veci od 1 i manji od 10. -}

osnova x osn1 osn2 
    | (x < osn2) = x
    | otherwise = (osnova (div x osn2) osn1 osn2) * osn1 + (mod x osn2)