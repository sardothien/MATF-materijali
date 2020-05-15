{- Definisati rekurzivnu funkciju varijacije l k koja
   generise listu koja sadrzi sve varijacije sa ponavljanjem
   elemenata date liste l duzine k. -}

varijacije xs 0 = [[]]
varijacije xs n = concat (map (\x -> map (x:) ys) xs)
    where ys = varijacije xs (n-1)