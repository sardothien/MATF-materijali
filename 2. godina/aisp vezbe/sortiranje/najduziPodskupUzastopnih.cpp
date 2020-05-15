/* U nizu celih brojeva odrediti najbrojniji 
 * podskup elemenata koji se mogu urediti u 
 * niz uzastopnih celih brojeva. Ako ima
 * više takvih podskupova, prikazati prvi
 * (onaj u kojem su brojevi najmanji).
 * O(nlogn) */

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
#include<iterator>
using namespace std;

int main(){
  
  int n;
  cin >> n;
  
  int niz[n];
  for(int i = 0; i < n; i++)
    cin >> niz[i];
  
  sort(niz, next(niz, n));
  
  // uklanjamo duplikate
  n = distance(niz, unique(niz, next(niz, n)));
    
  int duzina = 1, maxDuzina = 1;
  int j;
  
  for(int i = 1; i < n; i++){
    if(niz[i] == niz[i-1] + 1)
      duzina++;
    else
      duzina = 0;
    if(duzina > maxDuzina){
      maxDuzina = duzina;
      j = i;
    }
  }
  
   j -= maxDuzina; 
   int br = j;
   while(j <= maxDuzina + br){
     cout << niz[j] << " "; 
     j++;
   }
   cout << endl;  
  
  return 0;
}