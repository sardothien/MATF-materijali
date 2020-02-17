/* Zimi su prehlade česte i treba unositi više vitamina C.
Struktura V ocka sadrži ime voćke (nisku maksimalne dužine 20 karaktera)
i količinu vitamina C u miligramima (realan broj). Napisati program koji
učitava podatke o voćkama sve do unosa reči KRAJ i ispisuje ime voćke sa
najviše vitamina C. Pretpostaviti da broj voćki neće biti veći od 50. */

#include <stdio.h>
#include <string.h>

#define MAX_DUZINA 21
#define MAX_BR_VOCKI 50

typedef struct vocka{
  char ime[MAX_DUZINA];
  float vitamin;
} VOCKA;

int main(){
  VOCKA vocke[MAX_BR_VOCKI];
  int i = 0, n, max_vocka;
  char ime[MAX_DUZINA];

  do{
   scanf("%s",ime);
   if(strcmp(ime, "KRAJ") == 0)
     break;
   strcpy(vocke[i].ime,ime);
   scanf("%f", &vocke[i].vitamin);
   i++;
  } while(i<MAX_BR_VOCKI);

  n = i;

  max_vocka = 0;
  for(i=1; i<n; i++)
    if(vocke[i].vitamin > vocke[max_vocka].vitamin){
      max_vocka = i;
    }

  printf("%s\n", vocke[max_vocka].ime);
  
  return 0;
}
