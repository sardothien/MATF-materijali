# Metoda inverzne transformacije

# Uniformna raspodela na intervalu (a,b)
unif <- function(a,b){
  U <- runif(1)
  a + (b-1)*U
}

######################################################################

# Eksponencijalna raspodela
eksp <- function(lambda){ 
  U <- runif(1)
  -1 / lambda * log(1-U) # moze i log(U)
}

uzorak <- replicate(1000, eksp(3))
mean(uzorak) # ocekivanje
var(uzorak) # disperzija

# histogram verovatnoca:
library(lattice)
hist(uzorak, prob = TRUE, xlab = "", ylab ="",
     col = "coral1", border = "bisque", main = "Exp(3)")
curve(dexp(x, rate = 3), add = TRUE, lwd = 3, col = "cornflowerblue")

# P{X > 2}
mean(uzorak > 2)
# stvarna vrednost: 1 - P{X <= 2}
1 - pexp(2, rate = 3)

######################################################################

# Gama raspodela kao zbir nezavisnih eksponencijalnih
gama <- function(n, lambda){
  r <- replicate(n, eksp(lambda))
  sum(r)
}

uzorak <- replicate(1000, gama(10, 0.5))
hist(uzorak, prob = TRUE, xlab = "", ylab = "",
     col = "coral1", border = "bisque",
     main = "Gama(10, 0.5)", ylim = c(0, 0.07))
curve(dgamma(x, rate = 0.5, shape = 10), add = TRUE,
      lwd = 3, col = "cornflowerblue")

mean(uzorak)
var(uzorak)