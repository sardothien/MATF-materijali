# Prilikom proucavanja rasta dece, posmatra se obim glave deteta pri
# rodjenju izrazeno u cm. Dobijeni su dati podaci. Napisati program u 
# R-u koji iscrtava histogram i stablo-lisce dijagram nad zadatim
# podacima.

obim <- c(33.1, 33.7, 33.7, 33.8, 33.4,
          33.9, 33.6, 33.4, 34.1, 34.2,
          34.5, 34.2, 34.6, 34.9, 34.8,
          34.0, 34.5, 34.2, 34.2, 34.7,
          34.7, 34.6, 34.3, 34.3, 34.2,
          35.1, 36.0, 35.8, 35.2, 35.6,
          36.1, 35.1, 35.3, 35.2)

n <- length(obim)
k <- floor(log(n, base = 2)) + 1
d <- diff(range(obim)) / k
podela <- sort(obim)[1] + 0:k * d
hist(obim, breaks = podela, main = "Histogram")

stem(obim)