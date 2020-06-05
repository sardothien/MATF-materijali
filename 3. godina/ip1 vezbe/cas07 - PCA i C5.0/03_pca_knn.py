import pandas as pd
from sklearn import metrics
from sklearn.decomposition import PCA
from sklearn.model_selection import train_test_split, GridSearchCV
from sklearn.neighbors import KNeighborsClassifier
from sklearn.preprocessing import StandardScaler
from termcolor import colored
import numpy as np

df = pd.read_csv('data.csv')

df = df.drop(['id', df.columns[32]], axis=1)

print("Prvih 5 instanci:\n", df.head())
print("Opis skupa:\n", df.describe())
print()

if df.isna().any().any():
    print(colored("Ima nedostajucih vrednosti", 'red'))
else:
    print(colored("Nema nedostajucih vrednosti", 'green'))
print()

x = df.drop('diagnosis', axis=1)
y = df['diagnosis']
features = x.columns

print("Zastupljenost klasa:\n", y.value_counts())
print()

# Standardizacija (skaliranje)
x = pd.DataFrame(StandardScaler().fit_transform(x), columns=features)

# PCA
pca = PCA()
x_pca = pd.DataFrame(pca.fit_transform(x), columns=["pc%i" % (i+1)  for i in range(0, pca.n_components_)])

minimum_explained_variance = 0.8

cumsum = np.cumsum(pca.explained_variance_ratio_)
print("Kumulativne sume:\n", cumsum)

num_pc = np.sum(cumsum < minimum_explained_variance) + 1
print("Izabrano ", colored("%i" %num_pc, 'blue'), " glavnih komponenti.\n")

x_pca = x_pca[x_pca.columns[:num_pc]]

# Klasifikacija
def classification(x_data : pd.DataFrame, y_data : pd.Series, is_pca : bool):
    if is_pca:
        print(colored("Klasifikacija sa PCA skupom", 'blue'))
    else:
        print(colored("Klasifikacija sa prvobitnim skupom", 'magenta'))

    x_train, x_test, y_train, y_test = train_test_split(x_data, y_data, stratify=y_data)

    params = {
        'n_neighbors' : range(2, 20),
        'p' : [1, 2],
        'weights' : ['uniform', 'distance']
    }

    grid_search = GridSearchCV(KNeighborsClassifier(), params, cv=5)
    grid_search.fit(x_train, y_train)

    print("Parametri najboljeg modela:\n", grid_search.best_params_)
    print()

    y_pred = grid_search.predict(x_test)

    cnf_matrix = pd.DataFrame(metrics.confusion_matrix(y_test, y_pred), index=grid_search.classes_, columns=grid_search.classes_)
    print("Matrica konfuzije:\n", cnf_matrix)
    print()

    print("Izvestaj klasifikacije:\n", metrics.classification_report(y_test, y_pred))
    print()

classification(x, y, False)
classification(x_pca, y, True)