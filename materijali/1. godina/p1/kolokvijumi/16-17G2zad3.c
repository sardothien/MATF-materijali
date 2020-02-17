/* 2016/2017 - Predlog kolokvijuma GRUPA 2, zadatak 3 */
/* Napisati program za ifrovanje koji uitava karakter c i pozitivan broj b ifruje uneti karakter na sledei
nain:
• Ako je uneti karakter malo ili veliko slovo, njegova ifra se dobija ciklinim pomeranjem u desno za
b mesta (npr. za karakter y i broj 5 dobija se slovo d. Slino za karakter Y i broj 5 dobija se slovo
D).
• Ako je uneti karakter cifra, njegova ifra je broj √ koji se dobija kada se unetoj cifri doda njen
(celobrojni) koren (npr. za unetu 8, sifra je 8 + 8 = 10).
• Ako je uneti karakter zagrada (neka od: (, ), {, }, [ ili ]), karakter ostaje nepromenjen.
• U suprotnom, ifra je *.
Na standardni izlaz ispisati ifru unetog karaktera. U sluaju greke na standardni izlaz ispisati -1. */

#include <stdio.h>
#include <math.h>
#include <ctype.h>

int main(){

  char c, sifra;
  int b;
  
  scanf("%c%d", &c, &b);
  
  if(b<0){
    printf("-1\n");
    return -1;
  }
   
  /* Pod a) ako je c malo ili veliko slovo */ 
  if(islower(c)){
     if(c+b>'z')
       sifra = 'a' + (c+b-'z')%26 - 1;
     else
       sifra = c+b;
     printf("%c\n", sifra);
  }
   else if(isupper(c)){
     if(c+b>'Z')
       sifra = 'A' + (c+b-'Z')%26 - 1;
     else 
       sifra = c+b;  
     printf("%c\n", sifra);  
   }
   
   /* Pod b) ako je c neki broj */
   else if(isdigit(c)){
     int cifra = c - '0';
     printf("%d\n", cifra + (int)sqrt(cifra));
   }
   
   /* Pod c) ako je c neka od zagrada */
   else if(c=='(' || c==')' || c=='{' || c=='}' || c=='[' || c==']')
     printf("%c\n", c);
     
   /* Pod d) ako je c neki drugi karakter */  
   else
     printf("*\n");

  return 0;
}
