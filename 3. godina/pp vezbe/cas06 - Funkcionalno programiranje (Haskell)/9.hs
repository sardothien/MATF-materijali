{- Napisati funkcije koje odredjuju glavu i rep
   proizvoljne liste bez koriscenja ugradjenih 
   funkcija za rad sa listama. -}

glava :: [a] -> a
glava (x:_) = x

rep :: [a] -> [a]
rep (_:xs) = xs