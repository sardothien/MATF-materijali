/* Napisati funckiju void min_max(float a[], int n, float* min, float* max)
koja izračunava minimalni i maksimalni element niza a dužine n. Napisati
program koji učitava niz realnih brojeva maksimalne dužine 50 i ispisuje
vrednosti minimuma i maksimuma zaokruženu na tri decimale. */

#include<stdio.h>
#define MAX 50

void min_max(float a[], int n, float* min, float* max){	
 int i;
 *min=a[0];
 *max=a[0];

 for(i=1; i<n; i++){
  if(a[i]>*max){
   *max=a[i];
  }
  if(a[i]<*min){
   *min=a[i];
  }
 }
}

int main(){
 int i, n;
 float a[MAX], min, max;

 scanf("%d", &n);
 if(n<0 || n>MAX){
  printf("-1\n");
  return -1;
 }

 for(i=0; i<n; i++){
  scanf("%f", &a[i]);
 }

 min_max(a, n, &min, &max);	

 printf("Minimum: %.3f\n", min);
 printf("Maksimum: %.3f\n", max);
	
 return 0;	
}
