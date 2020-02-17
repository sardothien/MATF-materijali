/* Napisati funkcije za rad sa nizovima celih brojeva.
(a) Napisati funkciju koja proverava da li niz sadrži zadatu vrednost
m. Povratna vrednost funkcije je 1 ako je vrednost sadržana u nizu ili
0 ako nije.
(b) Napisati funkciju koja vraća vrednost prve pozicije na kojoj se
nalazi element koji ima vrednost m ili −1 ukoliko element nije u nizu.
(c) Napisati funkciju koja vraća vrednost poslednje pozicije na kojoj
se nalazi element koji ima vrednost m ili −1 ukoliko element nije u
nizu.
(d) Napisati funkciju koja proverava da li elementi niza čine palindrom.
(e) Napisati funkciju koja proverava da li su elementi niza uređeni
neopadajuće.
Napisati i program koji testira rad napisanih funkcija za uneti broj m
i niz čija dimenzija nije veća od 100. */

#include <stdio.h>
#define MAX 100

void ucitaj(int a[], int m){
 int i;
 for(i=0; i<m; i++){
  scanf("%d" ,&a[i]);
 }
}


void stampaj(int a[], int m){
 int i;
 for(i=0; i<m; i++)
  printf("%d ",a[i]);
 printf("\n");
}

/* POD a) */
int sadrzi_n(int a[], int m, int n){
 int i;
 for(i=0; i<m; i++){
  if(a[i]==n){
   return 1;
  }
 }
 return 0;
}
/* POD b) */
int pozicija(int a[], int m, int n){
 int i, poz;
 for(i=0; i<m; i++){
  if(a[i]==n){
   poz=i;
   break;
  }
 }
 return poz;
} 
/* POD c) */
int poslpozicija(int a[], int m, int n){
 int i, poz;
 for(i=0; i<m; i++){
  if(a[i]==n){
   poz=i;
  }
 }
 return poz;
} 
/* POD d) */
int palindrom(int a[], int m){
 int i, j;
 for(i=0, j=m-1; i<j; i++, j--){
  if(a[i]!=a[j]){
   return 0;
  }
 }
 return 1;
}
/* POD e) */
int uredjenje(int a[], int m){
 int i;
 for(i=0; i<m-1; i++){
  if(a[i]>a[i+1]){
   return 0;
  }
 }
 return 1;
}


int main(){
 int m, n;
 int a[MAX];
 
 scanf("%d", &m);
 if(m<1 || m>MAX){
  printf("-1\n");
  return -1;
 }
 
 ucitaj(a, m);
 stampaj(a, m);
 
 scanf("%d", &n);
 if(sadrzi_n(a, m, n)){
  printf("Sadrzi n.\n");
  printf("Pozicija 1. pojavljivanja: %d\n", pozicija(a, m, n));
  printf("Pozicija poslednjeg pojavljivanja: %d\n", poslpozicija(a, m, n));
 }
 else{
  printf("Ne sadrzi n.\n");
  printf("-1\n");
  printf("-1\n");
 }
 
 if(palindrom(a, m)){
  printf("Jeste palindrom.\n");
 }
 else{
  printf("Nije palindrom.\n");
 }
 
 if(uredjenje(a, m)){
  printf("Sortiran neopadajuce\n");
 }
 else{
  printf("Nije sortiran neopadajuce.\n");
 }
 
 return 0;
}
