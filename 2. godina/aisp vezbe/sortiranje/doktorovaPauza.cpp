/* Poznata su vremena dolaska pacijenata 
 * na pregled i vreme trajanja njihovog 
 * pregleda (pretpostavlja se da se nikoja
 * dva pacijenta ne preklapaju). Kolika je 
 * najveća pauza koju doktor može imati u 
 * toku tog dana, između pregleda dva svoja
 * pacijenta? 
 * O(nlogn) */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  
  int n;
  cin >> n;
  
  vector<int> dosao(n);
  vector<int> trajao(n);
  
  for(int i = 0; i < n; i++)
    cin >> dosao[i] >> trajao[i];
  
  sort(begin(dosao), end(dosao));
  
  int max = 0;
  
  for(int i = 0; i < n-1; i++){
    int pauza = dosao[i+1] - (dosao[i] + trajao[i]);
    if(pauza > max)
      max = pauza;
  }
  
  cout << max << endl;
  
  return 0;
}