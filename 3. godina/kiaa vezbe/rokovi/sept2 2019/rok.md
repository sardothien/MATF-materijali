1. Neka je dato *N* segmenata na veritkalnoj pravoj zadatih svojim krajnjim tačkama. Konstruisati algoritam složenosti *O(nlogn)* koji određuje koordinate krajnjih tačaka segmenta koji sadrži najveći broj drugih segmenata kao i broj sadržanih segmenata. Segment sadrži drugi segment samo ako sadrži oba njegova kraja. Sa standarndnog ulaza se unosi broj *N*. U narednih *N* linija se unose po 2 broja koja predstavljaju koordinate krajnjih tačaka segmenata. Na standardni izlaz ispisati koordinate traženog segmenta u opadajućem poretku a zatim i broj segmenata koje on sadrži. Može se pretpostaviti da je traženi segment jedinstven.\\

<pre>
 Primer 1:        Primer 2:        Primer 3:
 ulaz:            ulaz:            ulaz:
 7                5                3
 12 10            10 8             100 80
 15 11            5 2              50 40
 22 10            4 3              45 42 
 18 14            7 1              izlaz:
 9 8              20 1             50 40 1
 5 1              izlaz:
 10 8             20 1 4 
 izlaz:
 22 10 3
</pre>

2. Neka je zadata niska *S*. Pronaći ukupan broj palindromskih podniski niske *S*. Sa standarnog ulaza se unosi niska *S*. Na standardni izlaz ispisati jedan broj koji predstavlja broj palindromskih podniski niske *S*.

<pre>
Primer 1:        Primer 2:        Primer 3:
ulaz:            ulaz:            ulaz:
ababa            aba              abba
izlaz:           izlaz:           izlaz:
9                4                6
**Objašnjenje primera 1:** Podniske date niske koje su palindromi su:
  a
  b 
  a 
  b
  a 
  aba 
  aba 
  bab 
  ababa
</pre>

3. Asistent KIAA-e želi studentima da da zadatke za ispit. To će uraditi kroz jednu igru. Pravila igre su sledeća: 
    
    1. Asistent kaže zadatke jednom studentu.
    2. Asistent numeriše studente i sebe rednim brojevima i određuje ko sa kim sme međusobno da komunicira.
    3. Svi studenti koji smeju da komuniciraju moraju da iskomuniciraju tačno jednom.
    4. Na kraju poslednji student mora da ponovi asistentu zadatke.
    5. Ukoliko studenti uspeju da iskomuniciraju i kažu asistentu zadatke ti zadaci ostaju za ispit, inače se smišljaju novi duplo teži zadaci.
    6. Studenti se dogovaraju i kažu asistentu da li prihvataju igru ili ne.
    
    Sa standardnog ulaza se unose brojevi *N* i *M* koji predstavlja broj studenata (asistent je uračunat), kao i broj komunikacija koje će biti određene. Nakon toga se u narednih *M* linija unose po 2 broja koja govore o tome ko sa kim sme da komunicira. Na standardni izlaz ispisati "DA" ukoliko studenti treba da prihvate, a "NE" u suprotnom.

    Može se pretpostaviti da nijedan student neće biti izuzet iz komunikacije.
    **Napomena**: Svi radovi će biti pregledani. Oni zadaci u kojima se samo ispisuje "DA" ili "NE" će biti bodovani sa 0 poena.

<pre>
 Primer 1:        Primer 2:        Primer 3:
 ulaz:            ulaz:            ulaz:
 3 3              4 4              4 4
 0 1              0 1              0 1
 1 2              1 2              1 2
 2 0              2 3              2 0
 izlaz:           3 0              2 3
 DA               izlaz:           izlaz:
                  DA               NE
</pre>
