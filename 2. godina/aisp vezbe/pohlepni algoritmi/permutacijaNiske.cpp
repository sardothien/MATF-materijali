/* Naći neku permutaciju niske sastavljene od malih slova engleske
 * abecede u kojoj nikoja dva susedna elementa nisu jednaka ili 
 * odrediti da takva permutacija ne postoji. Na primer, ako niska 
 * aabbcc, se može permutovati u abacbc, dok se niska aabbbb ne može 
 * permutovati. */
#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

bool permutacija(string& s){
  priority_queue<pair<int, char>> red;
  int frekvencije[26] = {0};

  for(char c : s)
    frekvencije[c - 'a']++;

  for(int i = 0; i < 26; i++)
    if(frekvencije[i] > 0)
      red.push(make_pair(frekvencije[i], 'a' + i));

  int preostalo_prethodnih;

  for(int i = 0; i < s.size(); i++){
    if(red.empty()) 
      return false;
    s[i] = red.top().second;
    int preostalo_trenutnih = red.top().first - 1;
    red.pop();
    if(i > 0 && preostalo_prethodnih > 0)
      red.push(make_pair(preostalo_prethodnih, s[i-1]));
    preostalo_prethodnih = preostalo_trenutnih;
  }

  return true;
}

int main(){
  string s;
  cin >> s;
  
  cout << permutacija(s) << endl;
    
  return 0;
}