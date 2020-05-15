/* Dat je sortirani niz od n brojeva. Odrediti poziciju
 * na kojoj počinje k brojeva najbližih datom (ako postoji 
 * više takvih pozicija, ispisati najmanju). */

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
  
  int k;
  cin >> k;
  int x;
  cin >> x;
  
  int l = 0, d = n - k - 1;
  
  while(l <= d){
    int s = l + (d-l)/2;
    if(abs(niz[s] - x) > abs(niz[s+k] - x))
      l = s+1;
    else
      d = s-1;
  }
  
  cout << l << endl;
  
  return 0;
}