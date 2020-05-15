# Neka je X iz Ber(p) raspodele. Dobijen je prost slucajan uzorak
# obima n=250. Apriorna raspodela za p je beta(2,3), a za aposteriornu
# se dobije p|x~Beta(sum(xk)+2,n-sum(xk)+3). Naci je interval prekrivanja
# za p. (beta=0.9)

# Trazimo konstante a i b takve da je P{a < theta < b | x} = beta. 
# Te kontante mozemo da biramo simetricno, odnosno:
# a = F^{-1}_{beta(sum(xk)+2,n-sum(xk)+3)}(0.05) i 
# b = F^{-1}_{beta(sum(xk)+2,n-sum(xk)+3)}(0.95).

n <- 250

# X ~ Ber(0.55)
x <- sample(c(0,1), size = n, replace = TRUE, prob = c(0.45,0.55))

b <- qbeta(0.95, sum(x)+2, n-sum(x)+3)
a <- qbeta(0.05, sum(x)+2, n-sum(x)+3)

# interval pokrivanja
interval <- c(a, b)
interval

mean(x)