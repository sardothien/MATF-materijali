# Farmaceutska kompanija ima dve metode za proizvodnju 
# odredjenog leka. Smatra se da je metoda A manje uspesna
# od metode B. Dat je uzorak od 12 pacijenata koji su primili
# oba tretmana. Ispitati ovu tvrdnju. 
# (veci koeficijent znaci vecu uspesnost)

A <- c(1.5, 1.4, 1.4, 1, 1.1, 0.9, 1.3, 1.2, 1.1, 0.9, 0.7, 1.8)
B <- c(2, 1.8, 0.7, 1.3, 1.2, 1.5, 1.1, 0.9, 1.5, 1.7, 0.9, 0.9)

D <- A-B
t.hat <- sum(D>0)
p.hat <- pbinom(4, 12, 0.5)
alpha <- 0.05

p.hat > alpha