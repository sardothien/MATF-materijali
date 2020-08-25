/* Implementirati DFS pretragu grafa za usmereni/neusmereni
 * graf koji je predstavljen listom. */

#include<iostream>
#include<vector>
using namespace std;

struct Graf {
    int V;
    vector<vector<int>> lista_susedstva;
    vector<bool> posecen;
};

void inicijalizuj(Graf& g, int V){
    g.V = V;
    g.lista_susedstva.resize(V);
    g.posecen.resize(V, false);
}

void dodaj_granu(Graf& g, int u, int v){
    g.lista_susedstva[u].push_back(v);
    // ako imamo neusmereni graf, treba dodati i:
    // g.lista_susedstva[v].push_back(u);
}

void dfs(Graf& g, int u){
    g.posecen[u] = true;
    cout << u << " ";
    
    auto pocetak = g.lista_susedstva[u].begin();
    auto kraj = g.lista_susedstva[u].end();
    
    while(pocetak != kraj){
        if(!g.posecen[*pocetak])
            dfs(g, *pocetak);
        pocetak++;
    }
}

int main(){
    
    Graf g;
    inicijalizuj(g, 4);
    
    dodaj_granu(g, 0, 1);
    dodaj_granu(g, 0, 2);
    dodaj_granu(g, 1, 2);
    dodaj_granu(g, 2, 0);
    dodaj_granu(g, 2, 3);
    dodaj_granu(g, 3, 3);
    
    dfs(g, 0);
 
    cout << endl;
    
    return 0;
}
