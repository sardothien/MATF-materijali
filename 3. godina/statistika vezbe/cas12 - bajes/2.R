# Neka X ima familiju binomnih B(3,p) raspodjela. Apriorna 
# raspodela za p je: X:(0.4 0.5 
#                       0.7 0.3)
# Naci aposteriornu raspodelu za p ako je uzorak (obima 1) x=2.

x <- 2
q <- (0.7 * choose(3, 2) * 0.4^2 * (1-0.4)) / (0.7*choose(3, 2)*0.4^2*(1-0.4) + 0.3*choose(3, 2)*0.5^2*(1-0.5))
q

1-q