/* a. Napisati funkciju koja prima ceo broj i vraca njegovu
      vrednost uvecanu za 1
   b. Napisati funkciju koja prima ceo broj i vraca njegovu
      vrednost na kvadrat
   c. Napisati funckiju koja prima ceo broj i vraca
     -1*vrednost prosledjenog broja
Napisati funkciju modifikuj koja prima niz, dimenziju niza i
funkciju modifikacije koju treba primeniti na svaki clan
niza. Testirati ovu funkciju pozivom iz main-a, za gore
navedene funkcije. */

#include <stdio.h>
#include <stdlib.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

int a(int x){
 return x+1;
}

int b(int x){
 return x*x;
}

int c(int x){
 return -1*x;
}

void modifikuj(int *niz, int n, int (*modifikacija)(int)){
 int i;
 for(i=0; i<n; i++){
  niz[i]=modifikacija(niz[i]); 
  printf("%d ", niz[i]);
 }
}

int main(){
 int n;
 int *niz;
 scanf("%d", &n);
 if(n<=0)
  greska();
 
 niz=malloc(n*sizeof(int));
 if(niz==NULL)
  greska();
 
 int i;
 for(i=0; i<n; i++)
  scanf("%d", &niz[i]);
 
 printf("Uvecano za 1: ");
 modifikuj(niz, n, &a);
 printf("\n");
 printf("Kvadrat: ");
 modifikuj(niz, n, &b);
 printf("\n");
 printf("Suprotan broj: ");
 modifikuj(niz, n, &c);
 printf("\n");
 
 free(niz);
 
 return 0;
}
