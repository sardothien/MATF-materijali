import pandas as pd

# Ucitavamo skup iz csv fajla
df = pd.read_csv('iris.csv')

# Citamo prvih 5 redova u skupu podataka
# - kao argument mozemo zadati broj redova
print(df.head())

# Dimenzije (broj redova, broj atributa)
print(df.shape)

# Lista svih kolona
print(df.columns)
print(df.columns[2])

print("Input atributi: ", df.columns[:-1])
print("Target atribut: ",  df.columns[-1])

# Indeksiranje po kolonama
print(df['Sepal_Length'])
print(df[['Sepal_Length', 'Sepal_Width']])

input_podaci = df[df.columns[:-1]]
target_atribut = df[df.columns[-1]]
print(input_podaci)
print(target_atribut)

print(type(input_podaci))
print(type(target_atribut))

# Posto je target_atribut tipa Series, mozemo koristiti
# sledecu metodu
print(target_atribut.value_counts())

# Indeksiranje po redovima
print(df.iloc[0:2])
print(df.loc[[0, 1, 2], 'Sepal_Width'])

# Osnovne statistike o skupu podataka
print(df.describe())
print(df.describe().loc['50%', 'Petal_Length'])

# Matrica korelacije
print(df.corr())
print(df.corr().loc['Sepal_Width', 'Sepal_Length'])

# Brisanje kolone
df = df.drop('Petal_Width', axis=1)
print(df.head())

# Nedostajuce vrednosti
# - tamo gde je NA pisace True
print(df.isna())
# - za svaki atribut ce videti da li ima bar jedan True
print(df.isna().any())
# - da li postoji bar jedan koji je True bilo gde
print(df.isna().any().any())