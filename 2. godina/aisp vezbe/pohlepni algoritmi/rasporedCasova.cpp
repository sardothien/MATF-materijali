/* Za svaki od n časova poznato je vreme početka i završetka.
 * Napiši program koji određuje minimalni broj učionica potreban
 * da se svi časovi održe. */
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;

struct Cas {
  int broj, pocetak, kraj;
};

Cas napraviCas(int broj, int pocSat, int pocMin, int krajSat, int krajMin){
  Cas c;
  c.broj = broj;
  c.pocetak = pocSat*60 + pocMin;
  c.kraj = krajSat*60 + krajMin;
  return c;
}

struct Ucionica {
  int broj;
  int slobodnaOd;
};

Ucionica napraviUcionicu(int slobodnaOd, int broj){
  Ucionica u;
  u.broj = broj;
  u.slobodnaOd = slobodnaOd;
  return u;
}

struct PorediUcionice {
  bool operator()(const Ucionica& u1, const Ucionica& u2){
    return u1.slobodnaOd > u2.slobodnaOd;
  }
};

int main(){
  int n;
  cin >> n;
  
  vector<Cas> casovi(n);
  for(int i = 0; i < n; i++){
    int pocSat, pocMin, krajSat, krajMin;
    cin >> pocSat >> pocMin >> krajSat >> krajMin;
    casovi[i] = napraviCas(i, pocSat, pocMin, krajSat, krajMin);
  }

  sort(begin(casovi), end(casovi), [](const Cas& c1, const Cas& c2){
    return c1.pocetak < c2.pocetak;
  });

  vector<int> ucionica(n);
  priority_queue<Ucionica, vector<Ucionica>, PorediUcionice> redUcionica;

  for(const Cas& c : casovi){
    int brojUcionice;
    if(redUcionica.empty() || redUcionica.top().slobodnaOd > c.pocetak)
      brojUcionice = redUcionica.size() + 1;
    else{
      brojUcionice = redUcionica.top().broj;
      redUcionica.pop();
    }
    ucionica[c.broj] = brojUcionice;
    redUcionica.push(napraviUcionicu(c.kraj, brojUcionice));
  }

  cout << redUcionica.size() << endl;

  for(int u : ucionica)
    cout << u << endl;

  return 0;
}