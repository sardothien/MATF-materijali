{- Napisati funkciju izbaci k l koja izbacuje k-ti
   element iz liste l. U slucaju da je zadata neispravna
   pozicija u listi, funkcija vraca nepromenjenu listu. -}

izbaci :: Int -> [a] -> [a]
izbaci _ [] = []
izbaci k lista = foldr (\(i,x) acc -> if i == k then acc else x : acc) [] $ zip [0..] lista

-- drugi nacin
izbaci' _ [] = []
izbaci' 0 (_:xs) = xs
izbaci' k (x:xs) = x : (izbaci' (k-1) xs)