/* Napisati program koji učitava najpre broj različitih
prodavnica (ceo broj manji od 50) a zatim i podatke o ceni
traženog artikla – zadaje se naziv prodavnice (niske maksimalne
dužine 20 karaktera) i cena u toj prodavnici (realan broj).
Korisnik zadaje željenu cenu proizvoda, a program ispisuje
imena svih onih prodavnica u kojima je cena proizvoda jednaka
ili manja od željene. U slučaju greške ispisati odgovarajuću
poruku. */

#include <stdio.h>
#define MAX_N 50
#define MAX 21

typedef struct {
 char naziv[MAX];
 float cena;
}PODACI;

int main(){
 int n, i;
 float zeljena_cena;
 PODACI niz[MAX_N];
 
 scanf("%d", &n);
 if(n<=0 || n>=50){
  printf("-1\n");
  return -1;
 }
 
 for(i=0; i<n; i++){
  scanf("%s%f", niz[i].naziv, &niz[i].cena);  
 }
 
 scanf("%f", &zeljena_cena);
 for(i=0; i<n; i++){
  if(niz[i].cena<zeljena_cena){
   printf("%s\n", niz[i].naziv);
  }
 }
 
 return 0;
}
