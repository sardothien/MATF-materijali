import numpy as np

from numpy import linalg as LA

M1 = np.array([[10, 2, 31], [4, 45, 6], [1, 2, 3]])

# determinanta matrice
LA.det(M1)

# inverz matrice
LA.inv(M1)

# jedinicna matrica
LA.inv(M1).dot(M1)

# sopstvene vrednosti i vektori
LA.eig(M1)

eig_vals, eig_vecs = LA.eig(M1)

eig_vals

eig_vecs

# vektor
x = np.array([1, 2, 3])

# norma vektora
LA.norm(x)

LA.norm(x, ord=2)

# norma matrice
LA.norm(M1, ord=2)

LA.norm(M1, ord='fro')

# uslovljenost matrice
LA.cond(M1, p='fro')

LA.norm(M1) * LA.norm(LA.inv(M1))