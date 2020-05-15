{- Napisati funkciju sufiksi l koja pravi listu svih
   sufiksa proizvoljne liste l. -}

sufiksi :: [a] -> [[a]]
sufiksi [] = [[]]
sufiksi (x:xs) = (x:xs) : sufiksi xs