/* Kamenje je postavljeno duž pozitivnog dela x-ose i 
 * za svaki kamen je poznata njegova koordinata x. Žaba 
 * kreće da skače sa prvog kamena (koji se nalazi u koordinatnom 
 * početku) i želi da u što manje skokova dođe do poslednjeg
 * kamena. U svakom skoku ona može da skoči samo u napred i da
 * preskoči najviše rastojanje r (a može da skoči i manje, ako je 
 * to potrebno). Napisati program koji određuje da li žaba može stići
 * do poslednjeg kamena i ako može u koliko najmanje skokova to
 * može učiniti. 
 * O(n) */
#include<iostream>
#include<vector>
using namespace std;

int brojSkokova(const vector<int>& kamenje, int r){
  int n = kamenje.size();
  int broj = 0;
  int kamen = 0;

  while(kamen < n - 1){
    int noviKamen = kamen;
    while(noviKamen + 1 < n && kamenje[noviKamen + 1] - kamenje[kamen] <= r)
      noviKamen++;
    if(noviKamen == kamen)
      return n;
    broj++;
    kamen = noviKamen;
  }
  
  return broj;
}

int main(){
  int n;
  cin >> n;
  
  vector<int> kamenje(n);
  for(int i = 0; i < n; i++)
    cin >> kamenje[i];
  
  int r;
  cin >> r; 
  
  cout << brojSkokova(kamenje, r) << endl;
    
  return 0;
}