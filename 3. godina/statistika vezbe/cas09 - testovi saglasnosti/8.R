# Testirati da li X ima G(1/2), za alfa=0.05.
#   1    2    3    4    5    6   >=7
#   45   30   15   6    2    2    0

M <- c(45, 30, 15, 6, 2, 2, 0)

n <- sum(M)
pk <-c(dgeom(0:5, 0.5), 1 - sum(dgeom(0:5, 0.5)))
n*pk

# spajamo poslednje 3 kolone
# zbog uslova n*pk > 5
M <- c(45, 30, 15, 6, 4)
pk <- c(pk[1:4], sum(pk[5:7]))
pk

np <- n * pk
hi_0 <- sum((M - np)^2 / np)
hi_0

alpha <- 0.05
c <- qchisq(1-alpha, 5-1)
c

hi_0 > c
# False -> prihvatamo H0