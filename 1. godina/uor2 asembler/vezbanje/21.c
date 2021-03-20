#include <stdio.h>
#include <stdlib.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

void napravi(int*, int*, int, int*);

int main(){
 int n;
 scanf("%d", &n);
 
 int *x = malloc(n*sizeof(int));
 int *y = malloc(n*sizeof(int));
 if(x == NULL)
  greska();
 if(y == NULL)
  greska();
 
 int i;
 for(i=0; i<n; i++)
  scanf("%d", &x[i]);
 for(i=0; i<n; i++)
  scanf("%d", &y[i]);
 
 int *z = malloc(n*sizeof(int));
 if(z == NULL)
  greska();
  
 napravi(x, y, n, z);
 
 for(i=0; i<n; i++)
  printf("%d ", z[i]);
 printf("\n");
 
 free(x);
 free(y);
 free(z);
 
 return 0;
}
