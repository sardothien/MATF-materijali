/* Dat je sortirani niz od n različitih brojeva.
 * Odrediti broj najbliži datom (ako su dva podjednako 
 * udaljena, vratiti manji od njih). 
 * O(logn) */

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
  
  int x;
  cin >> x;
  
  auto it = lower_bound(begin(niz), end(niz), x);
  
  if(it == end(niz))
    cout << *prev(it) << endl;
  else if(it == begin(niz))
    cout << *it << endl;
  else
    if(*it - x < x - *prev(it))
      cout << *it << endl;
    else
      cout << *prev(it) << endl;

  return 0;
}