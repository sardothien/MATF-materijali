{- Kasirka Mica mora da rucno kuca artikle na kasi jer se pokvario 
   skener barkodova. Pomozite Mici da taj posao obavi sto brze 
   grupisanjem artikala iste vrste na pokretnoj traci. Napisati 
   funkciju podlistePonavljanja l koja grupise sva uzastopna 
   ponavljanja nekog elementa liste l u podlistu tako da rezultat 
   bude lista listi. -}

podlistePonavljanja :: Eq a => [a] -> [[a]]
podlistePonavljanja [] = []
podlistePonavljanja (x:xs) = (x : (takeWhile (==x) xs)) : podlistePonavljanja (dropWhile (==x) xs)