# Dat je skup sa podacima iz novinskih clanaka - ebart. Clanci su podeljeni 
# prema klasi kojoj pripadaju u direktorijume: Ekonomija, HronikaKriminal, 
# KulturaZabava, Politika i Sport. Svaki clanak je obradjen: uklonjene su stop 
# reci i svaka rec je zamenjena svojim korenom, a zatim je izvrseno prebrojavanje
# reci. Rezultat obrade svakog clanka je sacuvan u zasebnoj datoteci. U dobijenoj 
# datoteci koja odgovara jednom clanku, u jednom redu su podaci o jednom korenu 
# reci - koren reci i broj pojavljivanja tog korena u tom clanku. U programskom 
# jeziku Python napisati skript kojim se 
#  • pravi term-matrica sa brojem pojavljivanja reci za clanke iz teksta
#  • prave modeli za klasifikaciju primenom algoritama
#       - multinomijalni naivni Bajes
#       - K najblizih suseda i unakrsne validacije za odabir vrednosti parametara
#       - drveta odlucivanja i unakrsne validacije za odabir vrednosti parametara
#  • na standardni izlaz se za svaki napravljeni model ispisuje:
#       - koriscene vrednosti parametara algoritma pri pravljenju modela, ukoliko je 
#         model napravljen koriscenjem unakrsne validacije
#       - ukupna preciznost za trening i test skup
#       - matrica konfuzije za trening i test skup
#       - izvestaj o klasifikaciji (za svaku klasu izdvojiti: preciznost, odziv i f1) 
#         za trening i test skup

import os
from sklearn.feature_extraction import  DictVectorizer
from sklearn.model_selection import train_test_split, GridSearchCV
from sklearn.naive_bayes import MultinomialNB
from sklearn.tree import DecisionTreeClassifier
from sklearn.neighbors import  KNeighborsClassifier
import time

import sklearn.metrics as met
from termcolor import colored

import pandas as pd

# funkcija za treniranje modela i izvestaj o primeni modela na trening i test instance
def class_info(clf, x_train, y_train, x_test, y_test, cv=False):

    start=time.time()
    clf.fit(x_train, y_train)

    end=time.time()
    print('Vreme pravljenja modela', end-start)

    # izvestaj za unakrsnu validaciju, ukoliko je primenjena
    if cv:
        print('Najbolji parametri', clf.best_params_)

        means = clf.cv_results_['mean_test_score']
        stds = clf.cv_results_['std_test_score']
        for mean, std, params in zip(means, stds, clf.cv_results_['params']):
            print("%0.3f (+/-%0.03f) za %s" % (mean, std * 2, params))

    print('Trening skup')
    y_pred = clf.predict(x_train)

    cnf_matrix = met.confusion_matrix(y_train, y_pred)
    print("Matrica konfuzije")
    print(pd.DataFrame(cnf_matrix, index=clf.classes_, columns=clf.classes_))
    print()

    accuracy = met.accuracy_score(y_train, y_pred)
    print("Preciznost", accuracy)
    print()

    class_report = met.classification_report(y_train, y_pred, target_names=clf.classes_)
    print("Izvestaj klasifikacije")
    print(class_report)
    print()

    print('Test skup')
    y_pred = clf.predict(x_test)

    cnf_matrix = met.confusion_matrix(y_test, y_pred)
    print("Matrica konfuzije")
    print(pd.DataFrame(cnf_matrix, index=clf.classes_, columns=clf.classes_))
    print()

    accuracy = met.accuracy_score(y_test, y_pred)
    print("Preciznost", accuracy)
    print()

    class_report = met.classification_report(y_test, y_pred, target_names=clf.classes_)
    print("Izvestaj klasifikacije")
    print(class_report)
    print()

# podaci o instancama
corpus = []

# klase instanci
classes = []

# ucitavanje skupa
for class_name in os.listdir('Skup'):
    dir_path = 'Skup\\' + class_name
    for file_name in os.listdir(dir_path):
        f = open(dir_path + '\\' +file_name, 'r')
        file_words = {}
            
        for line in f:
            word_count=line.split()
            file_words[word_count[0]]=int(word_count[1])
        classes.append(class_name)
        corpus.append(file_words)
        f.close()


# pravljenje term-matrice na osnovu liste recnika
# jedan recnik sadrzi informacije o jednoj instanci, tj. jednom clanku u
# kojem je kljuc term, a vrednost kljuca broj pojavljivanja terma u clanku
dv = DictVectorizer()
x = dv.fit_transform(corpus)
print('Termi koji se pojavljuju u korpusu')
print(dv.get_feature_names())

df = pd.DataFrame(x.toarray(), columns=dv.get_feature_names())
print(df.head())

# podela na trening i test skup
x_train, x_test, y_train, y_test = train_test_split(df, classes, test_size=0.3, stratify=classes)

# klasifikacija primenom razlicitih algoritama
print(colored("MultinomialNB", "blue"))

clf_mnb = MultinomialNB()
class_info(clf_mnb, x_train, y_train, x_test, y_test)

parameters = [{'criterion': ['gini', 'entropy'],
                'max_depth':[15, 25, 5],
             }]

print(colored("KNeighborsClassifier", "blue"))

# definisanje mogucih vrednosti parametara za K najblizih suseda
# koji ce se koristiti u unakrsnoj validaciji
parameters = [{'n_neighbors': [3, 5, 8],
               'p':[2],
               'weights': ['uniform', 'distance'],
             }]

# napomena: izvrsavanje traje dugo
clf_dt = GridSearchCV(KNeighborsClassifier(), parameters, cv=5 )
class_info(clf_dt, x_train, y_train, x_test, y_test, cv=True)