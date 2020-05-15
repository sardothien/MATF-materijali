# Na osnovu prethodnih istrazivanja prosecna starost 
# devojaka prilikom prvog sastanka bila je 14 godina. 
# Sociolozi tvrde da se to promenilo, odnosno da se ta 
# starost smanjila. Sakupljen je uzorak od 15 devojaka 
# i postavljeno im je ovo pitanje. Dobijeni su rezultati: 
# 13, 12.5, 13.5, 14.2, 11.5, 12.5, 15, 15.5, 13.5, 13, 16, 
# 15.5, 13.7, 12, 14.5. Ako je alfa=0.05 testom znakova 
# ispitati da li su sociolozi u pravu.

x <- c(13, 12.5, 13.5, 14.2, 11.5, 12.5, 15, 15.5,
       13.5, 13, 16, 15.5, 13.7, 12, 14.5)

# broj elemenata koji su veci od 14
T.hat <- sum(x>14)  
# obim uzorka 
n <- length(x) 
# p vrednost
p.hat <- pbinom(6, n, 0.5) 
alpha <- 0.05

p.hat > alpha 