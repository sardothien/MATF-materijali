/* Napisati program koji pronalazi sve moguće načine 
 * da skakač u šahu obiđe celu šahovsku tablu, krenuvši
 * iz gornjeg levog ugla, krećući se po pravilima šaha 
 * tako da na svako polje table stane tačno jednom. 
 * Dopustiti da dimenzija table bude različita od 8 × 8. */
#include<iostream>
#include<vector>
using namespace std;

const int V = 4, K = 5;

vector<vector<int>> potezi = {
  {-1, -2}, {-1, 2}, {1, -2}, {1, 2},
  {-2, -1}, {-2, 1}, {2, -1}, {2, 1}
};

void ispisi(const vector<vector<int>>& tabla){
  for(int v = 0; v < V; v++){
    for(int k = 0; k < K; k++)
      cout << setw(2) << tabla[v][k] << " ";
    cout << endl;
  }

  cout << endl;
}

void obidjiTabluSkakacem(vector<vector<int>>& tabla, int v, int k, int potez){
  tabla[v][k] = potez;
  if(potez == V*K)
    ispisi(tabla);

  for(auto& p : potezi){
    int vn = v + p[0], kn = k + p[1];
    if(0 <= vn && vn < V && 0 <= kn && kn < K && tabla[vn][kn] == 0){
      obidjiTabluSkakacem(tabla, vn, kn, potez+1);
    }
  }
  
  tabla[v][k] = 0;
}

int main() {
  vector<vector<int>> tabla(V);
  
  for(int i = 0; i < V; i++)
    tabla[i].resize(K, 0);

  obidjiTabluSkakacem(tabla, 0, 0, 1);
  
  return 0;
}