# Neka X ima familiju N(theta, sigma^2), a apriorna raspodela je
# normalna N(mi, tau^2). Naci aposteriornu raspodelu za theta ako
# je obim uzorka n=1.

# Primer: uzorak je iz N(1,2), a apriorna je N(0,1)

n <- 50

mi <- 0
tau2 <- 1
sigma2 <- 2

ro <- n/sigma2 + 1/ tau2

x1  <- rnorm(n, 1, 2)

curve(dnorm(x), -5, 5, lwd = 2, col = "blue",
      xlab = "", ylab = "")

par(new = TRUE)

curve(dnorm(x, 1/ro * (mean(x1)*n/sigma2 + mi/tau2), 1/ro),
      -5, 5, col = "pink", ylab = "", xlab = "",
      lwd = 2, axes = FALSE)