/* Konstruisati algoritam koji odredjuje minimalan broj 
 * grana na putu od cvora u do cvora v u usmerenom grafu G. */

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

struct Graf {
    int V;
    vector<vector<int>> lista_susedstva;
    vector<bool> posecen;
    int minBrojGrana;
};

void inicijalizuj(Graf& g, int V){
    g.V = V;
    g.lista_susedstva.resize(V);
    g.posecen.resize(V, false);
    g.minBrojGrana = INT_MAX;
}

void dodaj_granu(Graf& g, int u, int v){
    g.lista_susedstva[u].push_back(v);
}

void dfs(Graf& g, int u, int v, int min){
    if(u == v){
        if(min < g.minBrojGrana)
            g.minBrojGrana = min;
        
        return;
    }
    
    g.posecen[u] = true;
    
    auto pocetak = g.lista_susedstva[u].begin();
    auto kraj = g.lista_susedstva[u].end();
    
    while(pocetak != kraj){
        if(!g.posecen[*pocetak])
            dfs(g, *pocetak, v, min+1);
        pocetak++;
    }
    
    g.posecen[u] = false;
}

int main(){
    
    Graf g;
    inicijalizuj(g, 5);
    
    dodaj_granu(g, 0, 1);
    dodaj_granu(g, 1, 0);
    dodaj_granu(g, 0, 4);
    dodaj_granu(g, 4, 0);
    dodaj_granu(g, 1, 2);
    dodaj_granu(g, 2, 1);
    dodaj_granu(g, 2, 4);
    dodaj_granu(g, 4, 2);
    dodaj_granu(g, 2, 3);
    dodaj_granu(g, 3, 2);
    dodaj_granu(g, 3, 4);
    dodaj_granu(g, 4, 3);
    
    int u, v;
    cin >> u >> v;
    
    dfs(g, u, v, 0);
    
    cout << g.minBrojGrana << endl;
    
    return 0;
}
