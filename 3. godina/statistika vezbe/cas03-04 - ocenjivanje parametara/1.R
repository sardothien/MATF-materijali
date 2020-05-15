# Generisemo uzorak iz uniformne U[-5,0] raspodele
n <- 1000
x <- runif(n, -5, 0)

# Ocene parametra theta na osnovu uzorka x
theta1 <- (n + 1) / n * min(x)
theta2 <- 2 * mean(x)

# Hocemo da ocenimo disperzije ovih ocena
ocene <- function(n) {
  x <- runif(n, -5, 0)
  
  theta1 <- (n + 1) / n * min(x)
  theta2 <- 2 * mean(x)
  
  return (c(theta1, theta2))
}

r <- replicate(1000, ocene(100))

# Ocene ocekivanje ocena theta1 i theta2
rowMeans(r)

# Ocene disperzija
var(r[1,])
var(r[2,])

# Poredimo sa teorijskim disperzijama
n <- 100
d1 <- 1 / (n*(n+2)) * (-5)^2
d2 <- 1 / (3*n) * (-5)^2
d1
d2

# Vektor r predstavlja uzorak ocena. Ako hocemo
# da imamo neku sliku o raspodelama tih ocena
# mozemo da nacrtamo njihov histogram
theta1.uzorak <- r[1,]
theta2.uzorak <- r[2,]

library(lattice)
hist (theta1.uzorak, prob =TRUE, 
      xlab ="", ylab ="", 
      col ='coral1', border ='bisque', 
      main="")
hist (theta2.uzorak, prob =TRUE, 
      xlab ="", ylab ="", 
      col ='coral1', border ='bisque', 
      main="")