/* Napisati rekurzivnu funkciju int f3(int x) koja u pocetnom
zapisu broja x izbacuje svaku neparnu cifru, ukoliko se ispred
te cifre nalazi cifra 2. Napisati program koji testira ovu
funkciju, tako sto sa standardnog ulaza ucitava ceo broj x, i na
standardni izlaz ispisuje vrednost funkcije f3(x). U slucaju
greske ispisati -1 na standardni izlaz za greske. Napomena:
Zadatak mora biti uradjen rekurzivno. Nije dozvoljeno koriscenje
statickih i globalnih promenljivih, menjanje zaglavlja funkcije
i pisanje pomocnih funkcija. */

#include <stdio.h>
#include <stdlib.h>

int f3(int x){
 if(x==0)
  return 0;
  
 int levi_deo=f3(x/10);
 if((x/10)%10==2 && x%2==1)
  return levi_deo;
 else
  return levi_deo*10+x%10;
}

int main(){
 int x;
 scanf("%d", &x);
 int k=abs(x);
 
 printf("%d\n", x>0 ? f3(x) : -1*f3(k));
 
 return 0;
}
