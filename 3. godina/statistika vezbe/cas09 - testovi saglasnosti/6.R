# Baca se kockica za igru. Testirati hipotezu 
# da je kockica homogena.

# tj. da li je verovatnoca za svaki broj 1/6

# Prvo simuliramo bacanje kockice, da bismo
# dobili neki uzorak
set.seed(9)
# uzorak od 60 ishoda bacanja kockice
x <- sample(6, 60, replace = TRUE)
# x

# broj elemenata po kategorijama
M <- table(x)
# M
# svi su veci od 5 pa ne spajamo kategorije

# broj kategorija
r <- length(M)

# ocekivanje
Npk <- length(x) * 1/6
Npk

hi_0 <- sum((M-Npk) ^ 2 / Npk)
alpha <- 0.05

# kvantil X^2 raspodele
c <- qchisq(1-alpha, df = r-1)

hi_0 > c
# False -> prihvata se H0

# Drugi nacin:
chisq.test(M, p = rep(1/6, 6), correct = FALSE)
# p-value = 0.3062 > 0.05 => prihvatamo H0