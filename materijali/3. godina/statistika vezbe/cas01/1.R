#############################
# Podsecanje iz verovatnoce #
#############################

# BINOMNA RASPODELA B(n, p)

# gustina
dbinom(0, size = 10, prob = 0.5)

# funkcija raspodele
pbinom(8, size = 10, prob = 0.3)

# kvantil (inverzna od funkcije raspodele)
qbinom(0.99, size = 10, prob = 0.5)

# generisanje slucajnih brojeva iz binomne raspodele
rbinom(20, 10, 0.5)

# crtanje verovatnoca (npr. B(50, 0.4))
x <- 0:50 # vektor od 0 do 50
#prvi nacin
plot(x, dbinom(x, size = 50, prob = 0.4), 
     main = "Binomna raspodela", 
     xlab = "k", ylab = "binomne verovatnoce")
# drugi nacin 
plot(x, dbinom(x, size = 50, prob = 0.4),
     type = "h", # h za histogram
     main = "Binomna raspodela")

# binomni koeficijenti
choose(4, 2)

####################################################

# NORMALNA RASPODELA N(m, sigma^2)

# gustina N(mean, sd^2), f(x)
dnorm(3, mean = 2, sd = 4)

# funkcija raspodele u tacki z
pnorm(0)
pnorm(3, mean = 4, lower.tail = FALSE)
pnorm(3, mean = 4, lower.tail = FALSE, log.p = TRUE)

# crtanje gustine
x <- seq(-5, 5, 0.01)
# prvi nacin
plot(x, dnorm(x), type = "l", main = "Normalna raspodela")
# drugi nacin
curve(dnorm(x), from = -5, to = 5)

# crtanje funkcije raspodele
plot(x, pnorm(x), type = "l")

# kvantili
qnorm(0.9)
qnorm(pnorm(2))

# uzorak pseudoslucajnih brojeva iz normalne raspodele
rnorm(20) # iz N(0, 1)

####################################################

# UNIFORMNA RASPODELA U[a, b]

# gustina
dunif(2)
dunif(2, min = 3, max = 5)

# funkcija raspodele
punif(1, min = 0, max = 3)

# kvantili
qunif(0.5)

# slucajni brojevi iz raspodele
runif(10) # iz U[0, 1]

####################################################

# EKSPONENCIJALNA RASPODELA EXP(lambda)

# gustina
dexp(2, rate = 2) # Exp(2), f(2)

# funkcija raspodele
pexp(qexp(0.4))

# grafik
x <- seq(0, 25, 0.01)
y <- dexp(x, rate = 3)
plot(x, y, main = "Gustina raspodele Exp(3)", ylab = "f(x)", type = "l")
