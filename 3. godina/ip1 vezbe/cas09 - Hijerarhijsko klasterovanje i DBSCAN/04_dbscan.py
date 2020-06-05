import pandas as pd
from sklearn import metrics
from sklearn.cluster import DBSCAN
from sklearn.preprocessing import MinMaxScaler
from sklearn.decomposition import PCA
from matplotlib import pyplot as plt

df = pd.read_csv('fish.csv')
x = df.drop('Species', axis=1)

# skaliranje
scaler = MinMaxScaler()
x = scaler.fit_transform(x)

pca = PCA(n_components=2)
x = pd.DataFrame(pca.fit_transform(x))

plt.scatter(x[0], x[1])
plt.show()

dbscan = DBSCAN(eps=0.1, min_samples=4)
dbscan.fit(x)

x['label'] = dbscan.labels_

# bez suma
x_denoised = x.loc[lambda inst: inst['label'] != -1]

ss = metrics.silhouette_score(x_denoised.drop('label', axis=1), x_denoised['label'])
print('Silueta koeficijen: ', ss)

n_clusters = x['label'].nunique()

for cluster_index in range(-1, n_clusters-1):
    samples = x.loc[lambda inst : inst['label'] == cluster_index]
    label = 'Sum' if cluster_index == -1 else 'Klaster %i' % cluster_index
    plt.scatter(samples[0], samples[1], label=label)

plt.legend()
plt.show()