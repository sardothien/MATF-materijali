# Igrac baca strelicu na tablu na kojoj se nalaze tri koncentricna kruga
# poluprecnika 5, 10 i 15cm. Najveci krug je upisan u kvadrat stranice 
# 30cm. Smatra se da je svaki deo table ravnopravan.

# a) Napisati funkciju strelica() koja simulira opisanu igru.
#    (Funkcija treba da vrati 1 ako je pogodjen prvi krug, 2 za drugi i 
#    3 za treci, -1 ako je strelica van krugova)
strelica <- function(){
  # tacka (x,y) iz intervala [-15,15]x[-15,15]
  poz <- runif(2, -15, 15)
  
  # rastojanje tacke od centra
  # isto sto i sqrt(sum(poz^2)):
  r <- norm(poz, type = "2")
  
  if (r <= 5)
    return (1)
  else if (r > 5 && r <= 10)
    return (2)
  else if (r > 10 && r <= 15)
    return (3)
  else
    return (-1)
}

# b) Oceniti verovatnocu da je pogodjen 1., odnosno 2. krug.
simulacije <- replicate(1000, strelica(), simplify = "array")
table(simulacije)

frekvencije <- table(simulacije) / 1000
frekvencije

# c) Igraci A i B naizmenicno bacaju po tri strelice na tablu. 
#    Na pocetku igre imaju po 20 poena. Ako se pogodi prvi krug
#    gubi se 1 poen, drugi 3, treci 5 i van kruga 10 poena. Igru
#    zapocinje igrac A, a zavrsava se kada jedan od igraca izgubi
#    sve poene. Simulirati igru. Napisati funkciju pikado() koja
#    vraca 1 ako je pobedio igrac A, odnosno 2 ako je pobedio igrac B.
poeni <- function(x){
  krug1 <- sum(x == 1)
  krug2 <- sum(x == 2)
  krug3 <- sum(x == 3)
  kvadrat <- sum(x == -1)
  
  return (krug1 + 3*krug2 + 5*krug3 + 10*kvadrat)
}

pikado <- function(){
  poeniA <- 20
  poeniB <- 20
  
  naPotezuA <- TRUE
  
  while(poeniA * poeniB > 0){
    poeniA <- poeniA - naPotezuA * poeni(replicate(3, strelica()))
    poeniB <- poeniB - (!naPotezuA) * poeni(replicate(3, strelica()))
    
    naPotezuA <- !naPotezuA
  }
  
  ifelse(poeniA <= 0, return (2), return (1))
}

s <- replicate(1000, pikado())
mean(s == 1)
mean(s == 2)