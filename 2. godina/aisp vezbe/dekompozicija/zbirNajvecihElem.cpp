/* Odrediti zbir najvećih k elemenata niza. */
#include<iostream>
#include<vector>
using namespace std;

void qsort(vector<int>& a, int l, int d, int k){
  if(k <= 0 || l >= d)
    return;
  
  int m = l;
  for(int i = l+1; i <= d; i++)
    if(a[i] >= a[l])
      swap(a[++m], a[i]);
    
  swap(a[m], a[l]);
  
  if(k < m-1)
    qsort(a, l, m-1, k);
  else
    qsort(a, m+1, d, k - (m-l+1));
}

int zbir(vector<int>& a, int k){
  qsort(a, 0, a.size()-1, k);
  
  int s = 0;
  for(int i = 0; i < k; i++)
    s += a[i];
  
  return s;
}

int main(){
  int n;
  cin >> n;
  
  vector<int> niz(n);
  for(int i = 0; i < n; i++)
    cin >> niz[i];
  
  int k;
  cin >> k;
  
  cout << zbir(niz, k) << endl;
  
  return 0;
}