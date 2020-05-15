x <- 0:5
ni <- c(6, 10, 14, 13, 6, 1)
n <- sum(ni)
p.hat <- sum(x*ni)/(5*n)

# ocena za P(X>=3) = 1-P(X<3) = 1-P(X<=2) =1-F(2)
1 - pbinom( 2 , 5, p.hat)