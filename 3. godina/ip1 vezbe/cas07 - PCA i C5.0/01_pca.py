# Primeniti PCA na skup iris, a zatim
#  - na standardni izlaz ispisati izraz po kome se racunaju vrednosti
#    u svakoj od glavnih komponenti transformisanog skupa
#  - na standardni izlaz ispisati kolicinu varijanse koja je objasnjena
#    svakom od glavnih komponenti transformisanog skupa
#  - na standardni izlaz ispisati procenat varijanse koja je objasnjena
#    svakom od glavnih komponenti transformisanog skupa
#  - pomocu stupcanog grafikona prikazati koji procenat varijanse objasnjava
#    svaka od glavnih komponenti u transformisanom skupu
#  - graficki prikazati skup iris pomocu rasprsenih elemenata koriscenjem 
#    prve dve glavne komponente transformisanog skupa. Svakoj klasi dodeliti 
#    jedinstvenu boju, a instance obojiti bojom klase kojoj instanca pripada.
# Zadatak resiti koriscenjem programskog jezika Python.

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.decomposition import PCA
from sklearn.preprocessing import StandardScaler

df = pd.read_csv('iris.csv')

x = df.drop('Species', axis=1)
y = df['Species']
features = x.columns
classes = y.unique()

# Skaliranje
scaler = StandardScaler()
x = pd.DataFrame(scaler.fit_transform(x), columns=features)

pca = PCA()
x_pca = pd.DataFrame(pca.fit_transform(x), columns=['pc%i' % i for i in range(1, pca.n_components_ + 1)])

# Trazimo koeficijente za linearnu kombinaciju
for index, component_array in enumerate(pca.components_):
    pc_text = "pc%i=" % (index+1)
    for feature, component in zip(features, component_array):
        pc_text += "%.2f * %s " % (component, feature)
    print(pc_text)
print()

print(pca.explained_variance_)
print(pca.explained_variance_ratio_)
print(np.cumsum(pca.explained_variance_ratio_))

# Zadrzavamo samo prve dve kolone jer nam one objasnjavaju
# 95% varijanse (sto vidimo iz cumsum)
x_pca = x_pca[['pc1', 'pc2']]

# Graficki prikaz
for color, cls in zip(['red', 'green', 'blue'], classes):
    class_indices = y[y == cls].index
    class_samples_x = x_pca.iloc[class_indices]
    plt.scatter(x=class_samples_x['pc1'], y=class_samples_x['pc2'], color=color, label=cls)
plt.legend(loc="upper right")
plt.show()