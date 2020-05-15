/* Napisati funkcije za rad sa nizovima celih brojeva.
(a) Napisati funkciju void ucitaj(int a[], int n) koja učitava elemente
niza a dimenzije n.
(b) Napisati funkciju void stampaj(int a[], int n) koja štampa elemente
niza a dimenzije n.
(c) Napisati funkciju int suma(int a[], int n) koja računa i vraća sumu
elemenata niza a dimenzije n.
(d) Napisati funkciju float prosek(int a[], int n) koja računa i vraća
prosečnu vrednost (aritmetičku sredinu) elemenata niza a dimenzije n.
(e) Napisati funkciju int minimum(int a[], int n) koja izračunava i
vraća minimum elemenata niza a dimenzije n.
(f) Napisati funkciju int pozicija_maksimuma(int a[], int n) koja
izračunava i vraća poziciju maksimalnog elementa u nizu a dimenzije n.
U slučaju više pojavljivanja maksimalnog elementa, vratiti najmanju
poziciju.
Napisati program koji testira rad zadatih funkcija. Sa standardnog
ulaza učitati dimenziju niza (broj ne veći od 100). */

#include <stdio.h>
#define MAX 100
/* POD a) */ 
void ucitaj(int a[], int n){
 int i;
 for(i=0; i<n; i++){
  scanf("%d", &a[i]);
 }
}
/* POD b) */ 
void stampaj(int a[], int n){
 int i;
 for(i=0; i<n; i++){
  printf("%d ", a[i]);
 }
 printf("\n");
}
/* POD c) */
int suma(int a[], int n){
 int s=0, i;
 for(i=0; i<n; i++){
  s+=a[i];
 }
 return s;
}
/* POD d) */
float prosek(int a[], int n){
 int s;
 s=suma(a, n);
 return (float) s/n;
}
/* POD e) */
int minimum(int a[], int n){
 int i, min;
 min=a[0];
 for(i=0; i<n; i++){
  if(a[i]<min){
   min=a[i];
  }
 }
 return min;
}
/* POD f) */
int pozicija_maksimuma(int a[], int n){
 int i, max, maxp;
 max=a[0];
 for(i=0; i<n; i++){
  if(a[i]>max){
   max=a[i];
   maxp=i;
  }
 }
 return maxp;
}

/* MAIN */ 
int main(){
 int n;
 int a[MAX];
 
 scanf("%d", &n);
 if(n<0 || n>MAX){
  printf("-1\n");
  return -1;
 }
 
 ucitaj(a, n);
 stampaj(a, n);
 printf("%d\n", suma(a, n));
 printf("%.2f\n", prosek(a, n));
 printf("%d\n", minimum(a, n)); 
 printf("%d\n", pozicija_maksimuma(a, n));
 
 return 0;
}
