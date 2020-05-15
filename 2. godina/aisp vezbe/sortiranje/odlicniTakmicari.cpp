/* Studenti su se na jednom turniru
 * takmičili iz programiranja i 
 * matematike. Takmičar je odličan ako 
 * ne postoji takmičar koji je od njega
 * osvojio strogo više poena i iz programiranja
 * i iz matematike. Napisati funkciju koja određuje
 * ukupan broj odličnih takmičara. 
 * O(nlogn) */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Poeni {
  int mat;
  int prog;
};

int main(){
  
  int n;
  cin >> n;
  
  vector<Poeni> poeni(n);
  for(int i = 0; i < n; i++)
    cin >> poeni[i].mat >> poeni[i].prog;
  
  sort(begin(poeni), end(poeni), [](Poeni &p1, Poeni &p2){
    return p1.mat > p2.mat || (p1.mat == p2.mat && p1.prog < p2.prog);
  });
  
  int brojOdlicnih = 0;
  int maxProg = 0;
  
  for(int i = 0; i < n; i++){
    if(poeni[i].prog >= maxProg){
      maxProg = poeni[i].prog;
      brojOdlicnih++;
    }
  }
  
  cout << brojOdlicnih << endl;
  
  return 0;
}