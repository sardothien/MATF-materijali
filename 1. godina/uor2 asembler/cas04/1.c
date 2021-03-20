#include <stdio.h>
#include <stdlib.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

int suma(int*, int);

int main(){
 int n;
 int *a;
 
 scanf("%d", &n);
 if((a=malloc(n*sizeof(int))) == NULL)
  greska();
  
 int i;
 for(i=0; i<n; i++)
  scanf("%d", &a[i]);
  
 printf("%d\n", suma(a, n));
 
 return 0;
}