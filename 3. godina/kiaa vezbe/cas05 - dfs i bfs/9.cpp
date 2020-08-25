/* Neka je dato stablo u vidu usmerenog grafa. Svaki cvor moze 
 * da ima od 1 do n sinova. Odrediti broj cvorova na nivou i 
 * koristeci DFS algoritam. */

#include<iostream>
#include<vector>
using namespace std;

struct Graf {
    int V;
    vector<vector<int>> lista_susedstva;
    vector<bool> posecen;
    int brCvorova;
};

void inicijalizuj(Graf& g, int V){
    g.V = V;
    g.lista_susedstva.resize(V);
    g.posecen.resize(V, false);
    g.brCvorova = 0;
}

void dodaj_granu(Graf& g, int u, int v){
    g.lista_susedstva[u].push_back(v);
}

void dfs(Graf& g, int u, int nivo, int trenutniNivo){
    g.posecen[u] = true;
    
    if(trenutniNivo == nivo)
        g.brCvorova++;
    
    auto pocetak = g.lista_susedstva[u].begin();
    auto kraj = g.lista_susedstva[u].end();
    
    while(pocetak != kraj){
        if(!g.posecen[*pocetak])
            dfs(g, *pocetak, nivo, trenutniNivo+1);
        pocetak++;
    }
}

int main(){
    
    Graf g;
    inicijalizuj(g, 8);
    
    dodaj_granu(g, 0, 1);
    dodaj_granu(g, 0, 4);
    dodaj_granu(g, 0, 7);
    dodaj_granu(g, 4, 6);
    dodaj_granu(g, 4, 5);
    dodaj_granu(g, 4, 2);
    dodaj_granu(g, 7, 3);
    
    int nivo;
    cin >> nivo;
    
    dfs(g, 0, nivo, 0);
    
    cout << g.brCvorova << endl;    
    
    return 0;
}
