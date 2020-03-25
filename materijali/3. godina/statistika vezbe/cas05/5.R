# U nekoj anketi od 500 ispitanika 285 se
# izjasnilo protiv. Naci 90%-tni interval
# poverenja za verovatnocu da se slucajno
# odabrana osoba izjasni protiv.

n <- 500
x_n <- 285/500
beta <- 0.9

c <- qnorm((1+beta)/2)

interval_poverenja <- c(x_n - c*sqrt(x_n*(1-x_n) / n), x_n + c*sqrt(x_n*(1-x_n) / n))
interval_poverenja