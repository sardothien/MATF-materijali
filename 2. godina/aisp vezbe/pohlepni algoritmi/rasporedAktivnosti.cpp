/* U jednom kabinetu se subotom održava obuka programiranja. Svaki
 * nastavnik drži jedno predavanje i napisao je vreme u kom želi da 
 * drži nastavu (poznat je sat i minut početka i sat i minut završetka 
 * predavanja). Odredi kako je moguće napraviti raspored časova tako da
 * što više nastavnika bude uključeno. Napisati program koji određuje
 * optimalan raspored i dokazati njegovu korektnost. */
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

typedef pair<int, int> cas;

cas napraviCas(int pocSat, int pocMin, int krajSat, int krajMin){
  return make_pair(pocSat*60 + pocMin, krajSat*60 + krajMin);
}

inline int pocetakCasa(const cas& c){
  return c.first;
}

inline int krajCasa(const cas& c){
  return c.second;
}

int main(){
  int n;
  cin >> n;
  
  vector<cas> casovi(n);

  for(int i = 0; i < n; i++){
    int pocSat, pocMin, krajSat, krajMin;
    cin >> pocSat >> pocMin >> krajSat >> krajMin;
    casovi[i] = napraviCas(pocSat, pocMin, krajSat, krajMin);
  }

  sort(begin(casovi), end(casovi), [](const cas& a, const cas& b) {
    return krajCasa(a) < krajCasa(b);
  });

  int brojOdrzanihCasova = 1;
  int kraj = krajCasa(casovi[0]);

  for(int i = 1; i < n; i++)
    if(pocetakCasa(casovi[i]) >= kraj){
      brojOdrzanihCasova++;
      kraj = krajCasa(casovi[i]);
    }
  
  cout << brojOdrzanihCasova << endl;

  return 0;
}