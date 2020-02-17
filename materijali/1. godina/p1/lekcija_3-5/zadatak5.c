/* Definisati strukturu ParReci koja sadrži reč na srpskom
jeziku i odgovarajući prevod na engleski jezik. Napisati program koji do
kraja ulaza učitava sve parove reči, a potom za rečenicu koja se zadaje
u jednoj liniji ispisati prevod. Ako je reč u rečenici nepoznata umesto
nje ispisati odgovarajući broj zvezdica. Maksimalna dužina reči je 50
karaktera, ukupan broj parova reči je maksimalno 100, a maksimalna
dužina rečenice je 100 karaktera. */

#include <stdio.h>
#include <string.h>

#define MAX_DUZINA 50
#define MAX_BR_RECI 100

typedef struct ParReci{
 char sr[MAX_DUZINA+1];
 char en[MAX_DUZINA+1];
}PR;

void proprevod(PR recnik[], int n, char rec[], char prevod[]){
 int i;
	
 for(i=0; i<n; i++){
  if(strcmp(recnik[i].sr, rec)==0){
   strcpy(prevod, recnik[i].en);
   return;
  }
 }
 for(i=0; rec[i]; i++){
  prevod[i]='*';
 }
 
 prevod[i]='\0';
}


int main(){
 PR recnik[MAX_BR_RECI];
 int n, j, i, k;
 char sr[MAX_DUZINA+1];
 char en[MAX_DUZINA+1];
 char rec[MAX_DUZINA+1];
 char prevod[MAX_DUZINA+1];	
 char c;
	
 i=0;
 while(scanf("%s %s", sr, en)!=EOF){
  if(i==MAX_BR_RECI)
    break;
  strcpy(recnik[i].sr, sr);
  strcpy(recnik[i].en, en);
  i++;
 }

 n=i;
 do{
  scanf("%s", rec);
  proprevod(recnik, n, rec, prevod);
  printf("%s ", prevod);
  c = getchar();
 } while(c != '\n');

 putchar('\n');
 				
 return 0;	
}
