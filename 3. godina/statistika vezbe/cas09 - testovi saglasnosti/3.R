# Ispitati, sa pragom znacajnosti 0.05, da li je 
# uzorak 0.3, 0.7, 0.9, 1.2, 1.4, 1.5, 1.6, 1.9,
# 2.0, 2.1, 2.3, 2.5, 2.6, 2.7, 3.0, 3.8, 3.9, 4.0
# iz normalne N(2,1) raspodele.

x <- c(0.3, 0.7, 0.9, 1.2, 1.4, 1.5,
       1.6, 1.9, 2.0, 2.1, 2.3, 2.5,
       2.6, 2.7, 3.0, 3.8, 3.9, 4.0)
n <- length(x)
alpha <- 0.05

F0 <- pnorm(x, mean = 2, sd = 1)
Fn <- ecdf(x)

Dn <- max(c(abs(F0 - Fn(x)), abs(F0 - c(0, Fn(x)[-n]))))

# iz tablice
c <- 0.309

Dn > c
# False -> prihvatamo H0

# Drugi nacin:
ks.test(x, "pnorm", 2, 1)
# p-value = 0.8797 > 0.05 => prihvatamo H0