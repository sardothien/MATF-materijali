# Istrazivac procenjuje procenat gojaznih osoba
# sa visokim krvnim pritiskom. Od 25 ispitanika
# 20 ima visok pritisak. Naci 95%-tni interval
# poverenja za parametar p koji predstavlja
# verovatnocu da gojazna osoba ima visok pritisak.

n <- 25
x_n <- 20/25
beta <- 0.95

c <- qnorm((1+beta)/2)

interval_poverenja <- c(x_n - c*sqrt(x_n*(1-x_n) / n), x_n + c*sqrt(x_n*(1-x_n) / n))
interval_poverenja