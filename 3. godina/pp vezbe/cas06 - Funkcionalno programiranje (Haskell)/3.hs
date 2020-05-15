{- Definisati funkciju pozitivni lista koja
   izdvaja sve pozitivne elemente iz liste. -}

-- sintaksa lambda funkcije:
--   \arg1 arg2 ... argn -> izraz

-- funkcija filter ocekuje predikat tj.
-- funkciju tipa: a -> Bool

pozitivni lista = filter (\x -> x > 0) lista

-- krace:
pozitivni' = filter (>0)