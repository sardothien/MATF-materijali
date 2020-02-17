/* Napisati rekurzivnu funkciju void f3(int *a, int na, int suma
prethodnih) koja u u nizu a, duzine na, postavlja vrednost
svakog broja na 0 ukoliko je veci od sume prethodnih brojeva u
nizu. Napisati program koji testira ovu funkciju, tako sto sa
standardnog ulaza ucitava broj na, zatim vrednosti niza a, i na
standardni izlaz ispisuje izmenjeni niz. U slucaju greske
ispisati -1 na standardni izlaz za greske. Napomena: Zadatak
mora biti uradjen rekurzivno. Nije dozvoljeno koriscenje
statickih i globalnih promenljivih, menjanje zaglavlja funkcije
i pisanje pomocnih funkcija. */

#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

void f3(int *a, int na, int suma_prethodnih){
 if(na==0)
  return;
 
 int nova_suma=suma_prethodnih+a[0];
 if(a[0]>suma_prethodnih)
  a[0]=0;  
 
 printf("%d ", a[0]); 
 f3(a+1, na-1, nova_suma);
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
 
 f3(niz, na, 0);
 printf("\n");
 
 return 0;
}
