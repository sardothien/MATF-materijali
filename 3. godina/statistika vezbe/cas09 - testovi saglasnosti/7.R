# Dat je uzorak:
#  [0,1] (1,2] (2,3] (3,4]
#    23    26   23    28
# Sa pragom znacajnosti alfa = 0.02 
# testirati hipotezu da X ima U[0,4]
# raspodelu. Naci p-vrednost testa.

M <- c(23, 26, 23, 28)
r <- 4
n <- sum(M)
np <- 1/4 * n

hi_0 <- sum((M - np)^2 / np)

alpha <- 0.02
c <- qchisq(1-alpha, r-1)

hi_0 > c
# False -> prihvatamo H0
  
p <- 1 - pchisq(hi_0, r-1)
p < alpha
# False -> prihvatamo H0