#include <stdio.h>
#include <stdlib.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

int izdvoji_proste(int*, int, int*);

int main(){
 int n, nb;
 int *a, *b;
 
 scanf("%d", &n);
 if((a=malloc(n*sizeof(int))) == NULL)
  greska();
 if((b=malloc(n*sizeof(int))) == NULL)
  greska();

 int i;
 for(i=0; i<n; i++)
  scanf("%d", &a[i]);
 
 nb = izdvoji_proste(a, n, b); 
 
 for(i=0; i<nb; i++)
  printf("%d ", b[i]);
 
 free(a);
 free(b);
  
 printf("\n");
  
 return 0;
}