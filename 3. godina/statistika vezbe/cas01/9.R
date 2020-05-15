# Za obelezje "brzina" iz date baze naci uzoracku sredinu i disperziju,
# medijanu i kvantile, a zatim nacrtati grafik empirijske funkcije
# raspodele i histogram podataka. Doneti neke zakljucke o raspodeli.

data("cars")
# cars

# uzoracka sredina
mean(cars$speed)

# uzoracka disperzija
var(cars$speed)

# medijana
median(cars$speed)

# kvantili
quantile(cars$speed)

# grafik empirijske funkcije raspodele
Fn <- ecdf(cars$speed)
plot(Fn, main = "Empirijska funkcija raspodele")

# histogram
n <- length(cars$speed)
k <- floor(log(n, base = 2)) + 1
d <- diff(range(cars$speed)) / k
podele <- sort(cars$speed)[1] + 0:k * d
hist(cars$speed, breaks = podele, main = "Brzine",
     probability = TRUE,
     ylim = c(0, 0.08))
curve(dnorm(x, mean = mean(cars$speed), sd = sd(cars$speed)),
      lwd = 2, col = "red", add = TRUE)