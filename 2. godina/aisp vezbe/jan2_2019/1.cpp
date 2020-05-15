#include<iostream>
#include<vector>
using namespace std;

int main(){ // O(mlogn)
  
  int n;
  cin >> n;
  
  vector<int> cene(n);
  for(int i = 0; i < n; i++)
    cin >> cene[i];
  
  int m; // broj kupaca
  cin >> m;
  
  vector<int> zeljenaCena(m);
  int k[m]; // broj vozila
  for(int i = 0; i < m; i++){
    cin >> zeljenaCena[i] >> k[i];  
      
    int l = 0, d = m-k[i]-1;
    
    while(l <= d){
      int s = l + (d-l)/2;
      if(abs(cene[s] - zeljenaCena[i]) > abs(cene[s+k[i]] - zeljenaCena[i]))
	l = s+1;
      else
	d = s-1;
    }
    
    cout << l << endl;
  
  }
  return 0;
}