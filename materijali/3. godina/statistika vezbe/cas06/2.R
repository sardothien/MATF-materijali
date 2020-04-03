# Primer prethodnog zadatka pomocu simulacije

# Generisemo uzorak iz normalne raspodjele N(m,10) i na osnovu tog uzorka
# racunamo vrednost statistike T date u ovom zadatku
tstatistika <- function(n, m, sigma = sqrt(10)) { 
  x <- rnorm(n, m, sigma)
  (mean(x) - 2) / sigma * sqrt(n)
}

n <- 1000
# dobijamo vektor tst na osnovu kojeg donosimo zakljucke 
# o raspodeli koju ima T
tst <- replicate(n, tstatistika(n, m = 2)) 
# m=2 jer nas zanima raspodela pri uslovu H0: m=2

alpha <- 0.05
# konstanta c iz kriticne oblasti W je uzoracki 1-alpha kvantil
const <- quantile(tst, 1 - alpha)
const
# stvarna vrednost
qnorm(1-alpha)