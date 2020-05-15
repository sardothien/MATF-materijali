/* Sortirani niz u kome su svi elementi različiti
 * je rotiran za proizvoljni broj mesta. Proveriti 
 * da li u njemu postoji dati element. 
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
  
  int l = 0, d = n-1;

  while(l <= d){
    int s = l + (d-l)/2;
    if(niz[s] == x){
      cout << "Postoji" << endl;
      return 0;
    }
    if(niz[l] < niz[s-1]){
      if(niz[l] <= x && x <= niz[s-1])
	d = s-1;
      else
	l = s+1;
    }
    else{
      if(niz[s+1] <= x && x <= niz[d])
	l = s+1;
      else
	d = s-1;
    }
  }
  
  cout << "Ne postoji" << endl;
  
  return 0;
}