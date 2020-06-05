import pandas as pd
from sklearn import metrics
from sklearn.cluster import AgglomerativeClustering
from sklearn.decomposition import PCA
from sklearn.preprocessing import MinMaxScaler
import matplotlib.pyplot as plt

df = pd.read_csv('iris.csv')
df = df.drop('Species', axis=1)
df_orig = df

pca = PCA(n_components=0.9)

# skaliranje
scaler = MinMaxScaler()
df = pd.DataFrame(scaler.fit_transform(df))

pr_components = pd.DataFrame(pca.fit_transform(df))

figure = plt.figure(figsize=(10,10))
plot_index = 1

for n_clusters in range(2, 5):
    for link in ['single', 'complete', 'average']:
        figure.add_subplot(3, 3, plot_index)
        plot_index += 1

        clustering = AgglomerativeClustering(n_clusters=n_clusters, linkage=link)
        clustering.fit(pr_components)
        pr_components['label'] = clustering.labels_

        for cluster_index in range(n_clusters):
            samples = pr_components.loc[lambda sample: sample['label'] == cluster_index]
            plt.scatter(x=samples[0], y=samples[1])

        ss = metrics.silhouette_score(pr_components.drop('label', axis=1), pr_components['label'])

        plt.title("N: %i, Link: '%s', SS: %.2f " % (n_clusters, link, ss))

plt.show()