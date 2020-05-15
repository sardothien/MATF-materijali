/* Napisati funkciju unsigned int apsolutna_vrednost(int x) 
koja izračunava apsolutnu vrednost broja x. Napisati program koji 
učitava jedan ceo broj i ispisuje rezultat poziva funkcije. */

#include <stdio.h>
#include <stdlib.h>

int apsolutna_vrednost(int x){
 
 x=abs(x);
 
 return x; 
}

int main(){
 
 int x;
 scanf("%d", &x);
 
 printf("%d\n", apsolutna_vrednost(x));
 
 return 0;
}
