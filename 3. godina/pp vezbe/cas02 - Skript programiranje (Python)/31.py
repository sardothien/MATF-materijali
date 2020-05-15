# Implementirati generator Fibonacijevih brojeva

def Fibonaci():
    a, b = 0, 1
    while True:
        yield a
        a, b = b, a+b

f = Fibonaci()
for i in range(10):
    print(f.__next__())