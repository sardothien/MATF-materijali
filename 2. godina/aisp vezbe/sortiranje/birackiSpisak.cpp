/* Državna komisija je napravila spisak 
 * svih birača u državi. Potrebno je da 
 * se svakoj opštini distribuira spisak 
 * birača sa teritorije te opštine, ali
 * tako da redosled ostane isti kakav je
 * na polaznom spisku državne komisije. Na 
 * standardni izlaz ispisati spiskove za 
 * sve opštine, svaki u posebnom redu. Opštine
 * treba da budu uređene leksikografski, rastuće.
 * O() */
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct Birac {
  string opstina;
  string sifra;
};

int main(){
  
  int n;
  cin >> n;
  
  vector<Birac> biraci(n);
  for(int i = 0; i < n; i++)
    cin >> biraci[i].opstina >> biraci[i].sifra;
  
  map<string, int> brojBiraca;
  
  for(auto birac : biraci)
    brojBiraca[birac.opstina]++;
  
  map<string, int> pozicije;
  int prethodnoBiraca = 0;
  
  for(auto it : brojBiraca){
    pozicije[it.first] = prethodnoBiraca;
    prethodnoBiraca += it.second;
  }
  
  vector<Birac> sortirano(n);
  
  for(auto birac : biraci){
    sortirano[pozicije[birac.opstina]] = birac;
    pozicije[birac.opstina]++;
  }
  
  
  biraci = sortirano;
  for(int i = 0; i < n; i++)
    cout << biraci[i].opstina << " " << biraci[i].sifra << endl;
  
  return 0;
}