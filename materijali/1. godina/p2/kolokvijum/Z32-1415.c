/* Sa standardnog ulaza se ucitava ceo broj n(n ≤ 100), a
potom i niz od n celih brojeva. Napisati rekurzivnu funkciju
void f(int a[], int n) koja u nizu a postavlja na nulu sve
elemente koji su (u pocetnom nizu) jednaki zbiru svojih
suseda. Rezultujuci niz ispisati na standardni izlaz. U
slucaju greske ispisati -1 na standardni izlaz za greske.
Napomena: Zadatak mora biti uradjen rekurzivno. Nije
dozvoljeno koriscenje statickih i globalnih promenljivih,
menjanje zaglavlja funkcije i pisanje pomocnih funkcija. */

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

void f(int a[], int n){
 if(n<=2)
  return;
 
 int a0, a1, a2;
 a0=a[0];
 a1=a[1];
 a2=a[2];
 
 
 if(a1==a0+a2){
  printf("0 ");
 }
 else{
  printf("%d ", a[1]);
 }
 f(a+1, n-1);
}


int main(){
 int n;
 scanf("%d", &n);
 if(n>MAX)
  greska();
 
 int niz[MAX];
 int i;
 for(i=0; i<n; i++)
  scanf("%d", &niz[i]);
 printf("%d ", niz[0]);
 f(niz, n);
 printf("%d ", niz[n-1]);
 printf("\n");
 
 return 0;
}
