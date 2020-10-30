"""
Rad sa matricama
    - numpy biblioteka
"""

import numpy as np

# jednodimenzioni niz
x = np.array([1, 2, 3])
x

# matrica
M = np.array([[1, 2, 3], [4, 5, 6]])
M

# dimenzija matrice
M.shape

x.shape

# promena dimenzije
x = x.reshape(1, 3)
x.shape

x

M.reshape(3, 2)

M.reshape(1, 6)
# nije moguce M.reshape(1, 5)

# interval
list(range(2, 5))

np.arange(2, 5)

# interval sa korakom
np.arange(2, 10, 3)

# niz elemenata koji su ravnomerno rasporedjeni
np.linspace(1, 10, 21)

# matric/niz nula
np.zeros((2, 3))

# matrica/niz jedinica
np.ones((2, 3))

# jedinicna matrica
np.eye(3)

# vektor
y = np.array([1, 2, 4])

# diagonalna matrica od vektora
np.diag(y)

# random - standardna normalna raspodela
np.random.randn(2, 3)

""" Operacije sa matricama """

M1 = np.array([[10, 2, 31], [4, 45, 6], [1, 2, 3]])
M2 = np.array([[0, 1, 2], [4, 5, 6], [7, 8, 9]])

M1

M2

# sabiranje (sabira po koordinatama)
M1 + M2

# mnozenje (po koordinatama)
M1 * M2

# mnozenje matrica
M1.dot(M2)

# transponovana matrica
M1.transpose()

# ili
M1.T

# primena f-je (po koordinatama)
np.sin(M1)

M1[M1>10]

# poredjenje (po koordinatama)
M1 == M2

# sabiranje skalarom (po koordinatama)
M1 + 2

x = np.array([1, 2, 3])
y = np.array([4, 5, 6])

# vertikalno nadovezivanje
np.vstack((x, y))

# horizontalno nadovezivanje
np.hstack((x, y))

# svaki red matrice se sabira sa vektorom
M1 + x

# mnozenje skalarom po koordinatama
3 * M

# izdvajanje druge kolone
M1[:,1]

# izdvajanje druge vrste
M1[1,:]

M1[1, 1:2]

E = np.eye(5)
E

# izdvajanje poslednje kolone
E[:, -1]

# izdvajanje sa korakom -1 
E[:,::-1]

E[-1, ::-1]