-- Napisati funkcije:

-- (a) trougao n
--     trougao :: Int -> [(Int,Int,Int)]
-- koja kao rezultat vraca listu trojki (x,y,z) takvih da brojevi 
-- x, y i z pripadaju intervalu od 1 do n i mogu predstavljati 
-- duzine stranica trougla.
trougao n = [(x, y, z) | x <- [1..n], y <- [1..n], z <- [1..n], x + y > z, x + z > y, y + z > x]

-- (b) raznostranicni lista
--     raznostranicni :: [(Int,Int,Int)] -> Int
-- koja kao argument prihvata listu trojki koje predstavljaju duzine 
-- stranica trouglova i vraca broj raznostranicnih trouglova.
razliciti (x, y, z) = if x /= y && x /= z && y /= z then True else False

raznostranicni [] = 0
raznostranicni (x:xs) = if razliciti x then 1 + raznostranicni xs else raznostranicni xs