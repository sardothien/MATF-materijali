# Osiguravajuca kompanija tvrdi da agenti koji su prosli 
# specijalni trening imaju vise uspeha u uspostavljanju 
# odnosa sa potencijalnim klijentima. Slucajno su odbarana 
# 22 mlada agenta i od njih je 10 pohadjalo specijalni 
# trening. Dobijeni su rezultati pri ocenjivanju probnih 
# intervjua sa klijentima. Ispitati tvrdnju Vilkoksonovim 
# testom zbira rangova za alfa=0.05.

# oni koji su prosli obuku
x <- c(8.1, 7.9, 9.0, 4.3, 7.0, 9.1, 7.2, 8, 9, 3.1) 
# oni koji nisu
y <- c(9.1, 6.3, 2.5, 6.0, 0, 2, 7, 5.5, 1, 9, 9.7, 5.1) 

library(MASS)
wilcox.test(x , y, alternative = "greater")