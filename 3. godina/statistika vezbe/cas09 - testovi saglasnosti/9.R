# Dati su podaci:
#   [0,1]   (1,2]   (2,3]   (3,4]   (4, +Inf)
#     42      34      16      8         0
# Sa pragom znacajnosti 0.01 testirati da je 
# X iz Eps(lambda).

M <- c(42, 34, 16, 8)
n <- sum(M)

x_sr <- sum(c(0.5, 1.5, 2.5, 3.5) * M) / n
lambda.hat <- 1 / x_sr
lambda.hat

pk <- pexp(1:4, lambda.hat) - pexp(0:3, lambda.hat)
pk <- c(pk, 1-sum(pk))
pk

# dodajemo jos jednu kategoriju: (4, +Inf)
M <- c(M, 0)
np <- n * pk
np

chi_0 <- sum((M - np)^2 / np)
chi_0

alpha <- 0.01
c <- qchisq(1-alpha, 5-1-1)
c

chi_0 > c
# True -> odbacujemo H0