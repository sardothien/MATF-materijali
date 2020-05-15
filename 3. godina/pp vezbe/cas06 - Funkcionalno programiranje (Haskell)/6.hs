{- Napisati funkciju absSume lista_listi koja na osnovu
   liste listi celih brojeva pravi listu suma elemenata
   liste listi koriscenjem kompozicije funkcija za rad
   sa listama. -}

absSume lista_listi = map (abs . sum) lista_listi