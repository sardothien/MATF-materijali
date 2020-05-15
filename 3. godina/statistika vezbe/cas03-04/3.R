# (a) lambda=3
x <- rpois(n, lambda = 3)
lambda.hat <- mean(x)
lambda.hat

# drugi nacin:
library(MASS)
fitdistr(x, "Poisson")

# (c)
x <- rgeom(n, prob = 0.8)
p.hat <- 1 / mean(x + 1) # korekcija zbog razlike u definiciji
p.hat

fitdistr(x, "geometric")

# treci nacin:
x <- rgamma(1000, shape = 2, rate = 0.5)
fitdistr(x, "gamma")