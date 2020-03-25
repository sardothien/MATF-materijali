# Od poslednjih 10 puta kada je tost
# sendvic pao, 9 puta je pao na "ukusnu"
# stranu. Naci 80%-tni interval poverenja
# za verovatnocu p da sendvic pada na
# tu stranu.

n <- 10
x_n <- 9/10
beta <- 0.8

c <- qnorm((1+beta) / 2)

# (n+c^2)*p^2 - (c^2 + 2*Xn*n)*p + n*Xn^2 = 0
a <- 0.72
b <- 0.97
interval_poverenja <- c(a, b)
interval_poverenja