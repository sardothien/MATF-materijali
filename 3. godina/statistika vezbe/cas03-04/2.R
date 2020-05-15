n <- 100 # obim uzorka

# (a) N = 10, p = 1/2
x <- rbinom(n, 10, 0.5)
p.hat <- 1/10 * mean(x)
p.hat

# (b) Theta = 1
x <- runif(n)
theta.hat <- 2*mean(x)
theta.hat

# (c) Generisemo prvo ovu raspodelu
x <- function(p){
  u <- runif(1)
  if (u <= p/2)
    return (-1)
  else if (u > p/2 & u <= p)
    return (0)
  else
    return (1)
}

uzorak <- replicate(n, x(0.5))
p.hat <- 2/3 * (1 - mean(uzorak))
p.hat