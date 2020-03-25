# Aproksimacija verovatnoca na osnovu uzorka

# U ~ U(0, 1)
n <- 10^5
u <- runif(n)
mean(u <= 0.3) # P{U <= 0.3}
mean(u == 1) # P{U = 1}
mean(u > 0.4) # P{U > 0.4}
# Tacnije - P{U > 0.4} = 1 - P{U <= 0.4}
1 - punif(0.4)

# X ~ N(0, 10)
x <- rnorm(n, sd = sqrt(10))
mean(x <= 0) # P{X <= 0}
pnorm(0, sd = sqrt(10))

# Z ~ Pois(3)
z <- rpois(n, lambda = 3)
mean(z == 2) # P{Z = 2}
# Tacna vrednost:
dpois(2, lambda = 3)