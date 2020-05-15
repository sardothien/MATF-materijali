/* Definisati funkciju koja u datoj niski određuje najkraću
 * podnisku koja sadrži sve karaktere iz datog skupa karaktera. */

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
  
  string niska;
  cin >> niska;
  
  string S;
  cin >> S;
  
  vector<int> pozKarakteraS;
  
  for(int i = 0; i < niska.size(); i++)
    if(S.find(niska[i]) != string::npos)
      pozKarakteraS.push_back(i);
    
  int min = numeric_limits<int>::max();
  map<char, int> brPojavljivanja;
  vector<int>::const_iterator i, j;
  
  for(i = j = pozKarakteraS.begin(); j != pozKarakteraS.end(); j++){
    brPojavljivanja[niska[*j]]++;
    if(brPojavljivanja.size() == S.size()){
      while(brPojavljivanja[niska[*i]] > 1){
	brPojavljivanja[niska[*i]]--;
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
    cout << "Ne sadrzi sve karaktere iz S" << endl; 
  
  return 0;
}