{- Napisati funkciju sumaKvadrata n koja racuna sumu kvadrata 
   prvih n prirodnih brojeva (rekurzivno, bez koriscenja formule). -}

sumaKvadrata n 
    | n < 0 = 0
    | n == 1 = 1
    | otherwise = (n*n) + sumaKvadrata (n-1)