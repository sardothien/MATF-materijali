# Empirijska funkcija raspodele

# Primer 1
x <- rpois(20, lambda = 3)
table(x)
Fn <- ecdf(x)
plot(Fn, main = "Empirijska funkcija raspodele")

# Primer 2
x <- runif(1000)
Fn <- ecdf(x)
plot(Fn, main = "Empirijska funkcija raspodele")
curve(punif(x), from = -1, to = 2, add = TRUE, col = "red")