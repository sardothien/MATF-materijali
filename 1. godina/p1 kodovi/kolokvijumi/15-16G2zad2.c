/* 2015/2016 - Kolokvijum GRUPA 2, zadatak 2 */
/* Korisnik unosi 7 karaktera koji predstavljaju indeks studenta koji je oblika OOGGBBB. OO je oznaka smera i moze biti mi, ma, mr, ms, mm, mp. GG je oznaka godine upisa. BBB je oznaka broja koji moze biti jednocifren, trocifren ili dvocifren sa vodecim nulama. Na osnovu ovih podataka na standarni izlaz ispisati ime smera kome student pripada i indeks u obliku broj/godina. U sluˇcaju greske (ukoliko OO kao oznaka smera nije ispravna ili ostali karakteri nisu brojevi) ispisati -1. Nazivi smerova su: mi - informatika, ma - astronomija, mr - racunarstvo i informatika, ms - statistika, mm - teorijska matematika, mp - primenjena matematika */

#include <stdio.h>
#include <ctype.h>

int main()
{
  char o1, o2, g1, g2, b1, b2, b3;
  int god, br, osnova;
  
  scanf("%c%c%c%c%c%c%c", &o1, &o2, &g1, &g2, &b1, &b2, &b3);

  if (o1 != 'm' || !isdigit(g1) || !isdigit(g2) || !isdigit(b1) || !isdigit(b2) || !isdigit(b3)){
    printf("-1");
    return -1;
  }
  
  else{
    switch(o2){
      case 'i': printf("informatika ");
                break;
      case 'a': printf("astronomija ");
                break;
      case 'r': printf("racunarstvo i informatika ");
                break;
      case 's': printf("statistika ");
                break;
      case 'v': printf("verovatnoca ");
                break;
      case 'm': printf("teorijska matematika ");
                break;
      case 'p': printf("primenjena matematika ");
                break;
      default: printf("-1\n");
               return -1;         
    }
    if(isdigit(g1) && isdigit(g2)){
      god=(g1-'0')*10 + g2-'0';
      if(isdigit(b1) && isdigit(b2) && isdigit(b3)){
        br=(b1-'0')*100 + (b2-'0')*10 + b3-'0';
        printf("%d/", br);
        osnova= god <= 17 ? 2000 : 1900;
	god += osnova;
	printf("%d",god);
      }
    }
  }

  printf("\n");
  return 0;
}
