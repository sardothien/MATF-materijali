/* Napisati rekurzivnu funkciju void f3(int *a, int na) koja u
pocetnom nizu a, duzine na, smanjuje vrednost broja za 1 ukoliko
je on paran, i nakon njega se nalazi paran broj. Kreirati
program koji testira ovu funkciju, tako sto sa standardnog ulaza
ucitava broj na(0 ≤ na ≤ 1000), zatim vrednosti niza a, i na
standardni izlaz ispisuje vrednosti izmenjenog niza. U slucaju
greske ispisati -1 na standardni izlaz za greske. Napomena:
Zadatak mora biti uradjen rekurzivno. Nije dozvoljeno koriscenje
statickih i globalnih promenljivih, menjanje zaglavlja funkcije
i pisanje pomocnih funkcija. */

#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

void f3(int *a, int na){
 if(na<=1)
  return;
 
 if(a[0]%2==0 && a[1]%2==0){
  a[0]--;
  printf("%d ", a[0]);
 }
 else
  printf("%d ", a[0]); 
 
 f3(a+1, na-1); 
}

int main(){
 int na;
 int niz[MAX];
 scanf("%d", &na);
 if(na<0 || na>1000)
  greska();
  
 int i;
 for(i=0; i<na; i++)
  scanf("%d", &niz[i]);
 
 f3(niz, na);
 printf("%d", niz[na-1]);
 printf("\n");
 
 return 0;
}
