/* Sortirati niz brojeva primenom algoritma brzog sortiranja. */
#include<iostream>
#include<vector>
using namespace std;

void quickSort(vector<int>& a, int l, int d){
  if(l < d){
    // proizvoljni element kao pivot
    swap(a[l], a[l + rand() % (d-l+1)]);
    
    // [l, k] - manji od pivota
    // (k, i) - veci od pivota
    // [i, d] - neispitani
    int k = l;
    for(int i = l+1; i <= d; i++)
      if(a[i] <= a[l])
	swap(a[i], a[++k]);
      
    swap(a[l], a[k]);
      
    quickSort(a, l, k-1);
    quickSort(a, k+1, d);
  }
}

int main(){
  int n;
  cin >> n;
  
  vector<int> niz(n);
  for(int i = 0; i < n; i++)
    cin >> niz[i];
  
  quickSort(niz, 0, n-1);
  
  for(int i = 0; i < n; i++)
    cout << niz[i] << " "; 
  cout << endl;
  
  return 0;
}