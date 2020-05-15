/* Dato je n zatvorenih intervala realne 
 * prave. Odredi ukupnu dužinu koju pokrivaju,
 * kao i najmanji broj zatvorenih intervala 
 * koji pokrivaju isti skup tačaka kao i 
 * polazni intervali (oni se mogu dobiti 
 * ukrupnjavanjem polaznih intervala). */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  
  int n;
  cin >> n;
  
  vector<pair<double, double>> ulazni(n);
  
  for(int i = 0; i < n; i++){
    double x1, x2;
    cin >> x1 >> x2;
    ulazni[i] = make_pair(x1, x2);
  }
  
  vector<pair<double, double>> izlazni(n);
  vector<pair<double, int>> promene(n * 2);
  
  for(int i = 0; i < n; i++){
    promene[2*i] = make_pair(ulazni[i].first, 1);
    promene[2*i+1] = make_pair(ulazni[i].second, -1);
  }
  
  sort(begin(promene), end(promene));
  
  bool zapocetIzlazni = false;
  double xPocetakIzlaznog = 0;
  int brojUlaznih = 0;
  int i = 0;
  
  while(i < promene.size()){
    double xTrenutno = promene[i].first;
    while(i < promene.size() && promene[i].first == xTrenutno)
      brojUlaznih += promene[i++].second;
    
    if(!zapocetIzlazni && brojUlaznih > 0){
      zapocetIzlazni = true;
      xPocetakIzlaznog = xTrenutno;
    }  
    
    if(zapocetIzlazni && brojUlaznih == 0){
      izlazni.push_back(make_pair(xPocetakIzlaznog, xTrenutno));
      zapocetIzlazni = false;
    }
  }
  
  int duzina = 0;
  for(auto it : izlazni)
    duzina += it.second - it.first;
  cout << duzina << endl;
  
  cout << izlazni.size() << endl;
  
  return 0;
}