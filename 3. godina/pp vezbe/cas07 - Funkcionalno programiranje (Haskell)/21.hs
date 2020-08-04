{- Podaci o cenama artikala u prodavnici su zadati u obliku liste 
   realnih brojeva. Definisati funkciju prosek lista_cena koja
   racuna prosecnu cenu artikla u prodavnici. -} 

prosek lista_cena = sum lista_cena / fromIntegral (length lista_cena)