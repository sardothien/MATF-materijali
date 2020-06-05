# U programskom jeziku Python izvrsiti klasterovanje nad skupom unbalance.csv
# primenom algoritama K-sredina, DBSCAN i hijerarhijskog sakupljajuceg
# klasterovanja za razlicit broj klastera. Skup unbalance.csv sadrzi numericke
# atribute X i Y. Vrednosti za parametre algoritama samostalno zadati. Rezultat
# svakog izvrsenog klasterovanja prikazati pomocu grafika sa semom sa rasprsenim
# elementima. Svakom klasteru u rezultatu dodeliti jedinstvenu boju i njegove instance
# oznaciti tom bojom. U naslovu grafika ispisati naziv primenjenog algoritma i broj
# izdvojenih klastera. Za svaki algoritam napraviti i grafik koji prikazuje silueta
# koeficijent za razlicit broj izdvojenih klastera.

import pandas as pd
from matplotlib.figure import Figure
from matplotlib import pyplot as plt
import numpy as np
from sklearn import metrics
from sklearn.cluster import KMeans, AgglomerativeClustering, DBSCAN
from sklearn.preprocessing import MinMaxScaler

df = pd.read_csv('unbalance.csv')

# provera da li ima nedostajucih vrednosti
has_na = df.isna().any().any()
print("Ima" if has_na else "Nema", "nedostajuce vrednosti")

print(df.describe())

scaler = MinMaxScaler()
x = pd.DataFrame(scaler.fit_transform(df), columns=df.columns)

figure = plt.figure(figsize=(20, 15))
plot_index = 1


# Scatter [title, legend, figure, show/save]
def create_scatter(x: pd.DataFrame, labels: np.array, plt_index, title):

    figure.add_subplot(3, 5, plt_index)

    clusters = np.unique(labels) # broj klastera

    for cluster_index in clusters:
        samples = x.iloc[labels == cluster_index]
        label = "Sum" if cluster_index == -1 else "Klaster % i" % cluster_index
        plt.scatter(samples['x'], samples['y'], label=label)

    plt.title(title)
    plt.legend()


# Silhouette line graph
def create_line_plot(x, y, plt_index):

    figure.add_subplot(3, 5, plt_index)
    plt.plot(x, y, marker='o')


k_means_n = []
k_means_sil = []

# K-Means
for k in range(6, 10):
    k_means = KMeans(n_clusters=k)
    k_means.fit(x)
    create_scatter(df, k_means.labels_, plot_index, "K-Means, K: %i" % k)
    plot_index += 1
    k_means_n.append(k)
    ss = metrics.silhouette_score(x, k_means.labels_)
    k_means_sil.append(ss)

create_line_plot(k_means_n, k_means_sil, plot_index)
plot_index += 1

agg_n = []
agg_sil = []

# Agglomerative
for k in range(6, 10):
    agg_clustering = AgglomerativeClustering(n_clusters=k)
    agg_clustering.fit(x)
    create_scatter(df, agg_clustering.labels_, plot_index, "Agglomerative, K: %i" % k)
    plot_index += 1
    agg_n.append(k)
    ss = metrics.silhouette_score(x, agg_clustering.labels_)
    agg_sil.append(ss)

create_line_plot(agg_n, agg_sil, plot_index)
plot_index += 1

dbscan_n = []
dbscan_sil = []

# DBSCAN
for eps in [0.02, 0.04, 0.06, 0.08]:
    dbscan = DBSCAN(eps=eps)
    dbscan.fit(x)
    create_scatter(df, dbscan.labels_, plot_index, "DBSCAN, eps: %.3f" % eps)
    plot_index += 1

    n_clusters = len(np.unique(dbscan.labels_)) - 1 # klaster za sum
    dbscan_n.append(n_clusters)

    x_without_noise = x.iloc[dbscan.labels_ != -1]
    labels_without_noise = dbscan.labels_[dbscan.labels_ != -1]

    ss = metrics.silhouette_score(x_without_noise, labels_without_noise)
    dbscan_sil.append(ss)

create_line_plot(dbscan_n, dbscan_sil, plot_index)
plot_index += 1

# plt.show()
# ako hocemo da se sacuva u datoteci, umesto plt.show() koristimo:
plt.savefig('zadatak.png')