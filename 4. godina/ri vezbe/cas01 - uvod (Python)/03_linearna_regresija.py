import numpy as np

from numpy import linalg as LA

"""**1.** Rešiti sledeći sistem jednačina dat u matričnom obliku: \\
$\begin{bmatrix} 2 & 0 \\ -1 & 1 \\ 0 & 2 \end{bmatrix}$$\begin{bmatrix} x_1 \\ x_2 \end{bmatrix}$ =
$\begin{bmatrix} 2 \\ 0 \\ -2 \end{bmatrix}$
"""

# Ax = b
A = np.array([[2, 0], [-1, 1], [0, 2]])
b = np.array([2, 0, -2])

x = LA.inv(A.T.dot(A)).dot(A.T).dot(b)
x

# suma kvadrata reziduala
rss = LA.norm(b - A.dot(x))**2
rss

x, rss, rank, s = LA.lstsq(A, b, rcond=None)

x

rss

"""**2.** Odrediti koeficijente $β_0$ i $β_1$ tako da funkcija $f(x)=β_0+β_1*x$ u smislu metode najmanjih kvadrata najbolje aproksimira skup tačaka (0, 1.2), (0.5, 2.05), (1, 2.9) i (−0.5, 0.1) u ravni."""

points = [[0, 1.2], [0.5, 2.05], [1, 2.9], [-0.5, 0.1]]
x = np.array([p[0] for p in points])
y = np.array([p[1] for p in points])

v_ones = np.ones(x.shape[0])
A = np.vstack((v_ones, x)).T

beta_0, beta_1 = LA.lstsq(A, y, rcond=None)[0]
(beta_0, beta_1)

"""**3.** Odrediti koeficijente $β_0$, $β_1$ i $β_2$ tako da funkcija $f(x)=β_0+β_1*x+β_2*x^2$ u smislu metode najmanjih kvadrata najbolje aproksimira skup tačaka (0, 1.2), (0.5, 2.05), (1, 2.9) i (−0.5, 0.1) u ravni."""

points = [[0, 1.2], [0.5, 2.05], [1, 2.9], [-0.5, 0.1]]
x = np.array([p[0] for p in points])
y = np.array([p[1] for p in points])

v_ones = np.ones(x.shape[0])
A = np.vstack((v_ones, x, x*x)).T

beta_0, beta_1, beta_2 = LA.lstsq(A, y, rcond=None)[0]
(beta_0, beta_1, beta_2)

"""**4.** Odrediti koeficijente a, b i c funkcije f(x,y)=a+bx+cy tako da u smislu metode najmanjih kvadrata aproksimira skup tacaka (3, 3, −1), (5, 3, 1) i (3, 4, 2) u prostoru."""

points = [[3, 3, -1], [5, 3, 1], [3, 4, 2]]
x = np.array([p[0] for p in points])
y = np.array([p[1] for p in points])
z = np.array([p[2] for p in points])

v_ones = np.ones(x.shape[0])
A = np.vstack((v_ones, x, y)).T

a, b, c = LA.lstsq(A, z, rcond=None)[0]
(a, b, c)

"""**5.** Odrediti vrednosti koeficijenata a i b tako da funkcija f(x)=a+bsinx u smislu metode najmanjih kvadrata aproksimira skup tacaka (2, 2.6), (−1.22, −1.7), (8.32, 2.5) i (4.23, −1.6) u ravni. Dati ocenu greske. Prikazati skup tačaka i nacrtati rezultujucu funkciju."""

from matplotlib import pyplot as plt

points = [[2, 2.6], [-1.22, -1.7], [8.32, 2.5], [4.23, -1.6]]
x = np.array([p[0] for p in points])
y = np.array([p[1] for p in points])

v_ones = np.ones(x.shape[0])
A = np.vstack((v_ones, np.sin(x))).T

a, b = LA.lstsq(A, y, rcond=None)[0]
(a, b)

x_plot = np.linspace(-5, 10, 100)
y_plot = a + b * np.sin(x_plot)

plt.plot(x_plot, y_plot)
plt.plot(x, y, 'o')
plt.show()

"""**6.** U datoteci social_reach.csv se nalaze cene reklamiranja za različite demografske grupe, koje su date u hiljadama evra za 1000 pregleda. Svaka od tri kolone označava različitu platformu za reklamiranje (na primer, platforme mogu biti Facebook, Instagram ili YouTube). Svaki red označava različitu demografsku grupu, koja može npr. biti posebna država u kojoj se reklama plasira. Potrebno je odrediti iznos sredstava da se ostvari približno milion pregleda za svaku demografsku grupu, gledajući po svim platformama ukupno."""

import pandas as pd

data = pd.read_csv('social_reach.csv')
data

A = data[['web1', 'web2', 'web3']]

b = 1000 * np.ones(10)

x = LA.lstsq(A, b, rcond=None)[0]

res = pd.Series(A.dot(x))
res

plt.bar(res.index, res.values)
plt.show()