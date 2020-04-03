# Za stare teniske loptice imamo N(28, 0.25)
# raspodelu. Proizvedena je nova serija teniskih
# loptica. Da li je smanjena disperzija? Na
# osnovu uzorka od n = 25 loptica imamo:
n = 25
alfa = 0.05
# dobija se pozivanjem fje var:
s_tilda_kvadrat = 0.1497
# Postaviti hipoteze i testirati da li je 
# smanjena disperzija.

t_kapa = 24 * s_tilda_kvadrat / 0.25
c = qchisq(alfa, n-1)
t_kapa < c
# FALSE => prihvatamo H0