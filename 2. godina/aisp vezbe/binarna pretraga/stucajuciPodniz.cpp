/* Ako je s niska, onda je s^n niska koja se dobija ako 
 * se svako slovo ponovi n puta, npr. (xyz)^3 je xxxyyyzzz. 
 * Napisati program koji određuje najveći broj n takav da 
 * je s^n podniz niske t (to znači da se sva slova niske s^n
 * javljaju u niski t, u istom redosledu kao u s^n , ali ne 
 * obavezno uzastopno). */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool jeStucajuci(string &podniz, string &niz, int n){
  int i = 0;
  
  for(char c : podniz){
    for(int k = 0; k < n; k++){
      while(i < niz.size() && niz[i] != c)
	i++;
      if(i == niz.size())
	return false;
      i++;
    }
  }
  
  return true;
}

int main(){
  
  string podniz, niz;  
  cin >> niz >> podniz;
  
  int l = 0, d = niz.size() / podniz.size();
  
  while(l <= d){
    int s = l + (d-l)/2;
    if(jeStucajuci(podniz, niz, s))
      l = s+1;
    else
      d = s-1;
  }
  
  cout << d << endl;
    
  return 0;
}