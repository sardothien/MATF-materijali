/* a) Definisati strukturu DUEL koja sadri podatke o
nazivima dva fudbalska kluba (niske duzine najvise 20
karaktera), broju golova koje je domacin postigao, broju
golova koje je gost postigao kao i nazivu stadiona (niska
duzine najvie 30 karaktera) na kome je duel odigran.

b) Sa standardnog ulaza se unosi broj n, 1 ≤ n ≤ 1000, a
zatim n duela u obliku naziv kluba domacina, naziv gostujueg
kluba, naziv stadiona, broj golova domaina broj golova
gosta. Brojevi golova su nenegativni celi brojevi. Na
standardni izlaz ispisati naziv stadiona na kome je
postignuta najvea gol razlika (apsolutna vrednost razlike
golova domaina i gosta). Nazivi klubova i stadiona se unose
u zasebnim linijama teksta, pretpostaviti da nee postojati
vise stadiona sa najvecom gol razlikom. U slucaju
neispravnog ulaza, na standardni izlaz ispisati -1. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_KLUB 21
#define MAX_STADION 31
#define MAX_DUEL 1000

typedef struct {
 char domacin[MAX_KLUB];
 char gost[MAX_KLUB];
 int gol_dom;
 int gol_gost;
 char stadion[MAX_STADION];
} DUEL;

int main(){
 int n, i;
 DUEL niz[MAX_DUEL];
 
 scanf("%d", &n);
 getchar();
 if(n<1 || n>1000){
  printf("-1\n");
  return -1;
 }
 
 for(i=0; i<n; i++){
  gets(niz[i].domacin);
  gets(niz[i].gost);
  gets(niz[i].stadion);
  scanf("%d", &niz[i].gol_dom);
  scanf("%d", &niz[i].gol_gost);
  getchar();
  if(niz[i].gol_dom<0 || niz[i].gol_gost<0){
   printf("-1\n");
   return -1;
  }
 }
 
 int indeks_max=0; 
 for(i=1; i<n; i++){
  if(abs(niz[i].gol_dom-niz[i].gol_gost)>abs(niz[indeks_max].gol_dom-niz[indeks_max].gol_gost))
    indeks_max = i;
 }
    
 printf("%s\n", niz[indeks_max].stadion);
 
 return 0;
}
