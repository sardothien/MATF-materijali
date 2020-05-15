# Dat je uzorak: 
# 4.19 2.86 3.93 4.64 6.22 1.99 3.52 4.41 3.89 4.54 3.86 1.62
# Sa nivoom znacajnosti 0.05 testirati hipotezu da ovaj uzorak
# ima medijanu jednaku medijani normalne N(2,1) raspodele.

x <- c(4.19, 2.86, 3.93, 4.64, 6.22, 1.99, 
       3.52, 4.41, 3.89, 4.54, 3.86, 1.62)

T.hat <- sum(x>2)
# P(T>=10) = 1-P(T<10) = 1-P(T<=9) =1-F(9)
p.hat <- 1-pbinom(9,12,0.5)+pbinom(2,12,0.5) 
alpha <- 0.05 

p.hat > 0.05