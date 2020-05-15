#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){ // O(n+m)
  
  int n;
  cin >> n;
  
  vector<int> a(n);
  for(int i = 0; i < n; i++)
    cin >> a[i];
  
  int m = *max_element(begin(a), end(a));
  
  vector<int> frekv(m+1, 0);
  for(int i = 0; i < n; i++)
    frekv[a[i]]++;
  
  int k = 0;
  for(int j = 0; j < m; j++)
    for(int i = 0; i < frekv[j]; i++)
      a[k++] = j;
  
  
  
  return 0;
}