/* Napisati program koji ucitava dva stringa i poredi ih. */

#include <stdio.h>
#include <string.h>

/*
       Funkcija strcmp(s,t) je ugradjena funkcija koja utvrdjuje da li su strinovi
       s i t jednaki. Ukoliko jesu, vraca 0, a u suprotnom vraca razliku
       ASCII kodova prva dva razlicita karaktera na istim pozicijama 
       (npr strcmp("aa","ab") ce vratiti -1 a strcmp("ab","aa") 1).

       Funkcija strcmp se nalazi u zaglavlju string.h.

       Funkcija strcmp_klon je jedna implementacija funkcije strcmp.
       
       U zadacima cemo uvek koristiti ugradjenu funkciju strcmp osim ako u tekstu zadatka
       nije naglaseno da se ona ne sme koristiti. Funkcija strcmp_klon sluzi da pokaze na koji
       nacin radi ugradjena funkcija strcmp.
    
       Ugradjena funkcija strcmp poziva se na isti nacin kao funkcija strcmp_klon:
       strcmp(s1,s2) 
       gde poredimo stringove s1 i s2. 

*/

int strcmp_klon(char s1[], char s2[])
{
  int i;
  for(i=0; s1[i]==s2[i];i++)
    if (s1[i]=='\0')
      return 0;
      
  return s1[i] - s2[i];
}

int main()
{
   char s1[21];
   char s2[21];
   int ind;
      
   printf("Unesi dva stringa:");   
   scanf("%s%s",s1,s2);
   ind = strcmp_klon(s1,s2);
   if (ind == 0)
      printf("Uneti stringovi su jednaki\n");   
   else if (ind < 0)
      printf("Niska \"%s\" manja je od niske \"%s\" \n", s1, s2);
   else
      printf("Niska \"%s\" veca je od niske \"%s\" \n", s1, s2);

   return 0;
}
