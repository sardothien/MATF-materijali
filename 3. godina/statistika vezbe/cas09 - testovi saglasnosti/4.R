# Neka je uzorak 1.6, 0.6, 2.9, 1.7, 3.2, iz raspodele
# sa funkcijom raspodele F1,
# i uzorak 3.8, 2.1, 3.0, 2.3, 3.1, 3.5 iz raspodele
# sa funkcijom raspodele F2. Sa pragom znacajnosti 0.05 
# ispitati da li sledeca dva uzorka imaju istu raspodelu.

x <- c(1.6, 0.6, 2.9, 1.7, 3.2)
y <- c(3.8, 2.1, 3.0, 2.3, 3.1, 3.5)

ks.test(x, y)
# p-value = 0.2381 > 0.05 => prihvatamo H0