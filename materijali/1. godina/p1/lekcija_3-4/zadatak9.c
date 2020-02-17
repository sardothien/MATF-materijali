/* Data je kvadratna matrica dimenzije n × n.
(a) Napisati funkciju float trag(float a[][MAX], int n) koja računa trag
matrice, odnosno zbir elemenata na glavnoj dijagonali matrice.
(b) Napisati funckciju float suma_sporedna(float a[][MAX], int n) koja
računa zbir elemenata na sporednoj dijagonali matrice.
(c) Napisati funkciju float suma_iznad(float a[][MAX], int n) koja 
određuje sumu elememenata iznad glavne dijagonale.
(d) Napisati funkciju float suma_ispod(float a[][MAX], int n) koja 
određuje sumu elememenata ispod sporedne dijagonale matrice.
Napisati program koji za učitanu matricu realnih brojeva ispisuje na tri
decimale trag matrice, sumu na sporednoj dijagonali, sumu iznad glavne
dijagonale i sumu elemenata ispod sporedne dijagonale. Pretpostaviti da
je maksimalna dimenzija matrice 50 × 50. U slučaju greške ispisati
odovarajuću poruku. */

#include <stdio.h>
#include <stdlib.h>

#define MAX 50

void ucitavanje(float mat[][MAX], int* n){
 int i, j;
 scanf("%d", n);
 if(*n<=0 || *n>MAX){
  printf("-1\n");
  exit(EXIT_FAILURE);
 }

 for(i=0; i<*n; i++)
  for(j=0; j<*n; j++)
   scanf("%f", &mat[i][j]);
}

float trag(float a[][MAX], int n){
 float suma = 0;
 int  i;
 for(i=0; i<n; i++)
  suma += a[i][i];

 return suma;
}

float suma_sporedna(float a[][MAX], int n){
 float suma = 0;
 int  i;
 for(i=0; i<n; i++)
  suma += a[i][n-i-1];
  
 return suma;
}

float suma_iznad(float a[][MAX], int n){
 float suma = 0;
 int  i, j;
 for(i=0; i<n; i++)
  for(j=i+1; j<n; j++)
   suma += a[i][j];

 return suma;
}

float suma_ispod(float a[][MAX], int n){
 float suma = 0;
 int  i, j;
 for(i=n-1; i>0; i--)
  for(j=n-i; j<n; j++)
   suma += a[i][j];

 return suma;
}

int main(){
 float a[MAX][MAX];
 int n;

 ucitavanje(a, &n);

 printf("%.3f.\n", trag(a, n));
 printf("%.3f.\n", suma_sporedna(a, n));
 printf("%.3f.\n", suma_iznad(a, n));
 printf("%.3f.\n", suma_ispod(a, n));
 
 return 0;
}
