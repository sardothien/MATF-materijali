/* Definisati strukturu Lopta sa poljima poluprecnik (ceo
broj u centimetrima) i boja (enumeracioni tip koji uključuje plavu,
žutu, crvenu i zelenu boju). Zatim učitati informacije o n lopti 
0 < n < 50) i ispisati ukupnu zapreminu, kao i broj crvenih lopti. 
U slučaju greške ispisati odgovarajuću poruku. */

#include <stdio.h>
#include <math.h>

#define MAX 50

typedef struct lopta{
  int poluprecnik; 
  enum {plava, zuta, crvena, zelena} boja; 
}LOPTA;

float zapremina(LOPTA l){
 return pow(l.poluprecnik, 3)*4/3*M_PI;
}

float ukupna_zapremina(LOPTA lopte[], int n){
  int i;
  float z = 0;
  for(i = 0; i < n; i++)
    z += zapremina(lopte[i]);
  return z;
}

int broj_lopti_u_boji(LOPTA lopte[], int n, int boja){
  int br = 0;
  int i;
  for(i = 0; i < n; i++)
    if(lopte[i].boja == boja)
      br++;
  return br;
}

int main(){
  LOPTA lopte[MAX];
  int n, i, boja;
    
  scanf("%d", &n);  
  if(n<1 || n>MAX){  
    printf("Nekorektan unos.\n");
    return 0;
  }
  
  for(i=0; i<n; i++){
    printf("%d. lopta: ", i+1);
    scanf("%d%d", &lopte[i].poluprecnik, &boja);
    switch(boja){    
      case 1: lopte[i].boja = plava; 
              break;
      case 2: lopte[i].boja = zuta; 
              break;
      case 3: lopte[i].boja = crvena;
              break;
      case 4: lopte[i].boja = zelena;
              break;
      default:printf("Nekorektan unos.\n");
	      return 0;
    }
  }
    
  printf("%.2f\n", ukupna_zapremina(lopte, n)); 
  printf("%d\n", broj_lopti_u_boji(lopte, n, crvena));

  return 0;
}
