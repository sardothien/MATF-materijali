# Nad skupom podataka iris.csv izvrsiti klasifikaciju primenom algoritma K 
# najblizih suseda u programskom jeziku Python. U okviru resenja uraditi i:
# • Za odabir vrednosti parametara algoritma koristiti unakrsnu validaciju.
# • Primeniti najbolji model na test skup i izdvojiti:
#    - ukupnu preciznost
#    - matricu konfuzije
#    - izvestaj za klasifikaciju (za svaku klasu izdvojiti: preciznost, odziv i f1)
# • Omoguciti i izvestaj o klasifikaciji svake instance u test skupu. Za svaku test 
#   instancu na standardni izlaz ispisati: klasu kojoj instanca pripada, klasu koja
#   je instanci dodeljena modelom i podaci o susedima (klasa kojoj sused pripada i 
#   rastojanje suseda do test instance).
# Napomena: posto se koristi rastojanje Minkovskog za odredjivanje bliskosti dve 
# instance, potrebno je izvrsiti normalizaciju (ili standardizaciju) vrednosti atributa.

import pandas as pd
from sklearn import metrics
from sklearn.model_selection import train_test_split, GridSearchCV
from sklearn.neighbors import KNeighborsClassifier
from sklearn.preprocessing import MinMaxScaler
import sys

df = pd.read_csv('iris.csv')

x = df[df.columns[:-1]]
y = df[df.columns[-1]]

# Najpre moramo da izvrsimo standardizaciju
x = pd.DataFrame(MinMaxScaler().fit_transform(x), columns=x.columns)

# MinMaxScaler:
# min max
# [a, b] => [0, 1]
# [a, b] - a => [0, b-a]
# [0, b-a] / (b-a) => [0, 1]

x_train, x_test, y_train, y_test = train_test_split(x, y, train_size=0.95, stratify=y)

parameters = [{'n_neighbors': range(3, 8),
               'weights': ['uniform', 'distance'],
               'p':[1, 2]
              }]

classifier = GridSearchCV(KNeighborsClassifier(), param_grid=parameters, cv=5)

# Pravljenje modela
classifier.fit(x_train, y_train)

# Predvidjanje
y_predicted = classifier.predict(x_test)

# Matrica konfuzije
confussion_matrix = metrics.confusion_matrix(y_test, y_predicted)
confussion_matrix_df = pd.DataFrame(confussion_matrix, index=classifier.classes_, columns=classifier.classes_)
print(confussion_matrix_df)

# Najbolji parametri
print(classifier.best_params_)

# sa .best_estimator_ se pristupa klasifikatoru i
# onda se mogu koristiti njegovi atributi i metode
knn = classifier.best_estimator_
distances, indices = knn.kneighbors(x_test)

# Na kojim mestima se gresi:
for i in range(len(indices)):
    instance_x = x_test.iloc[i]
    instance_y_true = y_test.iloc[i]
    instance_y_predicted = y_predicted[i]

    neighbor_distances = distances[i]
    neighbor_indices = indices[i]

    if instance_y_predicted != instance_y_true:
        print("predicred: %s, actual: %s" % (instance_y_predicted, instance_y_true))
        print(list(zip(df.loc[neighbor_indices, 'Species'].tolist(), neighbor_distances)))
