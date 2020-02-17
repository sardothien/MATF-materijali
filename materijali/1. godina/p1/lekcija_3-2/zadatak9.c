/* Napisati funkciju void par_nepar(int a[], int n, int
parni[], int* pn, int neparni[], int* nn) koja razbija niz a na niz parnih
i niz neparnih brojeva. Pokazivači pn i nn redom treba da sadrže broj elemenata
niza parnih tj. niza neparnih elemenata. Pretpostaviti da dužina niza a neće biti
veća od 50. Napisati program koji testira napisanu funkciju. */

#include <stdio.h>
#define MAX 50

void par_nepar(int a[], int n, int parni[], int* pn, int neparni[], int* nn){
 int i, j, k;
 for(i=0, j=0, k=0; i<n; i++){
  if(a[i]%2==0){
   parni[j]=a[i];
   j++;
  }
  else{
   neparni[k]=a[i];
   k++;
  }
 }
  
 *pn=j;
 *nn=k;
}

int main(){
 int n, i, j, pn, nn;
 int a[MAX], parni[MAX], neparni[MAX];

 scanf("%d", &n);
 if(n<0 || n>MAX){
  printf("-1\n");
  return -1;
 }
  
 for(i=0; i<n; i++){
   scanf("%d", &a[i]);
 }
  
 par_nepar(a, n, parni, &pn, neparni, &nn);
  
 for(i=0; i<pn; i++){
  printf("%d ", parni[i]);
 }
 printf("\n");

 for(i=0; i<nn; i++){
  printf("%d ", neparni[i]);
 }
 printf("\n");  

 return 0;
}
