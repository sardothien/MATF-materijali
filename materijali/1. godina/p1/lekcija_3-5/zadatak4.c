/* Definisati strukturu Grad u kojoj se nalazi ime grada (niska
dužine 20 karaktera) i prosečna temperatura u toku decembra
(realan broj). Napisati program koji učitava imena n (0<n<50)
gradova i njihove prosečne temperature, a zatim ispisuje one
gradove koji imaju idealnu temperaturu za klizanje: od 3 do 8
stepeni. */

#include <stdio.h>
#define MAX 21
#define MAXG 50

typedef struct {
 char grad[MAX];
 float temperatura;
}GRAD;

/* MAIN */
int main(){
 int n, i;
 GRAD niz[MAXG];
 
 scanf("%d", &n);
 for(i=0; i<n; i++){
  scanf("%s%f", niz[i].grad, &niz[i].temperatura);
 }
 
 for(i=0; i<n; i++){
  if(niz[i].temperatura>=3 && niz[i].temperatura<=8){
   printf("%s\n", niz[i].grad);
  }
 }
 
 return 0; 
}
