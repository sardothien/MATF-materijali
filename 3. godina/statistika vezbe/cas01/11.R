# Neka je Sn = X1 +... + Xn, gde su Xi, i=1,...,n nezavisne slucajne
# velicine sa Exp(2) raspodelom. Generisati slucajnu velicinu Sn. 
# Generisati N = 1000 brojeva iz iste raspodele kao Sn i nacrtati
# njihov histogram. 

s_n <- function(n){
  x <- rexp(n, rate = 2)
  sum(x)
}

N <- 1000
n <- 100
s <- replicate(N, s_n(n))

hist(s, probability = TRUE, col = "lightblue", main = "")

# Znamo da je EX = 1/lambda, DX = 1/lambda^2
EX <- 1/2
DX <- 1/4

# Hocemo da standardizujemo podatke
s.z <- (s - n*EX) / sqrt(n*DX)
hist(s.z, prob = TRUE, col = "lightblue", main = "")
curve(dnorm(x), add = TRUE, lwd = 2, col = "coral")