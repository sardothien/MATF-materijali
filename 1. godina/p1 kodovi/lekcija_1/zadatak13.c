/* Napisati program koji za uneti pozitivan četvorocifreni broj:
(a) izračunava proizvod cifara
(b) izračunava razliku sume krajnjih i srednjih cifara
(c) izračunava sumu kvadrata cifara
(d) izračunava broj koji se dobija ispisom cifara u obrnutom poretku
(e) izračunava broj koji se dobija zamenom cifre jedinice i cifre stotine */

#include <stdio.h>

int main() {
    
     int x;

     printf("Unesi cetvorocifren broj: ");
     scanf("%d", &x);
                                    /*  4        1         5         3  */
     printf("Proizvod cifara: %d\n", (x/1000)*(x%10)*((x/10)%10)*((x/100)%10));
     printf("Razlika suma: %d\n", ((x/1000)+(x%10))-(((x/10)%10)+((x/100)%10)));
     printf("Suma kvadrata: %d\n", (x/1000)*(x/1000)+(x%10)*(x%10)+((x/10)%10)*((x/10)%10)+((x/100)%10)*((x/100)%10));     
     printf("Obrnut broj: %d%d%d%d\n", (x%10), ((x/10)%10), ((x/100)%10),(x/1000));  
     printf("Obrnut broj: %d%d%d%d\n", (x/1000), (x%10), ((x/10)%10), ((x/100)%10)); 

     return 0;
}
