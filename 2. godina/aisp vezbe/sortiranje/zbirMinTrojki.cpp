/* Dat je niz pozitivnih celih brojeva 
 * a0, a1,..., an−1. Za svaku trojku
 * 0 ≤ i < j < k ≤ n odrediti najmanju 
 * vrednost od tri broja ai, aj, ak, a 
 * zatim odrediti zbir tako dobijenih 
 * vrednosti. 
 * O(nlogn) */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  
  int n;
  cin >> n;
  
  vector<int> niz(n);
  for(int i = 0; i < n; i++)
    cin >> niz[i];
  
  sort(begin(niz), end(niz));
  
  int zbir = 0;
  for(int i = 0; i < n-2; i++){
    int brojTrojki = (n-1-i) * (n-1-i-1) / 2;
    zbir += brojTrojki * niz[i];
  }
  
  cout << zbir << endl;
  
  return 0;
}