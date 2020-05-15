# Napisati program koji za uneta dva cela broja i nisku ispisuje
# najpre unete vrednosti, a zatim i zbir brojeva, njihovu razliku,
# proizvod i kolicnik.

a = int(input("Unesi ceo broj a: "))
b = int(input("Unesi ceo broj b: "))

niska = input("Unesi nisku: ")

print("{} {} {}".format(a, b, niska))
print(a+b)
print(a-b)
print(a*b)
print(a/b)