/* Potrebno je da niz učenika sortiramo 
 * na osnovu inicijala, ali tako da se 
 * unutar svake grupe učenika sa istim 
 * inicijalima raspored ostane isti kao na
 * originalnom spisku. */
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

enum {
  IME = 0, 
  PREZIME = 1  
};

typedef array<string, 2> Ucenik;

vector<Ucenik> razvrstaj(const vector<Ucenik>& ucenici, int ip){
  int brojPojavljivanja[26] = {0};

  for(auto ucenik : ucenici)
    brojPojavljivanja[ucenik[ip][0] - 'a']++;

  int pozicija[26];
  pozicija[0] = 0;

  for(int i = 1; i < 26; i++)
    pozicija[i] = pozicija[i-1] + brojPojavljivanja[i-1];

  vector<Ucenik> rezultat(ucenici.size());
  
  for(auto ucenik : ucenici)
    rezultat[pozicija[ucenik[ip][0] - 'a']++] = ucenik;

  return rezultat;
}

int main(){
  
  int n;
  cin >> n;
  
  vector<Ucenik> ucenici(n);
  
  for(int i=0; i<n; i++)
    cin >> ucenici[i];
  
  ucenici = razvrstaj(ucenici, PREZIME);
  ucenici = razvrstaj(ucenici IME);
  
  for(int i=0; i<n; i++)
    cout << ucenici[i] << " ";
  cout << endl;  
  
  return 0;
}