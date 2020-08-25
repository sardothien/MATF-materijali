/* Konstruisati algoritam za odredjivanje broja klastera 
 * (odvojenih povezanih komponenti) u neusmerenom grafu G. */

#include<iostream>
#include<vector>
using namespace std;

struct Graf {
    int V;
    vector<vector<int>> lista_susedstva;
    vector<bool> posecen;
    int brKomponenti;
};

void inicijalizuj(Graf& g, int V){
    g.V = V;
    g.lista_susedstva.resize(V);
    g.posecen.resize(V, false);
    g.brKomponenti = 0;
}

void dodaj_granu(Graf& g, int u, int v){
    g.lista_susedstva[u].push_back(v);
    g.lista_susedstva[v].push_back(u);
}

void dfs(Graf& g, int u){
    g.posecen[u] = true;
    
    auto pocetak = g.lista_susedstva[u].begin();
    auto kraj = g.lista_susedstva[u].end();
    
    while(pocetak != kraj){
        if(!g.posecen[*pocetak])
            dfs(g, *pocetak);
        pocetak++;
    }
}

int brojKomponentiPovezanosti(Graf& g){
    for(int i = 0; i < g.V; i++){
        if(!g.posecen[i]){
            g.brKomponenti++;
            dfs(g, i);
        }
    }
    
    return g.brKomponenti;
}

int main(){
    
    Graf g;
    inicijalizuj(g, 7);
    
    dodaj_granu(g, 0, 1);
    dodaj_granu(g, 0, 2);
    dodaj_granu(g, 1, 2);
    dodaj_granu(g, 2, 3);
    dodaj_granu(g, 3, 3);
    dodaj_granu(g, 4, 5);
    dodaj_granu(g, 4, 4);
    dodaj_granu(g, 6, 6);
    
    cout << brojKomponentiPovezanosti(g) << endl;
    
    return 0;
}
