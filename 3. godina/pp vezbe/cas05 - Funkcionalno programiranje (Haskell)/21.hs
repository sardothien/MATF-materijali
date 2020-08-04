{- Napisati funkciju parni n koja pravi listu prvih n parnih
   prirodnih brojeva. Pretpostaviti da je argument ispravan. -}

parni n = [y | y <- [1..2*n], mod y 2 == 0]