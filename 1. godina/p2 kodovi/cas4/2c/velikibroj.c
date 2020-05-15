#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "velikibroj.h"
/* Ucitavanje velikog broja iz datoteke */
VB unos(char *s){
 VB r;
 int i, j;
 r.n=strlen(s);
 for(i=r.n-1, j=0; i>=0; i--, j++){
  r.cifre[j]=s[i]-'0';
 }
 return r;
}
/* Ispis velikog broja iz datoteke */
void ispis(VB a){
 int i;
 for(i=a.n-1; i>=0; i--){
  putchar(a.cifre[i]+'0');
 }
 putchar('\n'); 
}
/* Sabiranje dva velika broja */
VB zbir(VB a, VB b){
 VB r;
 int brc= a.n > b.n  ?  a.n : b.n;
 int i, prenos=0;
 r.n=brc;
 for(i=0; i<brc; i++){
  int vrednost=prenos;
  if(i<a.n)
   vrednost+=a.cifre[i];
  if(i<b.n)
   vrednost+=b.cifre[i];
  r.cifre[i]=vrednost%10;
  prenos=vrednost/10;
 }
 
 if(prenos>0){
  r.cifre[r.n]=prenos;
  r.n++;
 }
 
 return r;
}
/* Poredenje dva velika broja (funkcija vraca -1, 0, ili 1) */
int cmpvb(VB a, VB b){
 int i;
 if(a.n!=b.n)
  return a.n-b.n;
 for(i=a.n-1; i>=0; i--){
  if(a.cifre[i]!=b.cifre[i])
   return a.cifre[i]-b.cifre[i];
 }
 return 0;
}
/* Mnozenje velikog broja cifrom */
VB mnozi_cifrom(VB a, int b){
 VB r;
 if(b==0){
  r=nula();
  return r;
 }
 int prenos=0;
 int i;
 r.n=a.n;
 for(i=0; i<a.n; i++){
  int vrednost=prenos + b*a.cifre[i];
  r.cifre[i]=vrednost%10;
  prenos=vrednost/10;
 }
 if(prenos>0){
  r.cifre[r.n]=prenos;
  r.n++;
 } 
 return r;
}
/* Mnozenje dva velika broja */
VB mnozi(VB a, VB b){
 VB r;
 r=nula();
 int i;
 for(i=0; i<b.n; i++){
  VB temp=mnozi_cifrom(a, b.cifre[i]);
  temp=puta_deset_na_k(temp, i);
  r=zbir(r, temp);
 }
 return r;
}

VB puta_deset_na_k(VB a, int k){
 VB r;
 int i, j;
 for(i=0; i<k; i++)
  r.cifre[i]=0;
 for(j=0; j<a.n; j++){
  r.cifre[i]=a.cifre[j];
  i++;
 }
 r.n=k+a.n;
 return r;
}

VB nula(){
 VB r;
 r.n=0;
 return r;
}
