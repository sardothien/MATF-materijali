import pandas as pd
from sklearn import metrics
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier

df = pd.read_csv('iris.csv')

x = df[df.columns[:-1]]
# poslednja kolona, Species, je ciljni atribut
y = df[df.columns[-1]]

# Trening i test skup
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.2, stratify=y)

# x_train y_train (75%)
# x_test  y_test  (25%)

dt = DecisionTreeClassifier()

# formiranje drveta/modela
dt.fit(x_train, y_train)

y_predicted = dt.predict(x_test)

# Matrica konfuzije
cnf_matrix = metrics.confusion_matrix(y_test, y_predicted)
df_cnf_matrix = pd.DataFrame(cnf_matrix, index=dt.classes_, columns=dt.classes_)

print(df_cnf_matrix)

# Preciznost
accuracy = metrics.accuracy_score(y_test, y_predicted)
print("Preciznost test skupa: ", accuracy)

y_train_predicted =  dt.predict(x_train)
train_accuracy = metrics.accuracy_score(y_train, y_train_predicted)
print("Preciznost trening skupa: ", train_accuracy)

print(metrics.classification_report(y_test, y_predicted))