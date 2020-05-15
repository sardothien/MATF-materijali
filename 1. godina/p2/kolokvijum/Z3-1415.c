/* Sa standardnog ulaza se ucitava ceo broj x, ceo broj n 
(n ≤ 100), a potom i niz od n celih brojeva. Napisati rekurzivnu
funkciju void f(int a[], int n, int x), koja u nizu a poslavlja
na nulu sve parove susednih elementa ciji je zbir (u pocetnom
nizu) jednak x. Rezultujuci niz ispisati na standardni
izlaz. U slucaju greske ispisati -1 na standardni izlaz za
greske. Napomena: Zadatak mora biti uradjen rekurzivno. Nije
dozvoljeno koriscenje statickih i globalnih promenljivih,
menjanje zaglavlja funkcije i pisanje pomocnih funkcija. */

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

void f(int a[], int n, int x){
 if(n<=1)
  return;
 
 int a0, a1;
 a0=a[0];
 a1=a[1];
 
 f(a+1, n-1, x);
 if(a0+a1==x){
  a[0]=0;
  a[1]=0; 
 }
}

void ispisi_niz(int *niz, int n){
 if(n==0)
  return;
 
 printf("%d ", niz[0]);
 ispisi_niz(niz+1, n-1); 
}

int main(){
 int n, niz[MAX], x;
 scanf("%d%d", &x, &n);
 if(n>MAX)
  greska(); 
  
 int i;
 for(i=0; i<n; i++){
  scanf("%d", &niz[i]);
 } 
 
 f(niz, n, x);
 ispisi_niz(niz, n);
 printf("\n");
 
 return 0;
}
