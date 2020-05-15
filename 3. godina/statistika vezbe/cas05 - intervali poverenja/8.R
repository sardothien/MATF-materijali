# Student zeli da istrazi procenat levorukih
# osoba. Ispitano je 100 ljudi i medju njima
# je samo 5 levorukih osoba. Ako nadjemo 90%-tni
# interval poverenja, da li ce on sadrzati vrednost
# 0.1? Ako ne, naci drugo beta tako da dobijeni
# interval sadrzi tu vrednost.

n <- 100
x_n <- 5/100
beta1 <- 0.9

c <- qnorm((1+beta1) / 2)

# (n+c^2)*p^2 - (c^2 + 2*Xn*n)*p + n*Xn^2 = 0
a1 <- 0.025
b1 <- 0.099
interval_poverenja <- c(a1, b1)
interval_poverenja

beta2 <- 0.91
c <- qnorm((1+beta1) / 2)
# ista jednacina
a2 <- 0.024
b2 <- 0.10001