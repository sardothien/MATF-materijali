# Koeficijent asimetrije i spljostenosti
# (treci i cetvrti standardizovani moment raspodele)

# install.packages("moments")
library(moments)

# koeficijent asimetrije
skewness(discoveries)
# uzoracki koeficijent asimetrije
mean(discoveries - mean(discoveries))^3 / (sd(discoveries))^3

# koeficijent spljostenosti
kurtosis(discoveries)
# ako sami racunamo:
(mean(discoveries - mean(discoveries))^4 / (var(discoveries))^2) - 3

# gustina normalne raspodele i gustina ocenjena iz ovog uzorka
plot(density((discoveries - mean(discoveries)) / sd(discoveries)),
     col = "green", main = "Gustine")
curve(dnorm(x), add = TRUE, col = "red")