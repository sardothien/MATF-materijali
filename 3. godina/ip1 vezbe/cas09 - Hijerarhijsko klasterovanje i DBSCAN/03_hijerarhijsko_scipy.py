# Dat je skup dogs koji ima atribute:
#   - breed - rasa psa
#   - height - visina psa
#   - weight - tezina psa
# Izvrsiti hijerarhijsko sakupljajuce klasterovanje na osnovu 
# visine i tezine pasa koriscenjem euklidskog rastojanja i average
# veze pri odredjivanju bliskosti dva klastera. Za klasterovanje
# koristiti biblioteku scipy programskog jezika Python. Rezultat 
# izvrsenog hijerarhijskog klasterovanja prikazati pomocu dendograma.


import pandas as pd
from sklearn.preprocessing import MinMaxScaler
from scipy.cluster.hierarchy import linkage, dendrogram, fcluster
from matplotlib import pyplot as plt

df = pd.read_csv('dogs.csv')
x = df.drop('breed', axis=1)

# skaliranje
scaler = MinMaxScaler()
x = pd.DataFrame(scaler.fit_transform(x), columns=x.columns, index=df['breed'])

z = linkage(x, 'average')

plt.figure(figsize=(10,10))

treshold = 0.7

dendrogram(z, labels=x.index, color_threshold=treshold)

# dodeljujemo oznaku klastera
# df['label'] = fcluster(z, t=treshold, criterion='distance')
df['label'] = fcluster(z, t=4, criterion='maxclust')

plt.show()