/* Ispisati sve putanje od cvora u do cvora v u usmerenom grafu G. */

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
}

void dfs(Graf& g, int u, int v, vector<int> rezultat){
    if(u == v){
        rezultat.push_back(u);
        
        int i;
        for(i = 0; i < rezultat.size()-1; i++)
            cout << rezultat[i] << " -> ";
        cout << rezultat[i] << endl;
        
        return;
    }
    
    g.posecen[u] = true;
    rezultat.push_back(u);
    
    auto pocetak = g.lista_susedstva[u].begin();
    auto kraj = g.lista_susedstva[u].end();
    
    while(pocetak != kraj){
        if(!g.posecen[*pocetak])
            dfs(g, *pocetak, v, rezultat);
        pocetak++;
    }
    
    // trazimo sve puteve
    g.posecen[u] = false;
}

int main(){
    
    Graf g;
    inicijalizuj(g, 4);
    
    dodaj_granu(g, 0, 1);
    dodaj_granu(g, 0, 2);
    dodaj_granu(g, 0, 3);
    dodaj_granu(g, 2, 0);
    dodaj_granu(g, 2, 1);
    dodaj_granu(g, 1, 3);
    
    int u, v;
    cin >> u >> v;
    
    vector<int> rezultat;
    
    dfs(g, u, v, rezultat);
    
    return 0;
}
