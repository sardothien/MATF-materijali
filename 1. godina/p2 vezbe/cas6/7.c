/* Napisati program koji u datom, rastuce sortiranom nizu
pronalazi prvi element veci od 100. Ukoliko je element nadjen,
na standarni izlaz ispisati njegovu vrednost, a u suprotnom
ispisati ”-”. U slucaju greske na standardni izlaz za greske
ispisati -1. */

#include <stdio.h>
#include <stdlib.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

int poredi(int a, int b){
 return a-b;
}

int main(){
 int n;
 scanf("%d", &n);
 if(n<=0)
  greska();

 int *niz;
 niz=malloc(n*sizeof(int));
 int i; 
 for(i=0; i<n; i++)
  scanf("%d", &niz[i]);
 
 int m=100;
 int br=0;
 for(i=0; i<n; i++){
  if(poredi(m, niz[i])<0){
   printf("%d\n", niz[i]);
   br++;
   break;
  }
 }
 
 if(br==0)
  printf("-\n");
 
 free(niz);
 
 return 0;
}
