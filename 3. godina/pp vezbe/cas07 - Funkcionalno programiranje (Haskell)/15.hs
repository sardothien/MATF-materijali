{- U toku su prijave za plesno takmicenje parova. Pored nagrade za najbolji par,
   dodeljuju se i pojedinacne nagrade za najboljeg zenskog i muskog takmicara. 
   Da bi ziri jednostavnije belezio poene i odredio nagrade, potrebno je da im 
   se dostave, pored liste parova koji se takmice, i liste samo muskih, tj. samo 
   zenskih takmicara, odvojeno. Napisati funkciju listaUPar lista koja pretvara 
   listu parova u par dve liste, tako da prva lista sadrzi prve elemente svih parova, 
   a druga druge elemente svih parova pod pretpostavkom da je prvi u paru uvek zenska
   osoba, a drugi muska (implementacija funkcije unzip). -}

listaUPar :: [(a,b)] -> ([a], [b])
listaUPar [] = ([], [])
listaUPar lista = foldr (\(a,b) (c,d) -> (a:c, b:d)) ([], []) lista