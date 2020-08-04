-- Napisati funkcije:

-- (a) uparene A B
--     uparene :: (Int,Int) -> (Int,Int) -> Bool
-- koja ispituje da li su dve domine (A i B) lepo uparene, odnosno 
-- da li je druga cifra domine A jednaka prvoj cifri domine B.
uparene :: (Int,Int) -> (Int,Int) -> Bool
uparene (a,b) (c,d) = if b == c then True else False

-- (b) listaUparenih L
--     listaUparenih :: [(Int, Int)] -> [(Int, Int)]
-- koja kao rezultat vraca listu prvih domina iz liste L 
-- koje su dobro uparene.
listaUparenih [] = []
listaUparenih [x] = [x]
listaUparenih (x:y:xs) = if uparene x y then x : (listaUparenih (y:xs)) else [x]

-- (c) domine L
--     domine :: [(Int,Int)] -> Bool
-- koja proverava da li je lista domina dobro uredjena, 
-- odnosno da li su svake dve susedne domine dobro uparene.
domine (x:xs) = if length (listaUparenih (x:xs)) == length (x:xs) then True else False