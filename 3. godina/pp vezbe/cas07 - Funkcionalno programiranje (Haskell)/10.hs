{- Ana uci brojanje i razlikovanje boja koristeci kutiju 
   punu jednobojnih kuglica. Ona prvo zmureci iz kutije
   izvuce odredjeni broj kuglica i poredja ih u niz u
   redosledu izvlacenja. Zatim izabere proizvoljnu boju i 
   odredi na kojoj se sve poziciji u nizu izvucenih kuglica 
   nalazi kuglica zeljene boje. Napisati funkciju 
   pozicije x l koja vraca listu pozicija elementa x u listi l. -}

pozicije :: Eq a => a -> [a] -> [Int]
pozicije x [] = []
pozicije x lista = [i | (x1, i) <- zip lista [0..n], x == x1]
    where n = length lista - 1