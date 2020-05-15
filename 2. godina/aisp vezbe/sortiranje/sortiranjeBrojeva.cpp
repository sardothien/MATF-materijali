/* Dati niz prirodnih brojeva sortirati 
 * primenom sortiranja višestrukim
 * razvrstavanjem. (radix sort) */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void sortiranje(vector<int> brojevi, int s, int n){
  int broj[10] = {0};
    
    for(int i = 0; i < n; i++)
      broj[(brojevi[i] / s) % 10]++;
    
    for(int i = 1; i < 10; i++)
      broj[i] += broj[i-1];
    
    vector<int> pom(n);
    
    for(int i = n-1; i >= 0; i++)
      pom[--broj[(brojevi[i] / s) % 10]] = brojevi[i];
    
    brojevi = pom;
}

int main(){
  
  int n;
  cin >> n;
  
  vector<int> brojevi(n);
  for(int i = 0; i < n; i++)
    cin >> brojevi[i];
  
  int max = numeric_limits<int>::min();
  
  for(int x : brojevi)
    if(x > max)
      max = x;
    
  for(int s = 1; max/s > 0; s *= 10){  
    sortiranje(brojevi, s, n);
  }
  
  for(int i = 0; i < n; i++)
    cout << brojevi[i] << " ";  
  cout << endl;
  
  return 0;
}