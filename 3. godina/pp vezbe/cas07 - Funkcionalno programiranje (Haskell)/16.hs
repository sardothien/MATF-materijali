{- Nakon jos jedne kosarkaske sezone, potrebno je sumirati rezultate svih
   igraca. Svaki igrac ima jedinstveni redni broj, pod kojim se u bazi, u 
   listi prezimena, cuva njegovo prezime, a u listi pogodaka, ostvaren broj 
   poena u sezoni. Uparivanjem odgovarajucih podataka, napraviti za svakog 
   igraca jedinstveni par oblika (prezime, poeni). Napisati funkciju 
   parOdListi lista1 lista2 koja pravi listu parova od dve liste, liste 
   prezimena i liste pogodaka, tako da prvi element svakog para bude iz prve 
   liste, a drugi element svakog para bude iz druge liste (implementacija 
   funkcije zip). -}

parOdListi [] _ = []
parOdListi _ [] = []
parOdListi (x:xs) (y:ys) = ((x,y) : (parOdListi xs ys))