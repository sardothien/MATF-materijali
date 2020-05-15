/*
  Program testira funkcije strstr(s,t) i strchr(s,c) 
*/

#include <stdio.h>
#include <string.h>


int main()
{
   char s1[21];
   char s2[21];
   char c;
   char* p;
      
   printf("Unesi dva stringa:");   
   scanf("%s%s",s1,s2);

   /*                 
       Funkcija strstr(s,t) je ugradjena funkcija koja utvrdjuje da li je string t
       podstring stringa t i ako jeste, vraca pokazivac (char*) na karakter 
       stringa s odakle pocinje prvo pojavljivanje stringa t, a NULL u suprotnom.
       
       NULL je pokazivac koji ne pokazuje ni na sta, odnosno ne sadrzi adresu
       nijedne promenljive.
       
       Podsetimo se veze nizova(a time i stringova) i pokazivaca:
       ako je string deklarisan sa s1[21], tada je njegov naziv s1
       ekvivalentan adresi prvog karaktera stringa: 
       s1 <=> &s1[0]
       i nadalje redom:
       s1+1 <=> &s1[1]
       ...
       u opstem slucaju:
       s1+i <=> &s1[i]
       
       To znaci da se indeks elementa na koji pokazuje s1+i moze
       dobiti tako sto od s1+i oduzmemo pokazivac na pocetak niza:
       s1+i-s1 <=> i. Ovako od pokazivaca na karakter u stringu
       dobijamo njegov indeks u stringu.
       
   */   

   p = strstr(s1,s2);
   
   if (p!=NULL)
      printf("%s jeste podstring od %s pocev od pozicije : %d\n", s2,s1, p-s1);
   else
      printf("%s NIJE podstring od %s\n", s2,s1);

   printf("Unesite karakter:\n");
   getchar(); // da se pokupi novi red nakon drugog stringa
   c = getchar(); 

   /*
      Funkcija strchr(s,c) je ugradjena funkcija koja vraca pokazivac
      na prvi karakter u stringu s koji je jednak karakteru c, ako takav
      postoji, a NULL u suprotnom.
      
      Indeks od pokazivaca dobijamo na isti nacin kao u prethodnom zadatku
      sa strstr.
   */
   
   p = strchr(s1,c);
   if(p!=NULL)
      printf("%c se pojavljuje u %s na poziciji %d\n", c, s1, p-s1);
   else
      printf("%c se NE pojavljuje u %s\n",c, s1);
 
  return 0;

}
