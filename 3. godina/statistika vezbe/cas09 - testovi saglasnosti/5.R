# Za  date uzorke ispitati hipotezu H0(F1=F2) 
# protiv H1(F1>F2) sa nivoom znacajnosti 0.1.
# (a)
x <- c(1.6, 0.6, 2.9, 1.7, 3.2)
y <- c(3.8, 2.1, 3.0, 2.3, 3.1, 3.5)

ks.test(x, y, alternative = "greater")
# p-value = 0.1403 > 0.1 => prihvatamo H0

# (b)
x <- c(0.04, 0.23, 0.34, 0.35, 0.51, 0.61, 0.63)
y <- c(0.02, 0.06, 0.07, 0.17, 0.4, 0.5, 0.55, 0.56, 0.73)

ks.test(x, y, alternative = "greater")
# p-value = 0.8807 > 0.1 -> prihvatamo H0