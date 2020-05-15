# Ako su dati sledeci podaci u tabeli 
#         peugeot  opel  renault   suma_j
#  M        30      30      5        65  
#  Z        20      10      5        35
# suma_i    50      40      10      100
# testirati da li izbor marke automobila zavisi 
# od pola sa pragom znacajnosti alfa=0.01.

alfa = 0.01
c = qchisq(1-alfa, 2)

podaci = c(30, 30, 5, 20, 10, 5)
podaci = matrix(podaci, ncol = 3, byrow = TRUE)

p_redovi = apply(podaci, FUN = sum, MARGIN = 1) / 100
p_kolone = apply(podaci, FUN = sum, MARGIN = 2) / 100

vrednosti = expand.grid(p_redovi, p_kolone)

vrednosti = vrednosti[1] * vrednosti[2]
vrednosti = matrix(vrednosti[[1]], ncol = 3) * 100

test_statistika = sum((podaci - vrednosti)^2 / vrednosti)

test_statistika > c
# False -> prihvatamo H0