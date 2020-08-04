{- Napisati funkciju fibLista n koja pravi listu prvih n 
   elemenata Fibonacijevog niza. Pretpostaviti da je argument 
   ispravan. -}

fib n
    | (n == 1) || (n == 2) = 1
    | otherwise = fib (n-1) + fib (n-2)

fibLista n = [fib y | y <- [1..n]]