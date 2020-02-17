/* Napisati program koji za uneta vremena poletanja i sletanja aviona ispisuje dužinu trajanja leta. */

#include <stdio.h>
int main(){
   int h_pol, m_pol, h_sl, m_sl;

   printf("Unesite vreme poletanja: ");
   scanf("%d%d", &h_pol, &m_pol);

   printf("Unesite vreme sletanja: ");
   scanf("%d%d", &h_sl, &m_sl);

   h_pol=h_pol*60+m_pol;
   h_sl=h_sl*60+m_sl;

   h_sl-=h_pol;
  
   h_pol=h_sl/60;
   m_pol=h_sl%60;

   printf("Duzina trajanja leta je %dh i %dmin\n", h_pol, m_pol);

   return 0;
}
