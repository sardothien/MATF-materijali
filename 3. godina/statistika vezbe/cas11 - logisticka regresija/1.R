# Baza sadrzi rezultate studenata na prijemnim ispitima za upis
# na master studije (prve dve kolone), treca kolona je indikator 
# da li je dati student upisao fakultet ili nije.
baza <- read.csv("http://www.math.rs/p/files/1458635682-70-baza.txt", header=FALSE)
# baza

# attach koristimo kako ne bismo morali svaki put da pisemo
# baza.V3, baza.V2 itd., vec mozemo samo da koristimo V3, V2...
attach(baza)

plot(V3 ~ V1+V2)

# Kako izgleda model logisticke regresije za verovatnocu p
# da student upise fakultet?
# -> beta0 + beta1*V1 + beta2*V2

# Trazeni model logisticke regresije:
model <- glm(V3 ~ V1+V2, family = binomial)
summary(model)

# na osnovu dobijene tabele citamo ocene koeficijenata:
beta0 = -25.16133
beta1 = 0.20623
beta2 = 0.20147

# Ako uvrstimo uzorkom date vrednosti za V1 i V2, dobicemo
# sledece vrednosti za p na osnovu modela
V3.p <- fitted(model)
V3.klasa <- ifelse(V3.p >=0.5, 1, 0)

# koliko puta je model pogodio:
mean(V3 == V3.klasa)
# -> pogodio je u 89% slucajeva

# Preciznost modela:
d <- sum(V3 == 1 & V3.klasa == 1)
bd <- sum(V3.klasa == 1)
preciznost <- d / bd
preciznost # 0.9016393

# Dobijeni model sada koristimo za predvidjanje.
# Neka je dato: 
V1 = 20
V2 = 100
# V3 = ?

# na osnovu datih vrednosti ocenjena verovatnoca je:
p <- 1 / (1+ exp(-1*(beta0 + beta1*V1 + beta2*V2)))
p
# drugi nacin:
predict(model, newdata = data.frame(V1 = 20, V2 = 100), type = "response")

# da li ce student upisati fakultet?
predict(model, newdata = data.frame(V1 = 20, V2 = 100), type = "response") > 0.5

# matrica konfuzije
table(V3, V3.klasa)