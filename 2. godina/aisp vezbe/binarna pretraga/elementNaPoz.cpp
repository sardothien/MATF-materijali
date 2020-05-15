/* Napisati funkciju koja proverava da li 
 * u strogo rastućem nizu elemenata postoji 
 * pozicija i takva da se na poziciji i nalazi
 * vrednost i tj. da važi da je ai = i. Ako pozicija 
 * postoji vratiti je, a ako ne postoji, vratiti -1. */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  
  int n;
  cin >> n;
  
  vector<int> a(n);
  for(int i = 0; i < n; i++)
    cin >> a[i];
  
  for(int i = 0; i < n; i++)
    a[i] -= i;
  
  auto it = lower_bound(a.begin(), a.end(), 0);
  
  if(it != a.end() && *it == 0)
    cout << distance(a.begin(), it) << endl;
  else
    cout << -1 << endl;
  
  return 0;
}