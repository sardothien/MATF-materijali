# Nad skupom podataka iris.csv izvrsiti klasifikaciju pomocu drveta odlucivanja u 
# programskom jeziku Python. U okviru resenja uraditi i:
# • Za odabir vrednosti parametara algoritma koristiti unakrsnu validaciju. Za ocenu
#   modela u unakrsnoj validaciji koristiti prosecnu preciznost klasa i prosecnu vrednost
#   mere f1 za klase.
# • Izdvojiti vrednosti parametara za najbolje modele prema zadatim merama.
# • Za svaku koriscenu kombinaciju vrednosti parametara u unakrsnoj validaciji izdvojiti:
#    - koriscene vrednosti parametara
#    - srednju vrednost mere za ocenu modela dobijenu na osnovu k test delova
#    - standardnu devijaciju vrednosti mere za ocenu modela dobijenu na osnovu k
#      test delova
# • Izdvojiti izvestaj o klasifikaciji za najbolje modele prema zadatim merama za test
#   skup (za svaku klasu izdvojiti: preciznost, odziv i f1).

import pandas as pd
from sklearn import metrics
from sklearn.model_selection import GridSearchCV, train_test_split
from sklearn.tree import DecisionTreeClassifier

df = pd.read_csv('iris.csv')

x = df[df.columns[:-1]]
y = df[df.columns[-1]]

x_train, x_test, y_train, y_test = train_test_split(x, y, stratify=y)

parameters = [{'criterion': ['gini', 'entropy'],
               'max_depth': [2, 3, 4, 5],
               'min_samples_split':[15, 10, 15],
               'min_samples_leaf': [2, 4, 6]
               }]
# score = ['precision', 'f1']
score = 'f1'

classifier = GridSearchCV(estimator=DecisionTreeClassifier(), param_grid=parameters, cv=5, scoring='%s_macro' % score)

# pravljenje modela
classifier.fit(x_train, y_train)

# Predvidjanje
y_predicted = classifier.predict(x_test)

print(classification_report(y_test, y_predicted))

# Matrica konfuzije
confussion_matrix = metrics.confusion_matrix(y_test, y_predicted)
confussion_matrix_df = pd.DataFrame(confussion_matrix, index=classifier.classes_, columns=classifier.classes_)
print(confussion_matrix_df)

# Parametri koji daju najbolji rezultat
print(classifier.best_params_)

# Recnik sa podacima o zadatim paramtetrima
print(classifier.cv_results_)
# za bolji prikaz (preko Python konzole):
cv_res = pd.DataFrame(classifier.cv_results_)

# Najbolji klasifikator
print(classifier.best_estimator_)

# Najbolji skor
print(classifier.best_score_)