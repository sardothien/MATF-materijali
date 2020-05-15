/* Dat je skup od n tačaka u ravni sa 
 * celobrojnim koordinatama. Napisati 
 * program koji određuje koliko se 
 * različitih kvadrata može napraviti tako
 * da su im sva četiri temena u tom skupu tačaka. */
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

typedef pair<int, int> Tacka;

Tacka transliraj(const Tacka &t, int dx, int dy){
  return make_pair(t.first + dx, t.second + dy);
}

bool drugaDvaTemena(const Tacka &t1, const Tacka &t2, Tacka &t3, Tacka &t4){
  int x1 = t1.first, y1 = t1.second;
  int x2 = t2.first, y2 = t2.second;
  int dx = x2 - x1, dy = y2 - y1;
  
  if((dx + dy) % 2 != 0)
    return false;
  
  t3 = transliraj(t1, (dx-dy)/2, (dy+dx)/2);
  t4 = transliraj(t1, (dx+dy)/2, (dy-dx)/2);
  
  return true;
}

int brojKvadrata(const vector<int> &tacke){
  sort(tacke.begin(), tacke.end());
  
  int broj = 0;
  for(int i = 0; i < n; i++)
    for(int j = i+1, j < n; j++){
      Tacka t3, t4;
      if(drugaDvaTemena(tacke[i], tacke[j], t3, t4))
	if(binary_search(tacke.begin(), tacke.end(), t3) &&
	   binary_search(tacke.begin(), tacke.end(), t4))
	    broj++;
    }
    
  return broj / 2;
}

int main(){
    
  int n;
  cin >> n;
  
  vector<int> tacke(n);  
  for(int i=0; i<n; i++)
    cin >> tacke[i];
  
  cout << brojKvadrata(tacke) << endl;
    
  return 0;
}