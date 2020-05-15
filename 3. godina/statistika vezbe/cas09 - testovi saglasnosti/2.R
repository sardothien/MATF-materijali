# Dat je uzorak trenutaka otkaza masine u casovima. 
# Sa pragom znacajnosti alfa=0.01 ispitati da li 
# trenutak otkaza ima uniformnu U[0,100] raspodelu.
# uzorak:
# 0-20  |  20-40  | 40-60  | 60-80  |  80-100
#  2        8         13      17        10

x <- c(10, 30, 50, 70, 90)
n <- length(x)
alpha <- 0.01

F0 <- punif(x, min = 0, max = 100)
Fn <- 1/50 * c(1, 6, 16.5, 31.5, 45)
Fn_ <- c(0, Fn[-n])

dn <- c(abs(F0-Fn), abs(F0-Fn_))
Dn <- max(dn)

# iz tablice
c <- 0.22585

Dn > c
# True -> odbacujemo H0