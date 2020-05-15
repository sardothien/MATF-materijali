# Dati su rezultati ispita. Odrediti: histogram, uzoracku sredinu,
# uzoracku disperziju, uzoracko standardno odstupanje, medijanu, 
# stablo-lisce, kvantile.

rezultati <- c(28, 27, 26, 25, 24, 23, 21, 21, 20, 19, 19, 
               18, 18, 18, 17, 17, 17, 17, 16, 16, 16, 15.5,
               15, 15, 15, 15, 14, 13, 13, 13, 13, 12, 12, 11,
               11, 11, 11, 11, 10, 10, 10, 9, 9, 8, 7, 6, 5, 4,
               0, 0, 25, 23, 21, 21, 21, 21, 20, 19.5, 19, 19, 
               18, 18, 17, 17, 17, 17, 16, 15, 15, 15, 14, 14,
               14, 13.5, 13, 13, 12, 12, 10, 10, 9, 9, 9, 9, 8,
               7, 7, 7, 7, 5, 5, 5, 5, 4, 3, 2)

# uzoracka sredina
mean(rezultati)

# uzoracka disperzija
var(rezultati)

# standardno odstupanje
sd(rezultati)

# medijana
median(rezultati)

# stablo lisce
stem(rezultati)

# kvantili
quantile(rezultati)

# histogram
n <- length(rezultati)
k <- floor(log(n, base = 2)) + 1
d <- diff(range(rezultati)) / k
podela <- sort(rezultati)[1] + 0:k * d
hist(rezultati, breaks = podela, 
     main = "Rezultati", 
     probability = TRUE,
     ylim = c(0, 0.07))

curve(dnorm(x, mean = mean(rezultati), sd = sd(rezultati)), 
      lwd = 2, col = "red", add = TRUE)