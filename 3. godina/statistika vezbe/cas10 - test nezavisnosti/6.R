library(MASS)
# install.packages("ISLR")
library(ISLR)

# postojeca baza podataka
Boston[1:10, ]

# imena promenljivih/atributa u bazi
names(Boston)

plot(medv~lstat, Boston)

# linearni model
fit1 = lm(medv~lstat, data = Boston)
fit1 # obe promenljive su znacajne

plot(medv~lstat, Boston)
# regresiona prava
abline(fit1, col = 'blue')

# intervali poverenja za ocene nasih koeficijenata modela
confint(fit1)

# funkcija pairs() vraca sve moguce grafike rasprsenosti nase baze

fit2 = lm(medv~lstat+age, data = Boston)
summary(fit2)

# uzeli smo u obzir sve moguce promenljive iz baze
fit3 = lm(medv~., Boston)
summary(fit3)

# funkcija update(model, ...) menja model na zadati nacin
fit4  = update(fit3, ~.-age-indus)
summary(fit4)

# ako bismo zeleli da pozovemo samo za prediktor x*y,
# morali bismo da pokrenemo: lm(medv~I(lstat*age))
fit5 = lm(medv~lstat*age, Boston)
summary(fit5)

# kad stavimo I(x^2) time trazimo da x^2 posmatra 
# totalno nezavisno od x.
fit6 = lm(medv~lstat+I(lstat^2), Boston)
summary(fit6)

attach(Boston)
plot(medv~lstat)
points(lstat, fitted(fit6), col = 'blue', pch = 20)

# hocemo da probamo sa vecim stepenom
fit7 = lm(medv~poly(lstat, 4))
points(lstat, fitted(fit7), col = 'pink', pch = 20)

summary(fit7)