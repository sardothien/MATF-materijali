# Histogram kao ocena gustine
# Koristimo histogram iz paketa lattice

library(lattice)

# Uzorak obima 500 iz standardne normalne raspodele
x <- rnorm(500)
hist(x, probability = TRUE, xlab = "", ylab = "",
     col = "red", border = "blue", main = "N(0, 1)")
curve(dnorm(x), add = TRUE, lwd = 3, col = "green")

# Uzorak obima 1000 iz eksponencijalne raspodele sa parametrom 4
y <- rexp(1000, 4)
hist(y, probability = TRUE, xlab = "", ylab = "", 
     col = "blue", border = "red", main = "Exp(1)")
curve(dexp(x, 4), add = TRUE, lwd = 3, col = "green")

# Uzorak iz uniformne U(0, 1) raspodele obima 500
z <- runif(500)
hist(z, probability = TRUE, xlab = "", ylab = "", 
     col = "green", border = "yellow", main = "U(0, 1)")
curve(dunif(x), add = TRUE, lwd = 3, col = "blue")