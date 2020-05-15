{- Milan obozava da sakuplja slicice fudbalera. Da bi jednostavnije 
   pratio koje mu slicice iz kolekcije jos uvek nedostaju, cuva ih 
   rastuce sortirane po rednom broju. Planirao je da dopuni svoju 
   kolekciju na narednoj razmeni slicica, pa za tu priliku zeli da iz 
   svoje kolekcije izbaci sve nepotrebne duplikate koje ce poneti na 
   razmenu. Napisati funkciju brisiPonavljanja l koja brise sva uzastopna 
   ponavljanja elemenata u listi l. -}

brisiPonavljanja :: Eq a => [a] -> [a]
brisiPonavljanja [] = []
brisiPonavljanja (x:xs) = x : brisiPonavljanja(dropWhile (==x) xs)