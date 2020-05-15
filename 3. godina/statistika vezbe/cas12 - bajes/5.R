# Neka su X1,X2,...,Xn iid iz geometrijske G(theta) raspodele. 
# Naci aposteriornu ocenu za theta ako je apriorna beta(a,b).

n <- 50
a <- 2
b <- 3

x1 <- rgeom(n, 0.8)+1

# apriorna gustina
curve(dbeta(x, a, b), 0, 1, lwd = 2,
      col = "blue", ylab = "", xlab = "")

par(new = TRUE)

# aposteriorna gustina
curve(dbeta(x, n+a, sum(x1)-n+b), 0, 1, lwd = 2,
      col = "pink", ylab = "", xlab = "", axes = FALSE)

theta.hat <- (n+a) / (n+a + sum(x1)-n+b)
theta.hat

abline(v = theta.hat, col = "green")