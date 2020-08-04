{- Definisati funkciju sufiks l pomocu funkcije scanr koja 
   odredjuje sve sufikse date liste. -}

sufiks lista = scanr (:) [] lista
