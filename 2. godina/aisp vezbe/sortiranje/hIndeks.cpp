/* Rangiranje naučnika vrši se pomoću 
 * statistike koja se naziva Hiršov
 * indeks ili kraće h-indeks. H-indeks
 * je najveći broj h takav da naučnik ima
 * bar h radova sa bar h citata. Napisati 
 * program koji na osnovu broja citata svih 
 * radova naučnika određuje njegov h-indeks. 
 * O(nlogn) */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  
  int n;
  cin >> n;
  
  vector<int> brojCitata(n);
  for(int i = 0; i < n; i++)
    cin >> brojCitata[i];
  
  sort(brojCitata.begin(), brojCitata.end(), greater<int>());
  
  int h = 0;
  while(h < n && brojCitata[h] > h)
    h++;
  
  cout << h << endl;  
  
  return 0;
}