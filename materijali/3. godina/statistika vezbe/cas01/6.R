# Tvrdi se da je prosecna minimalna cena bezolovnog benzina
# u Americi bila 1.35$. U reklamne svrhe kompanija zeli da pokaze
# kako je njihova cena niza. Da bi potkrepili svoju tvrdnju, 
# statisticari iz firme su sakupili sledece podatke na osnovu
# slucajnog uzorka. Napisati program u R-u koji racuna uzoracku 
# sredinu i medijanu, uzoracki raspon, i iscrtava histogram nad
# zadatim podacima.

cene <- c(1.22, 1.37, 1.27, 1.20, 1.42, 1.41, 1.22, 1.24,
          1.28, 1.42, 1.48, 1.32, 1.40, 1.26, 1.39, 1.45,
          1.44, 1.49, 1.47, 1.47, 1.24, 1.34, 1.27, 1.35,
          1.34, 1.45, 1.49, 1.45, 1.23, 1.20, 1.42, 1.34,
          1.43, 1.21, 1.49, 1.36, 1.24, 1.20, 1.45,
          1.23, 1.25, 1.24, 1.35, 1.23, 1.39, 1.38,
          1.46, 1.48, 1.26, 1.36, 1.22, 1.46, 1.39,
          1.22, 1.29, 1.47, 1.24, 1.35, 1.21, 1.21)

# uzoracka sredina
mean(cene)

# medijana
median(cene)

# uzoracki raspon
range(cene)
diff(range(cene))

# histogram
n <- length(cene)
k <- floor(log(n, base = 2)) + 1
d <- diff(range(cene)) / k
podela <- sort(cene)[1] + 0:k * d
hist(cene, breaks = podela, main = "Histogram")