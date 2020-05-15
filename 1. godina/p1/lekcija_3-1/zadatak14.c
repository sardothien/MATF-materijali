/* Napisati funkcije za rad sa nizovima celih brojeva.
(a) Napisati funkciju koja sve vrednosti niza uvećava za zadatu vrednost m.
(b) Napisati funkciju koja obrće elemente niza.
(c) Napisati funkciju koja rotira niz ciklično za jedno mesto u levo.
(d) Napisati funkciju koja rotira niz ciklično za k mesta u levo.
Napisati i program koji testira rad napisanih funkcija za uneti broj m i niz čija dimenzija nije veća od 100.*/

#include <stdio.h>

#define MAX 100

void ucitaj(int a[], int n){
 int i;
 for(i=0; i<n; i++){
  scanf("%d", &a[i]);
 }
}

void ispisi(int a[], int n){
 int i;
 for(i=0; i<n; i++){
  printf("%d ", a[i]);
 }
 printf("\n");
}
/* Pod a) */
void uvecaj(int a[], int n, int m){
 int i;
 for(i=0; i<n; i++){
  a[i]=a[i]+m;
 }
}
/* Pod b) */
void obrnuto(int a[], int n){
 int i, j=n-1, m; 
 for(i=0; i<n/2; i++){
  m=a[i];
  a[i]=a[j];
  a[j]=m;
  j--;
 }
}
/* Pod c) */
void rotiraj(int a[], int n){
 int i, pom=a[0]; 
 for(i=0; i<n-1; i++){
  a[i]=a[i+1];
 }
 a[n-1]=pom;
}
/* Pod d) */
void rotirajK(int a[], int n, int k){
 while(k>0){
  rotiraj(a, n);
  k--;
 }
}

int main(){

 int a[MAX];
 int n, m, k;
 
 scanf("%d%d%d", &n, &m, &k); 
 if(n<=0 || n>100){
  printf("-1\n");
  return -1;
 }
 
 ucitaj(a, n);
 uvecaj(a, n, m);
 ispisi(a, n);
 obrnuto(a, n);
 ispisi(a, n);
 rotiraj(a, n);
 ispisi(a, n);
 rotirajK(a, n, k);
 ispisi(a, n);
 
 return 0;
}
