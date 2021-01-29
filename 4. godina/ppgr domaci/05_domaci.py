import numpy as np
from numpy import linalg as LA
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from mpl_toolkits import mplot3d
from mpl_toolkits.mplot3d.art3d import Poly3DCollection, Line3DCollection

# Leva slika
L1 = [815, 110, 1]
L2 = [950, 160, 1]
L3 = [989, 123, 1]
L4 = [854, 78, 1]
L5 = [790, 305, 1]
L6 = [911, 358, 1]
L7 = [950, 319, 1]
L8 = [0, 0, 1]
L9 = [321, 344, 1]
L10 = [452, 369, 1]
L11 = [510, 270, 1]
L12 = [387, 249, 1]
L13 = [364, 559, 1]
L14 = [477, 582, 1]
L15 = [526, 486, 1]
L16 = [0, 0, 1]
L17 = [136, 550, 1]
L18 = [435, 761, 1]
L19 = [814, 381, 1]
L20 = [546, 252, 1]
L21 = [175, 656, 1]
L22 = [449, 859, 1]
L23 = [806, 488, 1]
L24 = [0, 0, 1]

# -- slika od prosle godine --
# L1 = [958, 38, 1]
# L2 = [1117, 111, 1]
# L3 = [874, 285, 1]
# L4 = [707, 218, 1]
# L5 = [0, 0, 1]
# L6 = [1093, 535, 1]
# L7 = [861, 725, 1]
# L8 = [707, 647, 1]
# L9 = [292, 569, 1]
# L10 = [770, 969, 1]
# L11 = [770, 1465, 1]
# L12 = [317, 1057, 1]
# L13 = [0, 0, 1]
# L14 = [1489, 601, 1]
# L15 = [1643, 1078, 1]
# L16 = [0, 0, 1]

# Desna slika
R1 = [911, 444, 1]
R2 = [808, 561, 1]
R3 = [917, 613, 1]
R4 = [1013, 491, 1]
R5 = [0, 0, 1]
R6 = [772, 770, 1]
R7 = [864, 824, 1]
R8 = [956, 700, 1]
R9 = [297, 73, 1]
R10 = [251, 119, 1]
R11 = [371, 138, 1]
R12 = [414, 88, 1]
R13 = [0, 0, 1]
R14 = [288, 326, 1]
R15 = [395, 343, 1]
R16 = [433, 286, 1]
R17 = [0, 0, 1]
R18 = [137, 319, 1]
R19 = [524, 530, 1]
R20 = [743, 347, 1]
R21 = [0, 0, 1]
R22 = [160, 425, 1]
R23 = [529, 645, 1]
R24 = [734, 454, 1]

# -- slika od prosle godine --
# R1 = [933, 33, 1]
# R2 = [1027, 132, 1]
# R3 = [692, 223, 1]
# R4 = [595, 123, 1]
# R5 = [0, 0, 1]
# R6 = [979, 536, 1]
# R7 = [653, 642, 1]
# R8 = [569, 533, 1]
# R9 = [272, 360, 1]
# R10 = [432, 814, 1]
# R11 = [414, 1284, 1]
# R12 = [258, 818, 1]
# R13 = [1075, 271, 1]
# R14 = [1299, 699, 1]
# R15 = [1251, 1165, 1]
# R16 = [0, 0, 1]

"""***Rekonstrukcija skrivenih tacaka***"""

L8 = np.cross(np.cross(np.cross(np.cross(L5, L6), np.cross(L1, L2)), L7), 
              np.cross(np.cross(np.cross(L2, L6), np.cross(L3, L7)), L4))
L8 = L8 / L8[2]
L8 = [np.round(L8[0]), np.round(L8[1]), L8[2]]
print("L8:  ", L8)

L16 = np.cross(np.cross(np.cross(np.cross(L13, L14), np.cross(L9, L10)), L15), 
               np.cross(np.cross(np.cross(L9, L13), np.cross(L10, L14)), L12))
L16 = L16 / L16[2]
L16 = [np.round(L16[0]), np.round(L16[1]), L16[2]]
print("L16: ", L16)

L24 = np.cross(np.cross(np.cross(np.cross(L21, L22), np.cross(L19, L20)), L23), 
               np.cross(np.cross(np.cross(L17, L21), np.cross(L18, L22)), L20))
L24 = L24 / L24[2]
L24 = [np.round(L24[0]), np.round(L24[1]), L24[2]]
print("L24: ", L24)

# ----- slika od prosle godine ------
# L5 = np.cross(np.cross(np.cross(np.cross(L4, L8), np.cross(L6, L2)), L1), 
#                np.cross(np.cross(np.cross(L1, L4), np.cross(L3, L2)), L8))
# L5 = L5 / L5[2]
# L5 = [np.round(L5[0]), np.round(L5[1]), L5[2]]
# print("L5: ", L5)

# L13 = np.cross(np.cross(np.cross(np.cross(L9, L10), np.cross(L11, L12)), L14), 
#                np.cross(np.cross(np.cross(L11, L15), np.cross(L10, L14)), L9))
# L13 = L13 / L13[2]
# L13 = [np.round(L13[0]), np.round(L13[1]), L13[2]]
# print("L13: ", L13)

# L16 = np.cross(np.cross(np.cross(np.cross(L10, L14), np.cross(L11, L15)), L12), 
#                np.cross(np.cross(np.cross(L9, L10), np.cross(L11, L12)), L15))
# L16 = L16 / L16[2]
# L16 = [np.round(L16[0]), np.round(L16[1]), L16[2]]
# print("L16: ", L16)

# ------------------------------------------------------------------------------

R5 = np.cross(np.cross(np.cross(np.cross(R1, R2), np.cross(R3, R4)), R6), 
              np.cross(np.cross(np.cross(R2, R6), np.cross(R3, R7)), R1))
R5 = R5 / R5[2]
R5 = [np.round(R5[0]), np.round(R5[1]), R5[2]]
print("R5:  ", R5)

R13 = np.cross(np.cross(np.cross(np.cross(R10, R14), np.cross(R11, R15)), R9), 
              np.cross(np.cross(np.cross(R9, R10), np.cross(R11, R12)), R14))
R13 = R13 / R13[2]
R13 = [np.round(R13[0]), np.round(R13[1]), R13[2]]
print("R13: ", R13)

R17 = np.cross(np.cross(np.cross(np.cross(R19, R20), np.cross(R23, R24)), R18), 
              np.cross(np.cross(np.cross(R18, R19), np.cross(R22, R23)), R20))
R17 = R17 / R17[2]
R17 = [np.round(R17[0]), np.round(R17[1]), R17[2]]
print("R17: ", R17)

R21 = np.cross(np.cross(np.cross(np.cross(R19, R20), np.cross(R23, R24)), R22), 
              np.cross(np.cross(np.cross(R18, R19), np.cross(R22, R23)), R24))
R21 = R21 / R21[2]
R21 = [np.round(R21[0]), np.round(R21[1]), R21[2]]
print("R21: ", R21)

# ----- slika od prosle godine ------
# R5 = np.cross(np.cross(np.cross(np.cross(R4, R8), np.cross(R6, R2)), R1), 
#               np.cross(np.cross(np.cross(R1, R4), np.cross(R3, R2)), R8))
# R5 = R5 / R5[2]
# R5 = [np.round(R5[0]), np.round(R5[1]), R5[2]]
# print("R5: ", R5)

# R16 = np.cross(np.cross(np.cross(np.cross(R10, R14), np.cross(R11, R15)), R12), 
#               np.cross(np.cross(np.cross(R9, R10), np.cross(R12, R11)), R15))
# R16 = R16 / R16[2]
# R16 = [np.round(R16[0]), np.round(R16[1]), R16[2]]
# print("R16: ", R16)
# ----------------------------------------------------------------------------------------

L = [L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, L11, L12, L13, L14, L15, L16, L17, L18, L19, L20, L21, L22, L23, L24]
R = [R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15, R16, R17, R18, R19, R20, R21, R22, R23, R24]

# 8 tacaka na osnovu kojih pravimo fundamentalnu matricu FF
LL = np.array([L1, L2, L3, L4, L7, L8, L9, L11])
RR = np.array([R1, R2, R3, R4, R7, R8, R9, R11])

def oneEquation(l, r):
    x1 = l[0]
    y1 = l[1]
    z1 = l[2]

    x2 = r[0]
    y2 = r[1]
    z2 = r[2]

    return np.array([x1*x2, y1*x2, z1*x2, 
                     x1*y2, y1*y2, z1*y2, 
                     x1*z2, y1*z2, z1*z2])

# Matrica formata 8x9 - 8 jednacina dobijenih iz korespodencija
equations8 = []
for i in range(8):  
    equations8.append(oneEquation(LL[i], RR[i]))

# print("Jednacine:")
# for i in range(8):
    # print(equations[i])

# SVD dekompozicija prethodne matrice
U, S, V = LA.svd(equations8)

# Fundamentalna matrica FF
FF = np.zeros((3, 3))
V = V[:][-1]

for i in range(3):
    for j in range(3):
        FF[i][j] = V[3*i+j]

print("1. Fundamentalna matrica:")
print(FF)

# Provera da li je R.T * FF * L = 0
C = np.ones((8, 1))
for i in range(8):
    C[i][0] = round(RR[i].T.dot(FF).dot(LL[i]), 5)

# print(C.T)

print(LA.det(FF)) # treba da bude blizu 0

"""***Trazimo epipolove***"""

U, S, V = LA.svd(FF)
# print("U:\n", U)
# print("S:\n", S)
# print("V:\n", V.T)

print("e1:")
e1 = V[:][-1] # treca vrsta matrice V 
print(e1)
e1 = (1/e1[2]) * e1 # afine koordinate
print(e1)

print("\ne2:")
e2 = U.T[:][-1] # treca kolona matrice U (tj. treca vrsta od U.T)
print(e2)
e2 = (1/e2[2]) * e2 # afine koordinate
print(e2)

"""***Postizanje uslova det(FF) = 0***"""

S = np.array([[S[0], 0, 0],
              [0, S[1], 0],
              [0, 0, 0]])
print(S)

FF1 = U.dot(S).dot(V)
print(FF1)

print(LA.det(FF))
print(LA.det(FF1))
# det(FF1) < det(FF) pa cemo koristiti FF1



"""***Trijangulacija***"""

# Kanonska matrica kamere
T1 = np.array([[1, 0, 0, 0],
               [0, 1, 0, 0],
               [0, 0, 1, 0]])
print("T1:")
print(T1)

# Matrica vektorskog mnozenja
E2 = np.array([[0, -e2[2], e2[1]],
               [e2[2], 0, -e2[0]],
               [-e2[1], e2[0], 0]])
print("E2:")
print(E2)

# Matrica druge kamere
tmp = E2.dot(FF1)
T2 = np.array([[tmp[0][0], tmp[0][1], tmp[0][2], e2[0]],
               [tmp[1][0], tmp[1][1], tmp[1][2], e2[1]],
               [tmp[2][0], tmp[2][1], tmp[2][2], e2[2]]])
print("T2:")
print(T2)

# Za svaku tacku dobijamo sistem od 4 jednacine sa 4 homogene nepoznate
def equations(l, d):
    return np.array([l[1]*T1[2] - l[2]*T1[1],
                    -l[0]*T1[2] + l[2]*T1[0],
                    d[1]*T2[2] - d[2]*T2[1],
                    -d[0]*T2[2] + d[2]*T2[0]])

# Vracamo 3D koordinate
def TriD(l, r):
    U, S, V = LA.svd(equations(l, r))
    P = V[-1]
    P = P / P[3]
    return P[:-1]

reconstructed = []
for i in range(len(L)):
    reconstructed.append(TriD(L[i], R[i]))
print("--------------------")

# Mnozimo z koordinatu sa nekoliko stotina
tmp = np.eye(3)
tmp[2][2] = 400
reconstructed_400 = np.zeros((len(L),3))
for i in range(len(L)):
    reconstructed_400[i] = tmp.dot(reconstructed[i])

print(reconstructed_400)
X = reconstructed_400

# ---------------------- ISCRTAVANJE -----------------------------

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.set_xlim([200, 1500])
ax.set_ylim([200, 1500])
ax.set_zlim([200, 1500])

Z = X[:8]
verts = [[Z[0],Z[1],Z[2],Z[3]],
         [Z[4],Z[5],Z[6],Z[7]], 
         [Z[0],Z[1],Z[5],Z[4]], 
         [Z[2],Z[3],Z[7],Z[6]], 
         [Z[1],Z[2],Z[6],Z[5]],
         [Z[4],Z[7],Z[3],Z[0]]]
ax.add_collection3d(Poly3DCollection(verts, facecolors='blue', linewidths=1, edgecolors='r', alpha=.25))

Z = X[8:16]
verts = [[Z[0],Z[1],Z[2],Z[3]],
         [Z[4],Z[5],Z[6],Z[7]], 
         [Z[0],Z[1],Z[5],Z[4]], 
         [Z[2],Z[3],Z[7],Z[6]], 
         [Z[1],Z[2],Z[6],Z[5]],
         [Z[4],Z[7],Z[3],Z[0]]]
ax.add_collection3d(Poly3DCollection(verts, facecolors='green', linewidths=1, edgecolors='r', alpha=.25))

Z = X[16:24]
verts = [[Z[0],Z[1],Z[2],Z[3]],
         [Z[4],Z[5],Z[6],Z[7]], 
         [Z[0],Z[1],Z[5],Z[4]], 
         [Z[2],Z[3],Z[7],Z[6]], 
         [Z[1],Z[2],Z[6],Z[5]],
         [Z[4],Z[7],Z[3],Z[0]]]
ax.add_collection3d(Poly3DCollection(verts, facecolors='yellow', linewidths=1, edgecolors='r', alpha=.25))


ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')
    
plt.gca().invert_yaxis()
plt.show()