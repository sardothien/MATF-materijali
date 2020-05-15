/* Potrebno je odrediti prag poena za 
 * upis na fakultet. Komisija je stalno
 * suočena sa pitanjima koliko bi se studenata 
 * upisalo, kada bi prag bio jednak datom broju. 
 * Napisati program koji učitava poene svih 
 * kandidata i efikasno odgovara na upite ovog tipa. 
 * O((n+m)logn) */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  
  int n;
  cin >> n;
  
  vector<int> poeni(n);
  for(int i = 0; i < n; i++)
    cin >> poeni[i];
  
  sort(begin(poeni), end(poeni));
  
  int m;
  cin >> m;
  
  for(int i = 0; i < m; i++){
    int prag;
    cin >> prag;
    auto it = lower_bound(begin(poeni), end(poeni), prag);
    cout << distance(it, end(poeni)) << endl;
  }
    
  return 0;
}