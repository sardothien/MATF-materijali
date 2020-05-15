{- Napisati funkciju broj lista koja vraca broj odredjen ciframa
   koje se nalaze u listi citajuci ih sa pocetka ka kraju liste i 
   funkciju brojObrnut lista koja vraca broj odrefjen ciframa koje 
   se nalaze u listi citajuci ih sa kraja ka pocetku liste. -}

broj [] = 0
broj (x:xs) = x*10^(length xs) + broj xs

brojObrnut :: Num a => [a] -> a
brojObrnut [] = 0
brojObrnut (x:xs) = (brojObrnut xs)*10 + x