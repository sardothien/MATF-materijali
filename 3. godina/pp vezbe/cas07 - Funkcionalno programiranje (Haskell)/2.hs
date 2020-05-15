{- Definisati tip podataka Oblik koji moze biti
   Kvadrat, Pravougaonik, Krug ili Trougao. -}

data Oblik = Kvadrat Float -- Float je argument konstruktora
           | Pravougaonik Float Float
           | Krug Float
           | Trougao Float Float Float
           deriving Show -- Oblik pripada klasi Show