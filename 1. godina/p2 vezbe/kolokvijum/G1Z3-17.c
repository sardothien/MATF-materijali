/* Napisati rekurzivnu funkciju int noviBroj(int x, int n)
koja iz celog broja x izbacuje prvih n parnih cifara sa desne
strane. U slučaju da broj x ima manje od n cifara, vraća -1.
Napisati program koji sa standardnog ulaza učitava ceo broj x
i pozitivan ceo broj n i testira funkciju noviBroj. U slučaju
neispravnih ulaza na standardni izlaz za greške ispisati -1. 
Napomena: Vrednost -1 dobijenu kao povratnu vrednost funkcije
ispisati na standardni izlaz. Funkcija noviBroj mora biti
rekurzivna, sa navedenim prototipom. Nije dozvoljeno
korišćenje globalnih niti statičkih promenljivih. Rešenje
koje ne zadovoljava ove uslove će biti ocenjeno sa 0 poena.*/

#include <stdio.h>
#include <stdlib.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

int noviBroj(int x, int n){
 if(n==0)
  return x;
  
 if(x<10){
  if(x%2==0){
   if(n>1)
    greska();
   else
    return 0;
  }
  else{
   if(n>0)
    greska();
   return x;
  }
 }

 int c=x%10;
 if(x%2==0)
  return noviBroj(x/10, n-1);
 else
  return noviBroj(x/10, n)*10+c;
}

int main(){
  int x, n;
  scanf("%d%d", &x, &n);
  if(n<=0)
   greska();
  
 int k=noviBroj(x, n);
 printf("%d\n", k);   
 
 return 0;
}
