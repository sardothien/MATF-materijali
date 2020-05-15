# Pretpostavimo da nam je dat uzorak iz N(m,10)
# raspodele, gde je m nepoznati parametar. Testirati
# koristeci p-vrednost testa hipotezu da:
# H0: m = 2, H1: m > 2.

x = c(5.6884562,  2.0308148, -0.2508697, -2.5062107,  5.1422191,  1.1849337,  3.6343267,
  4.6528487,  1.5760364,  5.1431170,  1.8864374,  4.4475159,  3.5619849,  4.7377123,
  -1.2994996,  2.4134766,  0.2744983,  5.2431267, -0.1152874,  0.8769407,  2.1222095,
  1.8561701,  3.0470218,  0.4738757,  2.1079643,  2.5249362, -2.2613439,  1.0116844,
  2.1796532,  1.6629011,  0.6026096,  3.0568876,  0.1365397, -5.0585758,  2.3148987,
  4.0924715, -0.9189906,  7.6984261, -1.9539183,  2.7631545,  5.5492733, -1.5838495,
  -2.3246922,  0.7752239,  1.3790237, -1.1731306,  4.8165865,  2.9824243,  6.0295380,
  0.1998773,  9.0725547, -1.2977859,  1.9417684, -3.5287460,  2.5369642, -1.3349065,
  -1.7820453,  4.2251318,  2.9737008,  1.8158107)

#################################################
# PRVI NACIN
#################################################
# posto alfa nije dato, uzecemo da je alfa = 0.05
n = length(x)
x_n = mean(x)
odstupanje = sqrt(10)

t_kapa = (x_n - 2) / odstupanje * sqrt(n)

alfa = 0.05
c = qnorm(1-alfa)

t_kapa > c 
# FALSE -> mozemo da prihvatimo H0

##############################################
# DRUGI NACIN
##############################################

# install.packages("BSDA")
library(BSDA)

z.test(x, sigma.x = sqrt(10), mu = 2, alternative = "greater")
# p-vrednost = 0.7014 > 0.05 pa prihvatamo H0

# bez koriscenja funkcije z.test:
1 - pnorm(t_kapa)

###########################################
# DODATNO
###########################################
nadji_moc <- function(c, donja_granica, gornja_granica, korak){
  t = seq(donja_granica, gornja_granica, korak)
  rez = 1 - pnorm(c + (2-t)/sqrt(10) * sqrt(n))
  return (rez)
}

alfa = 0.05
c = qnorm(1-alfa)
nadji_moc(c, 2, 3.5, 0.01)
