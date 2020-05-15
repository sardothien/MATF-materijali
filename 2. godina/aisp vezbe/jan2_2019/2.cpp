#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int main(){ // O(n)
  int k; // broj firmi
  cin >> k;
  
  int n; // broj predavanja
  cin >> n; 
  
  vector<int> redosled(n);
  for(int i = 0; i < n; i++)
    cin >> redosled[i];
  
  // --------------------------------------
  
  string podniz;
  for(int i = 0; i < n; i++)
    podniz[i] = i+1;
  
  vector<int> poz;
  
  for(int i = 0; i < n; i++)
    if(podniz.find(redosled[i]) != string::npos)
      poz.push_back(i);
    
  int min = numeric_limits<int>::max();
  map<char, int> brPojavljivanja;
  vector<int>::const_iterator i, j;
  
  for(i = j = poz.begin(); j != poz.end(); j++){
    brPojavljivanja[redosled[*j]]++;
    if(brPojavljivanja.size() == n){
      while(brPojavljivanja[redosled[*i]] > 1){
	brPojavljivanja[redosled[*i]]--;
	i++;
      }
      int duzina = *j - *i + 1;
      if(duzina < min)
	min = duzina;
    }
  }

  if(min != numeric_limits<int>::max())
    cout << min << endl;
  else
    cout << 0 << endl; 
  
  return 0;
}