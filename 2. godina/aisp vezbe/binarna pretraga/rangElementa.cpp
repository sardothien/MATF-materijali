/* Nakon takmičenja iz informatike poznata je lista 
 * učenika sa poenima (svaki učenik ima različit broj poena), 
 * međutim, nije poznat plasman (redni broj svakog učenika).
 * Napiši program koji za svakog učenika određuje plasman i
 * ispisuje izveštaj o plasmanu, pri čemu su učenici prikazani 
 * u istom redosledu kao i u polaznoj listi sa poenima. 
 * O(nlogn) */

#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
using namespace std;

int main(){
  
  int n;
  cin >> n;
  
  vector<pair<string, int>> ucenici(n);
  vector<int> poeni(n);
  
  for(int i = 0; i < n; i++){
    string ime;
    int poen;
    cin >> ime >> poen;
    ucenici[i] = make_pair(ime, poen);
    poeni[i] = poen;
  }
  
  sort(begin(poeni), end(poeni), greater<int>());
  
  for(int i = 0; i < n; i++){
    string ime = ucenici[i].first;
    int poen = ucenici[i].second;
    
    auto it = lower_bound(begin(poeni), end(poeni), poen, greater<int>());
    int plasman = distance(begin(poeni), it) + 1;
    
    cout << ime << " " << plasman << endl;
  }  
  
  return 0;
}