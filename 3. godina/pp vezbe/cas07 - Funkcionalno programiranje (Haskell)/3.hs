{- Definisati tip podataka Zivotinja koji moze
   biti Pas, Macka ili Papagaj. Zatim definisati
   tip Ljubimac karakterisan imenom, godinama i 
   tipom zivotinje. -}

data Zivotinja = Pas | Macka | Papagaj

-- MkLjubimac je konstruktor 3 argumenta, svakom
-- dajemo ime koje mozemo da koristimo kao getter
data Ljubimac = MkLjubimac { ime :: String,
                             godine :: Int,
                             tip :: Zivotinja
                           }