/* Definisati strukturu: 
typedef struct{
int x;
int y;
int z;
} VEKTOR;
kojom se opisuje trodimenzioni vektor. U datoteci
vektori.txt nalazi se nepoznati broj vektora. Na 
standarni izlaz ispisati koordinate vektora sa 
najvecom duzinom. Duzina vektora se izracunava po
formuli: |v| = koren(x^2+y^2+z^2). U slucaju greske
na standardni izlaz za greske ispisati -1. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

typedef struct{
 int x;
 int y;
 int z;
} VEKTOR;

int main(){
 FILE *in=fopen("vektori.txt", "r");
 if(in==NULL)
  greska();
 
 int n;
 fscanf(in, "%d", &n);
 if(n<=0)
  greska();
 
 int i;
 float max=0;
 float duzina;
 int x, y, z;
 VEKTOR koord;
 for(i=0; i<3*n; i+=3){
  fscanf(in, "%d%d%d", &koord.x, &koord.y, &koord.z);
  duzina=sqrt(koord.x*koord.x + koord.y*koord.y + koord.z*koord.z);
  if(duzina>max){
   max=duzina;
   x=koord.x;
   y=koord.y;
   z=koord.z;
  }
 }
 
 fclose(in);
 
 if(max!=0){
  printf("%d %d %d\n", x, y, z);
 }
 
 return 0;
}
