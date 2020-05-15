# Dat je uzorak 1.2, 3.1, 5.1, 6.7. Ispitati da li je 
# uzorak iz Eps(0.2) raspodele.

# H0: F = F0, H1: F != F0

x <- c(1.2, 3.1, 5.1, 6.7)
n <- length(x)
alpha <- 0.05

# funkcija raspodele
F0 <- pexp(x, 0.2)
# empirijska funkcija raspodele
Fn <- ecdf(x)

# najvece apsolutno rastojanje
Dn <- max(c(abs(F0 - Fn(x)), abs(F0 - c(0, Fn(x)[-n]))))

# iz tablice
c <- 0.62394

Dn > c
# False -> prihvatamo H0

# drugi nacin:
ks.test(x, "pexp", 0.2)
# dobijamo p-value = 0.8782 > 0.05 -> prihvatamo H0