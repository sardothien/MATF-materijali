/* Napisati program koji u datom nizu brojeva koji su
uredjeni rastuce pronalazi trazeni broj i to:
a. Linearnom pretragom
b. Binarnom pretragom (iterativno)
c. Binarnom pretragom (rekurzivno)
d. Binarnom pretragom, koristeci funkciju bsearch
Ukoliko je element nadjen, na standarni izlaz ispisati
njegovu poziciju (broji se od 0), a u suprotnom -1.
U slucaju greske na standardni izlaz za greske ispisati -1. */

#include <stdio.h>
#include <stdlib.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}
// POD a)
int linearna_pretraga(int *niz, int n, int x){
 int i;
 for(i=0; i<n; i++){
  if(niz[i]==x)
   return i;
 }
 return -1;
}
// POD b)
int binarna_iterativno(int *niz, int n, int x){
 int d=n-1; //desna granica
 int l=0;   // leva granica
 int sr;    // sredina intervala
 while(l<=d){
  sr=l+(d-l)/2;
  if(niz[sr]==x)
   return sr;
  else if(niz[sr]<x)
   l=sr+1;
  else
   d=sr-1;
 }
 return -1;
}
// POD c)
int binarna_rekurzivno(int* niz, int l, int d, int x){
 if(l>d)
  return -1;
 
 int sr=l+(d-l)/2;
 if(x==niz[sr])
  return sr;
 else if(x>niz[sr])
  return binarna_rekurzivno(niz, sr+1, d, x);
 else
  return binarna_rekurzivno(niz, l, sr-1, x);
}
// POD d) Prvi argument je adresa trazenog elementa
//        Drugi argument je argument jednog elementa niza
int poredi(const void *x, const void *niz){
 return *(int*)x-*(int*)niz;
 /*ILI: int vr1=*(int*)a;
        int vr2=*(int*)b; 
        if(vr1==vr2) 
	  return 0;
        else if(vr1>vr2)
	  return 1; 
        else
	  return -1;*/
}

int main(){
 int n;
 int *niz;
 scanf("%d", &n);
 if(n<=0)
  greska(); 
 
 niz=malloc(n*sizeof(int));
 if(niz==NULL)
  greska();
 
 int i;
 for(i=0; i<n; i++)
  scanf("%d", &niz[i]);
 
 int x;
 scanf("%d", &x);
 
 printf("Linearna pretraga: %d\n", linearna_pretraga(niz,n,x));
 printf("Binarna pretraga (iterativno): %d\n", binarna_iterativno(niz, n, x));
 printf("Binarna pretraga (rekurzivno): %d\n", binarna_rekurzivno(niz, 0, n-1, x));

 //Pozivamo funkciju bsearch
 /* Argumenti:
	1. Pokazivac na vrednost koju trazimo
	2. Niz
	3. Broj elemenata niza
	4. Velicina jednog clana niza
	5. Funkcija za poredjenje (opisana u komentaru iznad)
     Povratna vrednost: 
	Ako je element nadjen - pokazivac na taj element 
	Ako element nije nadjen - NULL */
 int *p=bsearch(&x, niz, n, sizeof(int), &poredi);
 if(p==NULL)
  greska();
 else
  printf("bsearch: %ld\n", p-niz);
 
 free(niz);
  
 return 0;
}
