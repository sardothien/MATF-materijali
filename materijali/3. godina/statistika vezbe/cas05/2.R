# Naci 95%-tni interval poverenja za nepoznati
# parametar m ako je dat uzorak iz normalne
# N(m, 100) raspodele za koji je Xn = 118, n = 64.

n <- 64
x_n <- 118
sigma2 <- 100 # sigma^2
beta <- 0.95

c <- qnorm((1+beta)/2)

interval_poverenja <- c(x_n - c*sqrt(sigma2/n), x_n + c*sqrt(sigma2/n))
interval_poverenja