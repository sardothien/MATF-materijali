# Prodavac smatra da, ako je prosecna zarada 2$
# po osobi, ostvaruje se dobar profit i da treba
# otvoriti prodavnicu. Profit ima normalnu 
# N(m,(1.7)^2) raspodelu. Prodavac je uzeo uzorak
# od 25 slucajno odabranih osoba i dobio prosecnu
# vrednost profita 2.842$. Ako je alfa = 0.05,
# da li se na osnovu dobijenog rezultata moze
# zakljuciti da treba otvoriti prodavnicu? 
# Sta je ovde H0, a sta H1?

# H0: m = 2, H1: m > 2

alfa = 0.05
c = qnorm(1-alfa)

# svi podaci su dati u tekstu
(2.842 - 2) / 1.7 * 5 > c
# TRUE => odbaujemo H0