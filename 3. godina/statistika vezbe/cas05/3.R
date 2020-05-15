# Naci 95%-tni interval poverenja za m na osnovu
# uzorka obima n ako je X~N(m, o^2), gde je 
# o^2 nepoznato, ako je n = 25, Xn = 2.6, 
# Sn^2 = 170.36.

n <- 25
x_n <- 2.6
s_n2 <- 170.36
beta <- 0.95

c <- qt((1+beta)/2, n-1)

# mora n-1 jer radimo sa popravljenom uzorackom disperzijom
interval_poverenja <- c(x_n - c*sqrt(s_n2/(n-1)), x_n + c*sqrt(s_n2/(n-1)))
interval_poverenja