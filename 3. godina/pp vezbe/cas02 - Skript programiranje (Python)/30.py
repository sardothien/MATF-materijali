# Implementirati klasu MyIterator koja predstavlja iterator
# od 0 do n, pri cemu je n atribut klase.

class MyIterator:
    def __init__(self, n):
        self.n = n

    def __iter__(self):
        self.x = 0
        return self

    def __next__(self):
        x = self.x
        if x > self.n:
            raise StopIteration
        else:
            self.x += 1
            return x

for i in MyIterator(10):
    print(i, end=' ')
print()