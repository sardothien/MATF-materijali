#include <stdio.h>
#include <stdlib.h>
#define MAX 200

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

void faktorizacija(int, int*, int*, int*);

int main(){
 int x;
 scanf("%d", &x);
 
 int *a, *b;
 a = malloc(MAX*sizeof(int));
 b = malloc(MAX*sizeof(int));
 if(a == NULL)
  greska();
 if(b == NULL)
  greska();
   
 int velicina;
 
 faktorizacija(x, a, b, &velicina);
  
 int i;
 for(i=0; i<velicina; i++)
  printf("%d ", a[i]); 
 printf("\n"); 
 for(i=0; i<velicina; i++)
  printf("%d ", b[i]);
 printf("\n"); 
 
 free(a);
 free(b); 
 
 return 0;
}
