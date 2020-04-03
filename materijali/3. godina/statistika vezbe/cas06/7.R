# Izvrseno je istrazivanje da li je cena artikala u 
# jednom hipermarketu veca od cene u drugom i slucajno
# je odabrano 20 artikala i belezene su njihove razlike
# u supermarketima i dobijene su sledece vrednosti:
# D=0.045 - srednja vrednost RAZLIKA u ceni,
# S_D^2=0.0084 - ocenjena disperzija razlika u ceni.
# Sa nivoom znacajnosti testa alfa = 0.05 ispitati da li
# su cene u prvom hipermarketu znacajno vece od cena u drugom.

# H0: d = 0
# H1: d > 0

t_kapa = 0.045 / sqrt(0.0084) * sqrt(20)
c = qt(1-alfa, 19)
t_kapa > c
# TRUE => odbacujemo H0