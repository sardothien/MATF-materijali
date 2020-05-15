# Iz serije sa nepoznatim udelom defektnih proizvoda p izvucen
# je uzorak obima n. Nema nikakvih prethodnih informacija o tom
# udelu. Naci Bajesovu ocenu udela p.

# uzmimo p = 1/2

n <- 50
x1 <- sample(c(0,1), n, replace = TRUE)

# apriorna gustina
curve(dunif(x), 0, 1, lwd = 2, col = "blue",
      xlab = "", ylab = "")

par(new = TRUE)

# aposteriorna gustina
curve(dbeta(x, sum(x1)+1, n-sum(x1)+1), 0, 1, lwd = 2,
      col = "pink", ylab = "", xlab = "", axes = FALSE)

p.hat <- (sum(x1)+1) / (sum(x1)+1 + n-sum(x1)+1)
p.hat

abline(v = p.hat, col = "green")