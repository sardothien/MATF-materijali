# Menadzer neke firme hoce da vidi da li je za firmu
# bolje da radi od 9:30 do 17:30(a) ili od 10 do 18(b).
# Uzorak je 25 slucajno odabranih dana kada je firma 
# radila po prvom i 25 dana po drugom rezimu i dobio je
# sledece rezultate:
# Prvi rezim: prosecna zarada je 570 (Xa), sa uzorackim
# disperzijama 1600=Sa^2
# Drugi rezim: prosecna zarada Xb=600, uzoracka 
# disperzija Sb^2=625
# Sa nivoom znacajnosti testa od 0.05 testirati da li se
# veca zarada ostvaruje u drugom rezimu rada.

# H0: m_a = m_b; o_a^2 = o_b^2
# H1: m_b > m_a; o_a^2 != o_b^2

alfa = 0.05
n1 = 25
n2 = 25

c1 = qf(0.05, n1-1, n2-1)
c2 = qf(0.95, n1-1, n2-1)

F_kapa = 1600/625
F_kapa

F_kapa < c1 | F_kapa > c2
# TRUE => odbacujemo H0 (disperzije nisu jednake)

# koristimo sl. statistiku:
Q = (1600/n1 + 625/n2) / ((1600/n1)^2 / (n1-1) + (625/n2)^2 / (n2-1))
Q

# Q ~ 45 pa se moze aproksimirati normalnom N(0,1):
c = qnorm(0.05)
t_kapa = (570-600) / sqrt(1600/n1 + 625/n2)
t_kapa < c
# TRUE => odbacujemo H0 (bolji je drugi rezim)