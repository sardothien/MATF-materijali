import pandas as pd
import numpy as np

df = pd.read_csv('iris.csv')

# print(np.isnan(np.nan))
# print(np.isnan(float('nan')))

# iris skup nema nedostajuce vrednosti pa cemo ih
# dodati vestacki:
df.iloc[1, 1] = None

print(df.shape)

# Prebrojavanje nedostajucih vrednosti
print(df.isna().sum(axis=0)) # sabiranje po kolonama
print(df.isna().sum(axis=1)) # sabiranje po vrstama
print("Ukupno: ", df.isna().sum(axis=0).sum()) # ukupno

# 1. Izbacujemo instance/redove sa NaN
# - axis = 0 -> gleda po redovima
print(df.dropna(axis=0, inplace=False))

# 2. Izbacujemo atribute/kolone sa NaN
# - axis = 1 -> gleda po kolonama
print(df.dropna(axis=1, inplace=False))

# 3. Umetanje vrednosti umesto NaN
print(df.fillna(0))
print(df.fillna(df.describe().loc['mean', 'Sepal_Width']))

# nije uvek dobro menjati sa mean:
df.iloc[0, 2] = None
print(df.fillna(df.describe().loc['mean', 'Petal_Length']))

setosae_df = df[df['Species'] == 'setosa']
print(setosae_df)
print(setosae_df['Petal_Length'])

mean_petal_length_setosae = setosae_df['Petal_Length'].mean()
print(mean_petal_length_setosae)

print(df.fillna(mean_petal_length_setosae))

# ovo moze dovesti do problema ako imamo vise NaN
# vrednosti u razlicitim atributima. Resenje:
# mean za svaki atribut
df.iloc[0, 0] = None

setosae_df_means = setosae_df.mean()
print(setosae_df_means)

print(df.fillna(setosae_df_means))

# jos jedan nacin:
print(df.fillna(method='bfill'))
print(df.fillna(method='ffill'))

# Sortiranje
# (ovde su vec sortirani pa cemo ih prvo izmesati)
df = df.sample(frac=1)
print(df)

df = df.sort_values(by='Species').reset_index(drop=True)
print(df)

# 4. Interpolacija vrednosti
# - ne radi ako su prve vrednosti NaN
df.iloc[1, 1] = None
df.iloc[2, 3] = None
print(df.interpolate())