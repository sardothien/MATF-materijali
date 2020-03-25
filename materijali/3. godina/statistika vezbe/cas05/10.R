# Izvrseno je ispitivanje 250 ljudi i dobijena
# ocena za p je 0.45. Isto istrazivanje je
# ponovljeno za 1000 ljudi i dobijena je ista 
# ocena. Naci 95%-tni interval povjerenja u oba
# slucaja. Koliko je puta drugi interval manji od
# prvog. Koliko veliko treba da bude n u 
# istrazivanju da bi 95%-tni interval bio duzine
# ne vece od 0.01?

n1 <- 250
n2 <- 1000
x_n <- 0.45
beta <- 0.95

c <- qnorm((1+beta)/2)

# duzina intervala poverenja
d <- function(n, x_n = 0.45){
  2 * sqrt(x_n * (1-x_n) / n) * c
}

# odnos duzina
d(n1) / d(n2)

n3 <- ceiling(4 * c^2 * x_n*(1-x_n) / (0.01)^2)
n3

d(n3)
d(n3) <= 0.01