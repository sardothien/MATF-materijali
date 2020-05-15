{- Napisati funkciju ubaci k n l koja ubacuje u listu l
   na poziciju k element n. U slucaju da je zadata
   neispravna pozicija u listi, dodati element n na kraj liste. -}

ubaci :: Int -> a -> [a] -> [a]
ubaci _ e [] = [e]
ubaci k e xs = foldr (\(i,x) acc -> if i == k then e : x : acc else x : acc) [] $ zip [0..] xs

-- drugi (bolji) nacin:
ubaci' 0 n lista = n : lista
ubaci' k n [] = [n]
ubaci' k n (x:xs) = x : (ubaci' (k-1) n xs)