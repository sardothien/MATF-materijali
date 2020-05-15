/* Implementirati sortiranje niza 
 * objedinjavanjem sortiranih polovina. */
#include<iostream>
#include<vector>
using namespace std;

void ucesljaj(vector<int>& a, int i, int m, 
		vector<int>& b, int j, int n,
		vector<int>& c, int k){
	
  while(i <= m && j <= n)
    c[k++] = a[i] < b[j] ? a[i++] : b[j++];
  while(i <= m)
    c[k++] = a[i++];
  while(j <= n)
    c[k++] = b[j++];
}

void merge_sort(vector<int>& a, int l, int d, vector<int>& tmp){
  if(l < d){
    int s = l + (d-l)/2;
    merge_sort(a, l, s, tmp);
    merge_sort(a, s+1, d, tmp);
    ucesljaj(a, l, s, a, s+1, d, tmp, l);
    
    for(int i = l; i <= d; i++)
      a[i] = tmp[i];
  }
}

int main(){
  
  int n;
  cin >> n;
  
  vector<int> niz(n);
  for(int i = 0; i < n; i++)
    cin >> niz[i];
  
  vector<int> tmp(n);
  
  merge_sort(niz, 0, n-1, tmp);
  
  for(int i = 0; i < n; i++)
    cout << niz[i] << " ";
  cout << endl;
  
  return 0;
}