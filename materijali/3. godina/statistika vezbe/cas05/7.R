# Naci 90%-tni i 80%-tni interval poverenja za
# nepoznati parametar p ako je u istrazivanju
# u kojem ucestvuje 100 ljudi dobijena 
# vrednost 0.45.

n <- 100
x_n <- 0.45
beta1 <- 0.9
beta2 <- 0.8

c1 <- qnorm((1+beta1) / 2)
c2 <- qnorm((1+beta2) / 2)

interval_poverenja1 <- c(x_n - c1*sqrt(x_n*(1-x_n) / n), x_n + c1*sqrt(x_n*(1-x_n) / n))
interval_poverenja1

interval_poverenja2 <- c(x_n - c2*sqrt(x_n*(1-x_n) / n), x_n + c2*sqrt(x_n*(1-x_n) / n))
interval_poverenja2