# Broj sati ucenja
x = c(4,9, 10, 14, 4, 7, 12, 22, 1, 3, 8, 
      11, 5, 6, 10, 11, 16, 13, 13, 10)
# Rezultati testa.
y = c(390, 580, 650, 730, 410, 530, 600, 
      790, 350, 400, 590, 640,450, 520, 
      690, 690, 770,700, 730, 640)

model = lm(y~x)
summary(model)

plot(x, y)

# iz tabele - regresiona prava
a = 25.326
b = 353.165
abline(b, a, col = 'pink')

# zelimo da ovo pripada nekoj normalnoj raspodeli
reziduali = model$residuals