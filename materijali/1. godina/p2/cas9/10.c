/* Napisati funkciju koja ispituje da li je dati ceo broj n
stepen broja 2. Koristiti bitovske operatore. */

#include <stdio.h>

int suma_bitova(int x){
 unsigned n=sizeof(x)*8;
 unsigned maska=1<<(n-1);
 int suma=0;
 while(maska){
  if(x&maska)
   suma++;
  maska >>= 1;
 }
 return suma;
}

int main(){
 int x;
 scanf("%d", &x);
 
 if(suma_bitova(x)==1)
  printf("jeste\n");
 else
  printf("nije\n");
  
 return 0;
}
