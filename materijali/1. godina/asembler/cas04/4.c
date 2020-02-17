#include <stdio.h>
#include <stdlib.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

void fibonaci(int, int*);

int main(){
 int n;
 int *a;
 
 scanf("%d", &n);
 if((a=malloc(n*sizeof(int))) == NULL)
  greska();

 fibonaci(n, a); 

 int i;
 for(i=0; i<n; i++)
  printf("%d ", a[i]);
 
 free(a);
  
 printf("\n");
  
 return 0;
}