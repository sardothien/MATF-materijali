{- Napisati funkciju jednocifreniDelioci n koja pravi listu svih 
   jednocifrenih delilaca prirodnog broja n. Pretpostaviti da je 
   argument ispravan. -}

jednocifreniDelioci n = [y | y <- [1..9], mod n y == 0]