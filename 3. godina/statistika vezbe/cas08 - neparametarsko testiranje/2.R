# Prevoznik razmatra promenu trase putovanja koriscenjem 
# novog autoputa. Prosecno vreme putovanja na staroj trasi 
# je 4 sata. Prilikom 18 probnih voznji na novoj trasi, dobijeni
# su rezultati: 4.4, 3.9, 5.2, 4.6, 4.3, 3.6, 4.4, 5.5, 3.8, 4.7,
# 4.1, 3.8, 4.8, 4.5, 5.6, 4.1, 4.5, 4. Testirati da li je nova
# trasa bolja.

x <- c(4.4, 3.9, 5.2, 4.6, 4.3, 3.6, 4.4, 5.5, 
       3.8, 4.7, 4.1, 3.8, 4.8, 4.5, 5.6, 4.1, 4.5, 4)

# realizovana vrednost test statistike 
T.hat <- sum(x > 4)  
# p vrednost
p.hat <- pbinom(T.hat,18,1/2)  
alfa <- 0.05
p.hat > alfa
# velika vrednost, blizu 1, pa prihvatamo H0 kako god da izaberemo alpha