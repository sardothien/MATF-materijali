q = seq(-1, 1, 0.05)
w = q^2+rnorm(length(q),0, 0.05)
# Naci regresionu pravu za w u odnosu na q.

model = lm(w~q)
summary(model)

plot(q, w)

# iz tabele
a = -0.00700 # = model$coefficients[2]
b = 0.34257  # = model$coefficients[1]

# regresiona prava
abline(b, a, col = 'pink')

# veza nije linearna

# probamo kvadratni model
model2 = lm(w~I(q) + I(q^2))
summary(model2)

plot(w~q)
points(q, fitted(model2), col = 'blue', pch = 20)