/* Sa standardnog unosa se unosi pozitivan prirodan broj n i pozitivan dvocifreni broj m. Napisati program ispisuje broj dobijen umetanjem broja m između cifre stotina i cifre hiljada broja n. */

#include <stdio.h>

int main() {

  int n, m;

  printf("Unesi broj n: ");
  scanf("%d", &n);

  printf("Unesi dvocifren broj m: ");
  scanf("%d", &m);

  printf("Novi broj: %d\n", n%1000+((n/1000)*100+m)*1000);

  return 0;
}
