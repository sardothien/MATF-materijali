library(ISLR)

baza <- Smarket
# imena argumenata baze
names(baza)

attach(baza)

# prvih 10 vrednosti argumenta Direction
Direction[1:10]

# model logisticke regresije
model <- glm(Direction ~ Lag1+Lag2+Lag3+Lag4+Lag5+Volume, family = binomial)
summary(model)

# fitovane vrednosti
model.p <- fitted(model)
model.klasa <- ifelse(model.p >= 0.5, "Up", "Down")

# koliko procenata je pogodilo klasu:
mean(model.klasa == Direction) # 0.5216

# Sada hocemo da pravimo model na osnovu poduzorka iz 
# date baze, odnosno izdvojicemo one podatke do 2005 
# godine i na osnovu njih napraviti model (trening skup), a
# potom predvidjati vrednosti na osnovu preostalog uzorka (test skup)

uzorak1 <- Year < 2005 # trening skup

# pravimo model na osnovu trening skupa
model1 <- glm(Direction ~ Lag1+Lag2+Lag3+Lag4+Lag5+Volume,
              data = Smarket, family = binomial,
              subset = uzorak1)
summary(model1)

# previdjanje na osnovu test skupa (Year > 2005)
model1.p <- predict(model1, newdata = Smarket[!uzorak1, ], type = "response")
model1.klasa <- ifelse(model1.p >= 0.5, "Up", "Down")

# koliko je model pogodio:
# vrednosti koje odgovaraju test skupu
Direction.2005 <- Direction[!uzorak1]
table(model1.klasa, Direction.2005)

mean(model1.klasa == Direction.2005) # 0.4801587

# model2 sa manje prediktora
model2 <- glm(Direction ~ Lag1+Lag2, data = Smarket, 
              family = binomial, subset = uzorak1)
summary(model2)

model2.p <- predict(model2, newdata = Smarket[!uzorak1, ], type = "response")
model2.klasa <- ifelse(model2.p >= 0.5, "Up", "Down")

# uspesnost modela2
table(model2.klasa, Direction.2005)
mean(model2.klasa == Direction.2005) # 0.5595238