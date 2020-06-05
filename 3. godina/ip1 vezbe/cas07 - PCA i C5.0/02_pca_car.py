# Skup car.csv sadrzi podatke o automobilima. Atributi skupa su:
#   • class - klasa automobila
#   • cylinders - broj cilindara
#   • displacement - zapremina motora
#   • horsepower - konjska snaga
#   • weight - tezina
#   • acceleration - ubrzanje
# Koristeci programski jezik Python i algoritam K najblizih suseda 
# izvrsiti klasifikaciju nad datim skupom. Atribut class je ciljni
# atribut. Primeniti unakrsnu validaciju za odabir optimalnih parametara.
# Za model napravljen sa optimalnim parametrima izdvojiti
#   • preciznost na trening skupu;
#   • preciznost na test skupu;
#   • matricu konfuzije za trening skup;
#   • matricu konfuzije za test skup;
# Zatim primeniti PCA na skup i izvrsiti klasifikaciju nad transformisanim
# skupom. Koji broj atributa ste izabrali nakon primene PCA da se koristi
# pri klasikaciji i zasto? Uporediti model dobijen nad originalnim skupom 
# sa modelom dobijenim nad podacima dobijenim nakon PCA transformacije.

import pandas as pd
from sklearn.model_selection import train_test_split, GridSearchCV
from sklearn import preprocessing
from sklearn.neighbors import  KNeighborsClassifier
from sklearn.decomposition import PCA
import matplotlib.pyplot as plt
import sklearn.metrics as met

# funkcija za klasifikaciju skupa
def classification(message, x_arg, y_arg):

    print(message, '\n')

    # podela na trening i test skup
    x_train, x_test, y_train, y_test = train_test_split(x_arg, y_arg, test_size=0.3, stratify=y)

    # vrednosti parametara algoritma KNN za unakrsnu validacuju
    parameters = [{'n_neighbors': range(3, 20, 2),
                   'p': [1, 2],
                   'weights': ['uniform', 'distance']
                   }]

    # primena unakrsne validacije
    clf = GridSearchCV(KNeighborsClassifier(), parameters, cv=10)
    clf.fit(x_train, y_train)

    print("Najbolji parametri:")
    print(clf.best_params_)
    print()

    print("Izvestaj za trening skup:")
    y_pred =clf.predict(x_train)
    print('Preciznost: ', met.accuracy_score(y_train, y_pred))
    print()

    print("Matrica konfuzije",
          pd.DataFrame(met.confusion_matrix(y_train, y_pred),
                       index=clf.classes_,
                       columns=clf.classes_),
          sep="\n")
    print()

    print("Izvestaj za test skup:")
    y_pred =clf.predict(x_test)
    print('Preciznost: ', met.accuracy_score(y_test, y_pred))
    print()

    print("Matrica konfuzije",
          pd.DataFrame(met.confusion_matrix(y_test, y_pred),
                       index=clf.classes_,
                       columns=clf.classes_),
          sep="\n")
    print()

    # Graficki prikaz test skupa pomocu rasprsenih elemenata
    # koriscenjem prve dve glavne komponente.
    # Svakoj klasi se dodeljuje odredjena boja, a instance na slici
    # se obelezavaju bojom na osnovu klase koja im je dodeljena.
    if message == 'PCA':
        colors = ['red', 'blue', 'gold',  'm', 'plum', 'orange', 'black']
        x_test.is_copy=False
        x_test['predicted'] = y_pred
        classes =x_test['predicted'].unique()
        for i, class_value in zip(range(0, len(classes)), classes):
            class_samples = x_test.loc[lambda s: s['predicted'] == class_value, :]
            plt.scatter(class_samples['pca1'], class_samples['pca2'], color=colors[i],
                        s=10, marker='o', label="class %s" % class_value)

        plt.title('PCA & klasifikacija')
        plt.xlabel('pca1')
        plt.ylabel('pca2')
        plt.legend(loc='upper right')
        plt.savefig('pca_klas.png')


# ucitavanje skupa
df = pd.read_csv("car.csv")

# prikaz imena kolona + 5 prvih instanci
print('Prvih 5 instanci', df.head(), sep='\n')
print()

print('Opis podataka')
print(df.describe())
print()

# prikaz broja instanci po klasama
print('Klase')
print(df["class"].value_counts())
print()

# priprema skupa za klasifikaciju - razdvajanje opisa instanci i njihovih klasa
features = df.columns[1:]
x = df[features]
y = df["class"]

num_features = x.shape[1]

# standardizacija podataka
scaler = preprocessing.StandardScaler().fit(x)
x = pd.DataFrame(scaler.transform(x))
x.columns = features

# primena pca
pca = PCA(n_components=2)
pca.fit(x)
x_pca = pd.DataFrame(pca.transform(x))

# promena imena kolona skupu dobijenom nakon pca transformacije
pca_columns = ['pca%d'%i for i in range(1, pca.n_components_+1)]
x_pca.columns = pca_columns

# procenat varijanse objasnjen svakom od izabranih glavnih komponenti
print('explained_variance_ratio_  ')
for i, evr in zip(range(1, num_features+1), pca.explained_variance_ratio_):
    print("pca%d: %.10f"%(i,evr))
print()

classification('Originalan skup', x, y)
classification('PCA skup', x_pca, y)