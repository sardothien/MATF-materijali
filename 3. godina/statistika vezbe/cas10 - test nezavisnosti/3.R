# Protok saobracaja u hiljadama automobila u toku dana
x = c(8.3, 9.3, 12.1, 12.3, 17.0, 17.3, 24.3, 24.5, 33.6) 
# A prisustva olova u kori drveca:
y = c(227, 312, 362, 521, 539, 728, 945, 1000, 1263)
# Oceniti koeficijente modela y=a*x+b.

model = lm(y ~ x)
summary(model)

plot(model)

# iz tabele
a = 41.318
b = -73.356
plot(x, y)
# regresiona prava
abline(b, a, col = 'pink')

new = 28
# predvidjanje na osnovu ovog modela za
# vrednosti x = 5, 13.3, 28, 30, 100.
predict(model, newdata = data.frame(x = c(5, 13.3, 28, 30, 100)))