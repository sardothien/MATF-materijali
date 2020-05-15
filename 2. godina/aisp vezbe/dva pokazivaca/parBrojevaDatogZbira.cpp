/* Definisati algoritam složenosti O(n) koji određuje 
 * koliko u datom rastuće sortiranom nizu dužine n 
 * (svi elementi su različiti) postoji parova brojeva
 * na različitim pozicijama čiji je zbir jednak datom broju s. */

#include<iostream>
#include<vector>
using namespace std;

int main(){
  
  int n;
  cin >> n;
  
  vector<int> niz(n);
  
  for(int i = 0; i < n; i++)
    cin >> niz[i];
  
  int s;
  cin >> s;
  
  int brParova = 0;
  int l = 0, d = n-1;
  
  while(l < d){
    if(niz[l] + niz[d] > s)
      d--;
    else if(niz[l] + niz[d] < s)
      l++;
    else{
      brParova++;
      d--;
      l++;
    }
  }
  
  cout << brParova << endl;
  
  return 0;
}