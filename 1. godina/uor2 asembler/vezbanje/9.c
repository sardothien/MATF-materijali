#include <stdio.h>
#include <stdlib.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

void izdvoji_deljive(int*, int, int*, int*);

int main(){
 int n;
 scanf("%d", &n);
 
 int *niz1=malloc(n*sizeof(int));
 if(niz1==NULL)
  greska();
 
 int i;
 for(i=0; i<n; i++)
  scanf("%d", &niz1[i]);
   
 int *niz2=malloc(n*sizeof(int));
 if(niz2==NULL)
  greska();
 
 int vrednost; 
 izdvoji_deljive(niz1, n, niz2, &vrednost);
 
 for(i=0; i<vrednost; i++) 
  printf("%d ", niz2[i]); 
 printf("\n");
 
 free(niz1);
 free(niz2);
   
 return 0;
}
