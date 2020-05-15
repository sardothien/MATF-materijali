{- Napisati funkcije glava i rep koje bezbedno 
   vracaju glavu i rep liste koristeci tip Maybe. -}

-- data Maybe a = Nothing | Just a

glava :: [a] -> Maybe a
glava [] = Nothing
glava (x:_) = Just x

rep :: [a] -> Maybe [a]
rep [] = Nothing
rep (_:xs) = Just xs