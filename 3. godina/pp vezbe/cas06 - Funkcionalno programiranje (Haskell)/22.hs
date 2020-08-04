{- Definisati funkciju obrni l za obrtanje liste l 
   pomocu funkcije foldl. -}

obrni lista = foldl (flip (:)) [] lista
