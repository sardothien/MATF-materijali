/* Pekara Kiflica proizvodi hleb i kifle. Za mesanje hleba potrebno je
   10 minuta, dok je za kiflu potrebno 12 minuta. Vreme potrebno za 
   pecenje cemo zanemariti. Testo za hleb sadrzi 300g brasna, a testo za
   kiflu sadrzi 120g brasna. Zarada koja se ostvari prilikom prodaje jednog
   hleba je 7 dinara, a prilikom prodaje jedne kifle je 9 dinara. Ukoliko 
   pekara ima 20 radnih sati za mesanje peciva i 20kg brasna, koliko komada
   hleba i kifli treba da se umesi kako bi se ostvarila maksimalna zarada 
   (pod pretpostavkom da ce pekara sve prodati)? */

/* Ogranicenja:
    * 20kg brasna: 
            H <= 20,000 / 300 ~ 66.67
            K <= 20,000 / 120 ~ 166.67
    * 20h:
            H <= 1200 / 10 = 120
            K <= 1200 / 12 = 100

    => optimalna gornja granica: H = 66, K = 100            
*/

pekara(Vars) :- Vars = [H, K],
                H :: 0..66,
                K :: 0..100,
                10*H + 12*K #=< 1200,
                300*H + 120*K #=< 20000,
                labeling([maximize(7*H+9*K)], Vars),
                Zarada is 7*H+9*K,
                write('Maksimalna zarada je: '), write(Zarada), nl,
                write('Hleba: '), write(H), nl,
                write('Kifli: '), write(K), nl.