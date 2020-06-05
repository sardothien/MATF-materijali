# Dat je skup dogs koji ima atribute:
#   - breed - rasa psa
#   - height - visina psa
#   - weight - tezina psa
# Primeniti klasterovanje algoritmom DBSCAN na osnovu visine i tezine
# pasa koriscenjem programskog jezika Python. Izvrsiti klasterovanja 
# koriscenjem razlicitih vrednosti za rastojanje medju susedima 
# (0.1, 0.2, 0.25, 0.27, 0.28, 0.3), a vrednost parametra za broj
# suseda koje mora da ima instanca u jezgru postaviti na 2. Rezultat 
# svakog izvrsenog klasterovanja prikazati pomocu grafika sa semom sa 
# rasprsenim elementima. Svakom klasteru u rezultatu dodeliti jedinstvenu 
# boju i njegove instance oznaciti tom bojom. U naslovu grafika ispisati 
# vrednost za parametar eps i vrednost silueta koeficijenta. Uporediti 
# dobijene modele.

import pandas as pd
from sklearn.metrics import silhouette_score
from sklearn import preprocessing
from sklearn.cluster import DBSCAN
import matplotlib.pyplot as plt

# ucitavanje skupa
df = pd.read_csv("dogs.csv")

# prikaz imena kolona + 5 prvih instanci
print('Prvih 5 instanci', df.head(), sep='\n')

# Za klasterovanje ce se koristiti atributi visina i tezina psa,
# a rasa nece biti uzeta u obzir.
features = df.columns[1:]
x_original = df[features]

# standardizacija atributa
# x=pd.DataFrame(preprocessing.scale(x_original))

# normalizacija
x = pd.DataFrame(preprocessing.MinMaxScaler().fit_transform(x_original))

# dodeljivanje imena kolonama
x.columns = features

# Definisanje boja koje se koriste pri crtanju instanci klastera.
# Instance jednog klastera ce biti prikazane istom bojom.
# Sum ce biti prikazan crvenom bojom.
colors = ['darkcyan', 'magenta', 'gold', 'blue', 'navy', 'green', 'red']

# pravljenje slike sa graficima
fig = plt.figure()

# oznaka celije na slici u kojoj se vrse naredna crtanja
plt_ind = 1

# Primena algoritma dbscan sa razlicitim vrednostima za parametar eps, a  parametar za
# broj suseda koje mora da ima instanca u jezgru je 2.
for eps in [0.1, 0.2, 0.25, 0.27, 0.28, 0.3]:

    est = DBSCAN(eps=eps, min_samples=2)
    est.fit(x)

    # Originalnom skupu se dodaje jos jedan atribut 'label', koji sadrzi
    # podatak kom klasteru pripada koja instanca.
    # Oznake klastera su u intervalu [0, n_clusters-1]
    # Instance tipa sum imaju oznaku -1.
    df['label'] = est.labels_

    num_clusters = max(est.labels_)+1

    # Podela slike na 3x2 celije i zadavanje
    # celije (plt_ind) u kojoj ce se izvrsiti naredna crtanja.
    fig.add_subplot(3,2,plt_ind)

    #obrada svakog klastera
    for j in range(-1,num_clusters):

        # izdvajanje instanci klastera koji se obradjuje
        cluster = df.loc[df['label'] == j, :]

        # dodela oznake klasteru za legendu
        if j==-1:
            label='šum'
        else:
            label = "klaster %d" % j

        # crtanje instanci klastera pomocu seme sa rasprsenim elementima
        plt.scatter(cluster['height'], cluster['weight'], color=colors[j], s=10, marker='o', label=label)

    # postavljanje legende i naslova (koji sadrzi vrednost parametra eps i silueta koeficijent)
    # za svaku celiju
    plt.legend(loc='lower right',fontsize=6)
    plt.title('DBSCAN, eps:%.2f silueta koeficijent %.2f'%(eps, silhouette_score(x, df['label'])), fontsize=10)

    # Prelazak u narednu celiju u kojoj ce se prikazati
    # rezultat klasterovanja sa novim parametrima.
    plt_ind += 1

# prikaz slike bez poklapanja celija
plt.tight_layout()
plt.show()

#Komentari:
# Za eps=0.1 veliki broj instanci nije dodeljen nijednom klasteru, tj. oznacen je kao sum.

# Sa povecanjem eps na 0.2 ili 0.25 izdvaja se klaster sa psima malog rasta, kao i klaster
# sa psima srednjeg rasta, ali psi velikog rasta se i dalje oznacavaju kao sum.

# Sa povecanjem eps na 0.28 psi malog i srednjeg rasta su u jednom  klasteru, a psi velikog
# rasta se i dalje oznacavaju kao sum.

# Sa povecanjem eps na 0.3 psi malog i srednjeg rasta su u jednom  klasteru, a psi velikog
# rasta cine drugi klaster.