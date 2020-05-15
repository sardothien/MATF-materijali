# Ilustrovati prenos argumenata funkciji: definisati dve funkcije koje rade sa
# listom, jednu koja menja, a drugu koja pravi kopiju prosledjenog joj argumenta.

def translacija(x):
    x = x - 1 
    return x

a = 5
print("a : ", a)
translacija(a)
print("a : ", a)

# --------------------------------------------

def translacija(l):
    l = l[:-1]

l = [1, 2, 3]
print("l : ", l)
translacija(l)
print("l : ", l)

def translacija(l):
    l[0] = "M"

translacija(l)
print("l : ", l)

# --------------------------------------------

x = 19
print("x = ", x, " id = ", id(x))

def primer(x):
    print("x = ", x, " id = ", id(x))
    x = 42
    print("x = ", x, " id = ", id(x))
    x -= 1
    print("x = ", x, " id = ", id(x))

primer(x)