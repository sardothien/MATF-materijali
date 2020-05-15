{- Napisati funkcije glava i rep koje bezbedno vracaju
   glavu i rep liste koristeci tip Either. U slucaju da 
   je lista prazna, vrati String sa porukom o gresci. -}

-- data Either a b = Left a | Right b

glava :: [a] -> Either String a
glava [] = Left "Prazna lista"
glava (x:_) = Right x

rep :: [a] -> Either String [a]
rep [] = Left "Prazna lista"
rep (_:xs) = Right xs