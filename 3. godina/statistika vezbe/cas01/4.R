# Neka je X ~ Exp(a). Generisati uzorke iz sledecih 
# raspodela i izracunati srednju vrednost.
# a) Y = |1 - X|
# b) Z = min{X, X^2}
# c) T = [X]

# (a)
simulacija_a <- function(n, a){
  x = rexp(n, a)
  y = abs(1-x)
  return(y)
}

vr_a = simulacija_a(10000, 2)
mean(vr_a)

# (b)
simulacija_b <- function(n, a){
  x = rexp(n, a)
  y = pmin(x, x^2)
  return(y)
}

vr_b = simulacija_b(10000, 2)
mean(vr_b)

# (c)
simulacija_c <- function(n, a){
  x <- rexp(n, a)
  y <- floor(x)
  return(y)
}

vr_c = simulacija_c(10000, 2)
mean(vr_c)