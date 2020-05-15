/* U nizu od n elemenata pronaći element od kojega 
 * je tačno k elemenata manje ili jednako. 
 * O(n) */
#include<iostream>
#include<vector>
using namespace std;

int element(vector<int>& a, int l, int d, int k){
  while(true){
    swap(a[l], a[l + rand() % (d-l+1)]);
    
    int i = l+1, j = d;
    while(i <= j){
      if(a[i] < a[l])
	i++;
      else if(a[j] > a[l])
	j--;
      else
	swap(a[i++], a[j--]);
    }
    
    swap(a[l], a[j]);
    
    if(k < j)
      d = j-1;
    else if(k > j)
      l = j+1;
    else
      return a[k];
  }
}

int main(){
  int n;
  cin >> n;
  
  vector<int> niz(n);
  for(int i = 0; i < n; i++)
    cin >> niz[i];
  
  int k;
  cin >> k;
  
  cout << element(niz, 0, n-1, k) << endl;
  
  return 0;
}