# Dat je skup dogs.csv koji ima atribute:
#   - breed - rasa psa
#   - height - visina psa
#   - weight - tezina psa
# Koriscenjem programskog jezika Python izvrsiti klasterovanje 
# algoritmom K-sredina na osnovu visine i tezine pasa. Napraviti
# modele za:
#   • za 2, 3 i 4 klastera i
#   • razlicite metode za inicijalizaciju centroida.
# Rezultat svakog izvrsenog klasterovanja prikazati graficki pomocu
# seme sa rasprsenim elementima. Svakom klasteru u rezultatu dodeliti 
# jedinstvenu boju i njegove instance oznaciti tom bojom. Za svako 
# klasterovanje prikazati centroide izdvojenih klastera i izracunati SSE.
# Za koje od koriscenih vrednosti parametara se dobija najbolji model?

import pandas as pd
from sklearn import metrics
from sklearn.cluster import KMeans
from sklearn.preprocessing import MinMaxScaler
from termcolor import colored
import matplotlib.pyplot as plt

df = pd.read_csv('dogs.csv')

# ne treba nam naziv rase
df = df.drop('breed', axis=1)

# normalizacija
scaler = MinMaxScaler()
x = pd.DataFrame(scaler.fit_transform(df), columns=df.columns)

# Zelimo da nam sve slike budu u jednoj:
figure = plt.figure(figsize=(9, 9))
# indeks za slike
plot_index = 1

# K-sredina
for k in range(2, 5):
    for init in ['k-means++', 'random']:
        k_means = KMeans(n_clusters=k, init=init)
        k_means.fit(x)

        # slika sa 3 vrste i 2 koline
        figure.add_subplot(3, 2, plot_index)
        plot_index += 1

        print(colored("k: %i, init: %s" % (k, init), 'blue'))

        # koordinate centroida
        print(k_means.cluster_centers_)

        # oznake klastera  kojima pripada
        print(k_means.labels_)

        # suma kvadratnih gresaka
        print(k_means.inertia_)
        print()

        # Dodajemo novu kolonu u originalni dataFrame
        # koji ne treba da bude skaliran
        df['label'] = k_means.labels_
        centroids = k_means.cluster_centers_
        centroids = scaler.inverse_transform(centroids)

        # graficki prikaz
        for cluster_index, color in zip(range(k), ['red', 'green', 'blue', 'magenta']):
            samples = df.loc[lambda inst: inst['label'] == cluster_index, :]
            # drugi nacin:
            # samples = df[df['label'] == cluster_index]

            plt.scatter(x=samples['height'], y=samples['weight'], color=color)

            centroid = centroids[cluster_index]

            plt.scatter(x=centroid[0], y=centroid[1], color='black', marker='x')

            silhouette_coef = metrics.silhouette_score(x, k_means.labels_)

            # naslov za svaki plot
            plt.title("k: '%i', init: '%s', SSE: '%f', SCoef: '%f'" % (k, init, k_means.inertia_, silhouette_coef))

plt.show()