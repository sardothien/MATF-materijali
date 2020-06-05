import pandas as pd

s = pd.Series([1, 2, 3, 4], index = ['a', 'b', 'c', 'd'])
s = pd.Series([1, 2, 3, 4])

print(s)
print(s.dtype)

# s[0]
# s[2]
# s['b']

s1 = pd.Series([10, 20, 30, 40])

print(s+s1)

s = pd.Series([1, 2, 3], index = ['a', 'b', 'c'])
s1 = pd.Series([20, 30, 40], index = ['b', 'c', 'd'])
print(s+s1)

print(s.keys())
print(s.values)

s1 = pd.Series([1, 2, 3], index = ['a', 'b', 'c'])
s2 = pd.Series(['tekst', 'tekst', 'jos jedan tekst'], index = ['a', 'b', 'c'])

df1 = pd.DataFrame([s1, s2])
print(df1)

df2 = pd.DataFrame({'prva' : s2, 'druga' : s1})
print(df2)

# Statistike
print("Suma: ", s1.sum())
print("Std: ", s1.std())
print("Mean: ", s1.mean())
print("Value counts:\n", s1.value_counts())
print("Value counts:\n", s2.value_counts())
print("Najcesca vrednost: ", s2.mode())