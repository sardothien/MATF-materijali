# (a) Neka je dat uzorak iz normalne raspodele
#     N(m, o^2) obima 20 za koji je izracunata
#     (popravljena) uzoracka sredina Sn^2 = 21.12.
#     Naci 99%-tni dvostrani interval poverenja
#     za nepoznati parametar o^2.

n <- 20
s_n2 <- 21.12
beta <- 0.99

c1 <- qchisq((1-beta)/2, n-1)
c2 <- qchisq((1+beta)/2, n-1)

interval_poverenja <- c((n-1)*s_n2 /c2, (n-1)*s_n2 / c1)
interval_poverenja

# (b) Naci jednostrani interval poverenja za o^2
#     na osnovu istog uzorka.

d <- qchisq(beta, n-1)
gornji_interval <- c((n-1)*s_n2 / d, Inf)
gornji_interval

f <- qchisq(1-beta, n-1)
donji_interval <- c(0, (n-1)*s_n2 / f)
donji_interval