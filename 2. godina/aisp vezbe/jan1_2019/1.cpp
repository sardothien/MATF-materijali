#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){ // O(n^2)
  int iznos;
  cin >> iznos;
  
  int n;
  cin >> n;
  
  vector<int> cene(n);
  for(int i = 0; i < n; i++)
    cin >> cene[i];
  
  int brNacina = 0;
  
  sort(begin(cene), end(cene));
  
  for(int i = 0; i <= n-2; i++){
    int l = i+1, d = n-1;
    while(l < d){
      if(cene[l] + cene[d] + cene[i] > iznos){
	d--;
      }
      else if(cene[l] + cene[d] + cene[i] < iznos)
	l++;
      else{
	brNacina++;
	l++;
	d--;
      }
    }
  }
  
  cout << brNacina << endl;
  
  return 0;
}