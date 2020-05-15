module Stud where

-- importuje samo elemIndex iz Data.List
import Data.List as List (elemIndex, sortBy)
import Data.Maybe as DM (fromJust)

-- test = print "Zdravo!"

-- algebarski tip = konstruktori (u ovom slucaju bez argumenata)
-- lici na enum ali nije
data StepenStudija = OsnovneStudije 
                   | MasterStudije 
                   | DoktorskeStudije 
                   deriving (Show, Eq) -- klase koje nasledjuje

-- StepenStudija je sada argument konstr. Kratko
data KratkiStepenStudija = Kratko StepenStudija 

-- show za KratkiStepenStudija (mi implementiramo)
instance Show KratkiStepenStudija where
    show (Kratko OsnovneStudije) = "BSc"
    show (Kratko MasterStudije) = "MSc"
    show (Kratko DoktorskeStudije) = "PhD"
    -- show (Kratko _) = "..."

-- MkStudent je konstruktor sa 4 argumenta
data Student = MkStudent { indeks :: String,
                           ime :: String,
                           prezime :: String,
                           stepen :: StepenStudija  
                         } -- deriving Show

-- nalik toString za Studenta
formatirajStudenta :: Student -> String
formatirajStudenta s = 
    let id = indeks s
        ip = (ime s) ++ " " ++ (prezime s)
        ss = show $ Kratko $ stepen s
    in id ++ " : " ++ ip ++ " : " ++ ss
    -- "81/2017 : Mina Milosevic : KratkiStepenStudija"

instance Show Student where
    -- show s = formatirajStudenta s
    show = formatirajStudenta

instance Eq Student where
    -- (==) s1 s2 = 
    s1 == s2 = (indeks s1) == (indeks s2)

-- za svakog studenta pamtimo broj poena
type Rezultat = (Student, Maybe Int)

rezultati :: [Student] -> [Rezultat]
-- mapira svakog studenta u uredjeni par (s, Nothing)
rezultati = map (\s -> (s, Nothing))

-- glava :: [a] -> Maybe a
-- glava [] = Nothing
-- glava (x:_) = Just x

poeni :: Student -> [Rezultat] -> Either String (Maybe Int)
poeni s rez = 
    case mozda_indeks of Nothing -> Left $ (indeks s) ++ " se ne nalazi u listi!"
                         (Just i) -> Right $ snd $ rez !! i
    where mozda_indeks = List.elemIndex s $ map fst rez

-- data Either a b = Left a
--                 | Right b

ponisti :: Student -> [Rezultat] -> [Rezultat]
ponisti s rez = foldr azuriraj [] rez
    where azuriraj r acc = if fst r == s then (s, Nothing) : acc
                                         else r : acc
-- ponisti s rez = foldl azuriraj [] rezultati
--     where azuriraj r acc = if fst r /= s then acc ++ [r]
--                                          else acc ++ [(s, Nothing)]

-- svakom studentu stavi Nothing
ponistiSve :: [Rezultat] -> [Rezultat]
ponistiSve = map (\r -> (fst r, Nothing))

-- filtrira rezultate samo sa datog stepena studija
studije :: StepenStudija -> [Rezultat] -> [Rezultat]
studije ss = filter (\(s, _) -> stepen s == ss)

polozeni :: [Rezultat] -> [Rezultat]
polozeni = filter (\(s, mozdaRez) -> (izvuci mozdaRez) > 50)
    where izvuci Nothing = 0
          izvuci (Just poeni) = poeni

-- upisuje novog studenta u listu rezultata
upisi :: Student -> Int -> [Rezultat] -> [Rezultat]
upisi s p rez = if elem s studenti
                then foldr azuriraj [] rez 
                else (s, Just p) : rez
    where studenti = map fst rez
          azuriraj r acc = if fst r == s then (s, Just p) : acc
                                         else r : acc

-- najboljih n po rezultatima
najboljih :: Int -> [Rezultat] -> [Int]
najboljih n rezultati = take n
                      $ List.sortBy (flip compare)
                      $ map DM.fromJust
                      $ filter (Nothing /=) 
                      $ map snd 
                      $ rezultati


-- TESTIRANJE
s1 = MkStudent "123/1234" "Mina" "Milosevic" OsnovneStudije
s2 = MkStudent "124/1234" "Mina" "Milosevic" MasterStudije
s3 = MkStudent "125/1234" "Mina" "Milosevic" OsnovneStudije
s4 = MkStudent "126/1234" "Mina" "Milosevic" DoktorskeStudije
studenti = [s1, s2, s3, s4]
rez :: [Rezultat]
rez = [(s1, Just 100), (s2, Nothing), (s3, Just 49), (s4, Just 81)]