#include <stdio.h>
#include <stdlib.h>

unsigned izbaci_neparne(long *niz, unsigned duzina);

int main(){
 unsigned n;
 scanf("%u", &n);
 
 long *niz=malloc(n*sizeof(long));
 if(niz==NULL){
  printf("-1\n");
  return -1;
 }
 
 int i;
 
 for(i=0; i<n; i++)
  scanf("%ld", &niz[i]);
  
 n=izbaci_neparne(niz, n);
 
 for(i=0; i<n; i++)
  printf("%ld ", niz[i]);
 
 printf("\n");
 
 return 0;
}