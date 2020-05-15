# Prosta linearna regresija je regresija oblika 
# Y = beta_0 + beta_1 * X
# gde se parametri beta_0, beta_1 dobijaju kao
# ocene koje minimizuju srednje kvadratno rastojanje 
# reziduala. Rezidualima zovemo eps = Y_cap - Y
# odnosno greska koju smo napravili kada smo samo 
# pomocu promenljive X i dobijenih parametara pokusali 
# da pogodimo Y.

X = runif(100)
Y = rnorm(100)

regresija = lm(Y~X)

summary(regresija)

# beta_0 je podatak iz tabele u polju
# (Intercept, Estimate)
beta_0 = coefficients(regresija)[1]
beta_0

# beta_1 -> (X, Estimate)
beta_1 = coefficients(regresija)[2]
beta_1