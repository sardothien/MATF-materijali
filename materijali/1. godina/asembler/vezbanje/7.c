#include <stdio.h>
#include <stdlib.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

int suma_razlika(int*, int);

int main(){
 int n;
 scanf("%d", &n);
 
 int *niz=malloc(n*sizeof(int));
 if(niz==NULL)
  greska();
 
 int i;
 for(i=0; i<n; i++)
  scanf("%d", &niz[i]);
  
 printf("%d\n", suma_razlika(niz, n));
 
 free(niz);
  
 return 0;
}
