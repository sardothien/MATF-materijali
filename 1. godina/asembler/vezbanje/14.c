#include <stdio.h>
#include <stdlib.h>

void greska(){
 printf("-1\n");
 exit(EXIT_FAILURE);
}

void napravi_niz(int*, int*, int, int*, int);

int main(){
 int n;
 int i;
 scanf("%d", &n);
 

 int *niz1=malloc(n*sizeof(int));
 int *niz2=malloc(n*sizeof(int));
 if(niz1==NULL)
  greska();
 if(niz2==NULL)
  greska();
 
 for(i=0; i<n; i++)
  scanf("%d", &niz1[i]); 
  
 for(i=0; i<n; i++)
  scanf("%d", &niz2[i]);
  
 int m;
 scanf("%d", &m);
 
 int *niz3=malloc(m*sizeof(int));
 if(niz3==NULL)
  greska(); 
  
 for(i=0; i<m; i++)
  scanf("%d", &niz3[i]);
 
 napravi_niz(niz1, niz2, n, niz3, m);
 
 for(i=0; i<m; i++)
  printf("%d ", niz3[i]);
 printf("\n");
  
 free(niz1);
 free(niz2);
 free(niz3);
 
 return 0;
}
