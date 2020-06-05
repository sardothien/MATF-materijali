# Izvrsiti klasifikaciju nad skupom o perunikama primenom algoritma naivni 
# Bajes za neprekidne atribute. Na standardni izlaz za test skup ispisati:
#  • ukupnu preciznost za test skup
#  • matricu konfuzije za test skup
#  • izvestaj o klasifikaciji (za svaku klasu izdvojiti: preciznost, odziv
#    i f1) za test skup
# Zadatak resiti koriscenjem programskog jezika Python.

import pandas as pd
from sklearn import metrics
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import GaussianNB

df = pd.read_csv('iris.csv')

x = df[df.columns[:-1]]
y = df[df.columns[-1]]

x_train, x_test, y_train, y_test = train_test_split(x, y, stratify=y)

gnb = GaussianNB()
gnb.fit(x_train, y_train)

y_pred = gnb.predict(x_test)

conf_matrix = metrics.confusion_matrix(y_test, y_pred)
conf_matrix_df = pd.DataFrame(conf_matrix, index=gnb.classes_, columns=gnb.classes_)
print(conf_matrix_df)

print(metrics.classification_report(y_test, y_pred))

print(metrics.accuracy_score(y_test, y_pred))