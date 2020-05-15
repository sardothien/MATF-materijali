# Neka je X iz familije Bernulijevih raspodela sa parametrom teta
# i neka je apriorna raspodela za teta ~ beta(2,3). Naci aposteriornu 
# raspodelu za teta.

# grafik apriorne i aposteriorne gustine
gf <- function(theta, a, b, n){
  
  # uzorak iz Ber(theta) raspodele
  x1 <- sample(c(0, 1), n, replace = TRUE, 
               prob = c(1-theta, theta))
  
  # apriorna gustina
  curve(dbeta(x, a, b), 0, 1, lwd = 2, 
        col = "blue", ylab = "", xlab = "")
  
  par(new = TRUE)
  
  # aposteriorna gustina
  curve(dbeta(x, sum(x1)+a, n-sum(x1)+b), 0, 1,
        lwd = 2, col = "pink", ylab = "", xlab = "",
        axes = FALSE)
}

# primer za theta = 0.5
gf(0.5, 2, 3, 100)

# primer za theta = 0.1
gf(0.1, 2, 3, 100)

# Cesto se desava da ako imamo veliki broj podataka, izbor 
# apriorne ocene ne utice mnogo da zakljucak o raspodeli parametra.

gf(0.4, 3, 4, 1000)
par(new = TRUE)
gf(0.4, 2.5, 3.5, 1000)
par(new = TRUE)
gf(0.4, 103, 104, 1000)