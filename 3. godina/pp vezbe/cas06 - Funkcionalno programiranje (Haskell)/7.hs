{- Definisati funkciju sledbenici l koja vraca listu
   sledbenika elemenata liste l koji su prirodni brojevi. -}

sledbenici lista = map (+1) (filter (>0) lista)