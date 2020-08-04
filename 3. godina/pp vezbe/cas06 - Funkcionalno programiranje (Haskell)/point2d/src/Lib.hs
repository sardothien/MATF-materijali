module Lib where

type Tacka = (Float, Float)

tacka :: Float -> Float -> Tacka
tacka x y = (x, y)

-- koordinatni pocetak
o :: Tacka
o = tacka 0.0 0.0

-- x :: Tacka -> Float
-- x = fst
-- y = snd

type Putanja = [Tacka]

putanja :: [Tacka] -> Putanja
putanja = id

duzinaPutanje :: Putanja -> Int
duzinaPutanje p = length p

transliraj :: Tacka -> Float -> Float -> Tacka
transliraj (x,y) xt yt = (x + xt, y + yt)
-- transliraj t xt yt = (x t + xt, y t + yt)

rastojanje :: Tacka -> Tacka -> Float
rastojanje (x1,y1) (x2,y2) =  sqrt $ (x1-x2)^2 + (y1-y2)^2

uKrugu :: Float -> [Tacka] -> [Tacka]
uKrugu radius lista = [t | t <- lista, rastojanje o t < radius]

translirajPutanju :: Putanja -> Float -> Float -> Putanja
-- map mora ovako jer u transliraj imamo 3 argumenta, a ne 2
translirajPutanju p x y = map (\t -> transliraj t x y) p

nadovezi :: Tacka -> Putanja -> Putanja
nadovezi t putanja = reverse s t : (reverse putanja) 

spojiPutanje :: Putanja -> Putanja -> Putanja
spojiPutanje = (++)

centroid :: [Tacka] -> Tacka
centroid ts = tacka prosekX prosekY
    where prosekX = prosek $ map fst ts
          prosekY = prosek $ map snd ts
          prosek lista = (sum lista) / (fromIntegral $ length lista)

kvadrantTacke :: Tacka -> Int
kvadrantTacke (x,y) 
    | x > 0 && y > 0 = 1
    | x < 0 && y > 0 = 2
    | x < 0 && y < 0 = 3
    | x > 0 && y < 0 = 4
    | otherwise  = 0

kvadrantPutanje :: Putanja -> Int
kvadrantPutanje lista = if istiKvadranti then head kvadranti else 0
    where kvadranti = map kvadrantTacke lista
          istiKvadranti = all (== head kvadranti) (tail kvadranti)

tackeUKvadrantu :: Int -> [Tacka] -> [Tacka]
tackeUKvadrantu k = filter (\t -> kvadrantTacke t == k)

tackeVanKvadranta :: Int -> [Tacka] -> [Tacka]
tackeVanKvadranta k = filter (\t -> kvadrantTacke t /= k)

maksimumi :: [Tacka] -> (Float, Float)
maksimumi lista = (maksimum $ map fst lista, maksimum $ map snd lista)
    where maksimum (x:xs) = foldl (\acc x -> if x > acc then x else acc) x xs