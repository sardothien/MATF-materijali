{- Formacija igre kolo je polukrug sa istaknutom ulogom prvog i 
   poslednjeg igraca. Napisati funkciju ucesljaj mIgraci zIgraci 
   koja pravi jednu formaciju za kolo naizmenicnim ucesljavanjem 
   igraca iz date grupe muskih i zenskih igraca, mIgraci i zIgraci,
   redom. -}

ucesljaj [] lista = lista
ucesljaj lista [] = lista
ucesljaj (x:xs) (y:ys) = [x] ++ [y] ++ (ucesljaj xs ys)