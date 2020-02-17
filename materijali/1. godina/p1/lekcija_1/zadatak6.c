/* Napisati program koji pomaže kasirki da obračuna kusur koji treba da vrati kupcu. Za unetu cenu artikla, količinu artikla i iznos koji je kupac dao, program treba da ispiše vrednost kusura. */

#include <stdio.h>
int main(){
   int a,b,c;

   printf("Unesite cenu, kolicinu i uplacen iznos: ");
   scanf("%d%d%d", &a, &b, &c);

   printf("Kusur je: %d\n", c-a*b);

   return 0;
}
