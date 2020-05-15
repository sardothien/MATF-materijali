import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import accuracy_score, classification_report

iris = pd.read_csv('iris.csv')

# prvih 5 instanci
print(iris.head(5))
# osnovne statistike atributa
print(iris.describe())
# korelacija
print(iris.corr())

# lista klasa
print(iris.columns.tolist())
# bez poslednje klase
features = iris.columns.tolist()[:-1]
print(features)

# podaci o klasama
x = iris[features]
y = iris[iris.columns.tolist()[-1]]
print(x.head(5))
print(y.head(5))

# stratify = y -> stratifikovana podela (isti procenat svake klase kao na pocetku)
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size = 0.3, stratify = y)

clf = DecisionTreeClassifier(criterion = 'entropy', max_depth = 3, min_samples_split = 3)

# Treniranje
clf.fit(x_train, y_train)
print(clf.classes_)
print(pd.Series(clf.feature_importances_, index = features))
print(clf.predict_proba(x_test))
print(clf.predict(x_test))

print("trening")
y_pred = clf.predict(x_train)
print('Preciznost za ceo skup: ', accuracy_score(y_train, y_pred))
print(classification_report(y_train, y_pred))

print("test")
y_pred = clf.predict(x_test)
print('Preciznost za ceo skup: ', accuracy_score(y_test, y_pred))
print(classification_report(y_test, y_pred))