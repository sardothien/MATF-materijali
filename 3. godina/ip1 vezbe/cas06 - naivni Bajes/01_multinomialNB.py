import pandas as pd
from sklearn import metrics
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import MultinomialNB

df = pd.read_csv('Articles.csv', encoding="ISO-8859-1")

# izbacujemo kolone koje nam ne trebaju
# df = df.drop(['Date', 'Heading'])
# drugi nacin - zadrzimo sta nam treba
# df = df[['Article', 'NewsType']]
# treci nacin:
x = df['Article']
y = df['NewsType']

x_train, x_test, y_train, y_test = train_test_split(x, y, stratify=y)

# pretvaramo u retke podatke
vectorizer = CountVectorizer()
x_train = vectorizer.fit_transform(x_train)
x_test = vectorizer.transform(x_test)

mnb = MultinomialNB()
mnb.fit(x_train, y_train)

y_pred = mnb.predict(x_test)

cnf_matrix = metrics.confusion_matrix(y_test, y_pred)

moj_test_x = [
    "Oil Prices Drop as US Invades Middle East",
    "Manchester United Wins Another Cup",
    "Market Valuation Of Spanish Sports Clubs Decreases"
]
moj_test_x = vectorizer.transform(moj_test_x)

moj_pred_y = mnb.predict(moj_test_x)
print(moj_pred_y)
print(mnb.predict_proba(moj_test_x))