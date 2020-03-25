# Autlajeri (boxplot)
boxplot(discoveries, col = "pink")

airquality
boxplot(airquality)

# install.packages("plotly")
# library(plotly)
Ozon <- airquality$Ozone
# plot_ly(x = Ozon, type = "box")
range(Ozon, na.rm = TRUE)
median(Ozon, na.rm = TRUE)

q1 <- quantile(Ozon, na.rm = TRUE)[2]
q3 <- quantile(Ozon, na.rm = TRUE)[4]
qr <- IQR(Ozon, na.rm = TRUE)
q1
q3

q1 - 1.5 * qr # f1
q3 + 1.5 * qr # f3

q1 - 3 * qr # F1
q3 + 3 * qr # F3

max(Ozon[Ozon < q3 + 1.5 * qr], na.rm = TRUE) # a3
