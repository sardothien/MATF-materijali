-- Napisati funkcije:

-- (a) trougaoni n
--     trougaoni :: Int -> [(Int, Int)]
-- koja kao rezultat vraca listu parova (i,x) takvih da broj i 
-- predstavlja indeks, a broj x element na tom indeksu u sekvenci
-- prvih n trougaonih brojeva.
trougaoni :: Int -> [(Int, Int)]
trougaoni n = [(i, (i*(i+1) `div` 2)) | i <- [1..n]]

-- (b) kvadratni lista
--     kvadratni :: [(Int,Int)] -> [Int]
-- koja kao argument prihvata listu parova listu parova (i,x) takvih
-- da broj i predstavlja indeks, a broj x element na tom indeksu u 
-- listi trougaonih brojeva, i kao rezultat vraca listu kvadratnih 
-- brojeva koji se mogu generisati pomocu prosledjene liste trougaonih 
-- brojeva. Svaki kvadratni broj se racuna kao zbir dva susedna trougaona broja.
kvadratni [] = []
kvadratni [x] = []
kvadratni (x:y:xs) = (snd x) + (snd y) : kvadratni (y:xs) 