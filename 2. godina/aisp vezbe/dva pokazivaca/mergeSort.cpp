/* Data su dva sortirana niza. Kreirati treći sortirani
 * niz koji sadrži tačno sve elemente prethodna dva onoliko
 * puta koliko se ukupno javljaju u oba niza. */

#include<iostream>
#include<vector>
using namespace std;

int main(){
  
  int a[] = {1, 3, 5, 7, 9};
  int b[] = {2, 4, 6, 8, 10};
  
  int na = sizeof(a) / sizeof(int);
  int nb = sizeof(b) / sizeof(int);
    
  int c[na+nb];
  
  int i = 0, j = 0, k = 0;
  while(i < na && j < nb)
    c[k++] = a[i] < b[j] ? a[i++] : b[j++];
  
  while(i < na)
    c[k++] = a[i++];
  while(j < nb)
    c[k++] = b[j++];
  
  for(int l = 0; l < na+nb; l++)
    cout << c[l] << " ";
  cout << endl;

  return 0;
}