-- Napisati funkciju delioci n koja pravi listu svih
-- pravih delioca pozitivnog broja n.

delioci n
    | n == 1 = [1]
    | otherwise = delioci' n 2
    where delioci' n k
            | k == n = []
            | mod n k == 0 = [k] ++ (delioci' n (k+1))
            | otherwise = delioci' n (k+1)