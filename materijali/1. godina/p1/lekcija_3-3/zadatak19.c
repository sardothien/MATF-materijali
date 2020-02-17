/* Napisati funkciju int ucitaj_liniju(char s[], int n)
   koja ucitava liniju maksimalne duzine n u string s
   i vraca duzinu ucitane linije. Linija moze da sadrzi
   blanko znakove ali ne moze da sadrzi \n ili EOF. 
   
   Napisati potom glavni program koji ucitava linije
   do EOF i ispisuje najduzu liniju i njenu duzinu. Ukoliko
   ima vise linija maksimalne duzine, ispisati prvu. Mozemo
   pretpostviti da svaka linija sadrzi najvise 80 karaktera,
   zajedno sa \n. */

#include <stdio.h>
#include <string.h>

#define MAX 81

int ucitaj_liniju(char s[], int n){
 int i=0;
 int c;
 while((c=getchar())!='\n' && i<n-2 && c!=EOF){
   s[i] = c;
   i++;
 }

 s[i]='\n';    
 s[i+1]='\0';
  
 return i;  
}

int main(){

 char linija[MAX];
 char najduza_linija[MAX];
 int max_duzina=0;
 int duzina;
  
 while((duzina=ucitaj_liniju(linija, MAX))>0){
   if(max_duzina<duzina){
     max_duzina = duzina;
     strcpy(najduza_linija,linija);
   }
 }
  
 printf("%s %d\n", najduza_linija, max_duzina);

 return 0;
}
