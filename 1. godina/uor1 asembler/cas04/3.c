#include <stdio.h>
#include <stdlib.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

void obrni(long*, int);

int main(){
 int n;
 long *a;
 
 scanf("%d", &n);
 if((a=malloc(n*sizeof(long))) == NULL)
  greska();
  
 int i;
 for(i=0; i<n; i++)
  scanf("%ld", &a[i]);
  
 obrni(a, n);
 for(i=0; i<n; i++)
  printf("%ld ", a[i]);
 
 free(a);
  
 printf("\n");
  
 return 0;
}