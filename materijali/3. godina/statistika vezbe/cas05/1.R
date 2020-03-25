# X^2 raspodela
# pomocne funkcije: rchisq, qchisq, dchisq

# kriva gustine sa 3 stepena slobode:
curve(dchisq(x, df = 3), lwd = 2, col = "pink",
      xlim = c(0, 10), xlab = "", ylab = "", main = "")

######################################################

# Studentova raspodela
# pomocne funkcije: rt, pt, qt, dt

# kriva gustine sa 50 stepeni slobode u poredjenu
# sa standardnom normalnom raspodelom
curve(dt(x, df = 50), lwd = 2, col = "blue", xlim = c(-5, 5),
      xlab = "", ylab = "", main = "")
curve(dnorm(x), lwd = 2, col = "pink", xlim = c(-5, 5),
      xlab = "", ylab = "", main = "", add = TRUE)