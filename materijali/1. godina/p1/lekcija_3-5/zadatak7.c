/* Statistički zavod Srbije istražuje kako rade obdaništa
u Srbiji. Za dato obdanište dobija spisak n dece sa
kolonama: pol (m ili z), broj godina (od 3 do 6) i ocena
koju je dete dalo radu obdaništa (od 1 do 5). Maksimalan
broj dece u obdaništu je 200. Napisati program koji za
decu datog pola i broja godina ispisuje na tri decimale
prosečnu ocenu obdaništa. U slučaju neispravnog
unosa ispisati odgovarajuću poruku. */

#include <stdio.h>
#include <ctype.h>
#define MAX 200

typedef struct obd{
 char pol;
 int godine;
 int ocena;
}OBDANISTE;

int main(){
 int n, i, g; 
 int s=0, br=0;
 char p;
 OBDANISTE niz[MAX];
 
 scanf("%d", &n);
 for(i=0; i<n; i++){
  getchar();
  scanf("%c%d%d", &niz[i].pol, &niz[i].godine, &niz[i].ocena);
  getchar();
 }
 
 scanf("%c%d", &p, &g);
 for(i=0; i<n; i++){
  if(niz[i].pol==p && niz[i].godine==g){
   s=s+niz[i].ocena;
   br++;
  }
 }
 
 printf("%.3f\n", (double)s/br); 
 
 return 0;
}
