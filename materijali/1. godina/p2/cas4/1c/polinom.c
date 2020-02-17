#include <stdio.h>
#include <stdlib.h>
#include "polinom.h"

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

/* a) Funkcija kojom se unose koeficijenti P(x) */
int* unos(int* n){
 scanf("%d", n);
 if(n<=0)
  greska();
  
 int *niz, k=*n;
 niz=malloc((k+1)*sizeof(int));
 if(niz==NULL)
  greska();
   
 int i;
 for(i=0; i<k+1; i++){
  scanf("%d", &niz[i]);
 } 
 return niz;
}

/* b) Ispisuje se P(x) */
void ispis_polinoma(int *niz, int n){
 int i;
 
 for(i=0; i<=n; i++){
  if(niz[i]==0){
   continue;
  }
  else{
   if(i==0){
    printf("%d ", niz[i]);
   }
   else if(i==1){
    printf("%c %d*x ", niz[i]<0 ? '-':'+', abs(niz[i]));
   }
   else{
    printf("%c %d*x^%d", niz[i]<0 ? '-':'+', abs(niz[i]), i);
   }
  }
 }
}

/* MIN i MAX */
int max(int m, int n){
 int max=m;
 if(n>m){
  max=n;
 }
 return max;
}
int min(int m, int n){
 int min=m;
 if(n<m){
  min=n;
 }
 return min;
}

/* v) Sumira 2 polinoma */
int suma_polinoma(int* a, int n, int* b, int m, int** c){
 int i;
 *c=malloc((max(m,n)+1)*sizeof(int));
 if(*c==NULL)
  greska();
  
 for(i=0; i<=min(m,n); i++){
  (*c)[i]=a[i]+b[i];
 }
 for(; i<=n; i++){
  (*c)[i]=a[i];
 }
 for(; i<=m; i++){
  (*c)[i]=b[i];
 } 
 return max(m,n);
}

/* g) Polinom se mnozi skalarom */
void mnoz_skalarom(int *a, int n, int c){
 scanf("%d", &c);
 if(c==0)
  printf("0");
 else{
  int i;
  for(i=0; i<=n; i++){
   a[i]=a[i]*c;
  } 
  ispis_polinoma(a, n);
 }
}

/* d) Vrednost P(x) u x preko Horneove seme */
int vr_poly(int* a, int n, int x){
 int s=a[n+1];
 scanf("%d", &x);
 int i;
 for(i=n; i>=0; i--){
  s=s*x+a[i];
 }
 return s; 
}

int mul_poly(int* a, int n, int* b, int m, int** c){
 int *rez=calloc(m+n+1, sizeof(int));
 if(rez==NULL)
  greska();
 
 int i, j;
 for(i=0; i<=n; i++){
  for(j=0; j<=m; j++){
   rez[i+j]+= a[i]*b[j];
  }
 }
  
 *c=rez;
 return n+m; 
}
