{- Napisati funkciju fib n koja racuna n-ti element Fibonacijevog
   niza. Pretpostaviti da je argument ispravan. -}

fib n 
    | (n == 1) || (n == 2) = 1
    | otherwise = fib(n-1) + fib(n-2)