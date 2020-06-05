# U programskom jeziku Python napisati skript kojim se
#  • pravi term-matrica sa brojem pojavljivanja reci za dati trening skup
#  • pomocu algoritma multinomijalni naivni Bajes i trening skupa pravi model 
#    za klasifikaciju
#  • klasifikuje test instanca X = Chinese Chinese Chinese Tokyo Japan.

import pandas as pd
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.naive_bayes import  MultinomialNB

trening_skup = [
        'Chinese Beijing Chinese',
        'Chinese Chinese Shanghai',
        'Chinese Macao',
        'Tokyo Japan Chinese'
    ]

klase = ['yes', 'yes', 'yes', 'no']

# pravljenje term matrice sa brojem pojavljivanja reci
vectorizes = CountVectorizer()
x_train = vectorizes.fit_transform(trening_skup)

print(vectorizes.get_feature_names())

print(pd.DataFrame(x_train.toarray(), index=trening_skup, columns=vectorizer.get_feature_names()))

# pravljenje modela primenom multinomijalnog naivnog Bajesa
mnb = MultinomialNB()
mnb.fit(x_train, klase)

# broj instanci po klasama
print(pd.Series(mnb.class_count_, index=mnb.classes_))

# broj pojavljivanja reci po klasama
print(pd.DataFrame(mnb.feature_count_, index=mnb.classes_, columns=vectorizer.get_feature_names()))

# transformisanje test instance u term matricu
x_test = ['Chinese Chinese Chinese Tokyo Japan']
x_test = vectorizer.transform(x_test)

y_pred = mnb.predict(x_test)
print('Dodeljena klasa: ', y_pred)