# Napisati program koji sa standardnog ulaza ucitava ceo broj, koji 
# je otporan na pogresan ulaz. Nakon toga, ilustrovati imutabilnost stringova.

try:
    n = int(input("Uneti ceo broj: "))
except ValueError:
    print("Nije unet ceo broj!")
    exit(1)

# Imutabilnost stringova:
x = "Hello world"
print("x : ", x, id(x))
y = "Hello world"
print("y : ", y, id(y))
print(x == y)