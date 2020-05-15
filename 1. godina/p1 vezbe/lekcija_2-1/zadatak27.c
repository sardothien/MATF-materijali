/* Napisati program koji za uneti karakter ispituje da li je samoglasnik. */

#include <stdio.h>
#include <ctype.h>

int main(){
	
   char c;
   
   printf("Unesite jedan karakter: ");
   scanf("%c", &c);
   c=tolower(c);
   	
   switch(c){
	case 'a': 
	case 'e': 
	case 'i': 
	case 'o': 
	case 'u': printf("Uneti karakter je samoglasnik.\n");
                  break;
	default: printf("Uneti karakter nije samoglasnik.\n");
	         break;  
	}

  return 0;
}
