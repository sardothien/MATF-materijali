{- Definisati funkciju spoji lista1 lista2 koja
   pravi listu uredjenih parova tako sto spaja
   redom elemente prve liste sa elementima druge 
   liste u parove rezultujuce liste. -}

-- zip pravi listu torki od dve liste tako sto
-- spaja elemente prve liste sa elem. druge liste
spoji lista1 lista2 = zip lista1 lista2

-- krace:
spoji' = zip