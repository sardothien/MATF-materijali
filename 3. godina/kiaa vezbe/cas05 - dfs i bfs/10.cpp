/* Konstruisati algoritam koji za usmereni graf G proverava
 * da li je bipartitan. Koristiti DFS algoritam. */

#include<iostream>
#include<vector>
using namespace std;

struct Graf {
    int V;
    vector<vector<int>> lista_susedstva;
    vector<bool> posecen;
    vector<int> boje;
};

void inicijalizuj(Graf& g, int V){
    g.V = V;
    g.lista_susedstva.resize(V);
    g.posecen.resize(V, false);
    g.boje.resize(V, -1);
}

void dodaj_granu(Graf& g, int u, int v){
    g.lista_susedstva[u].push_back(v);
}

bool dfs(Graf& g, int u, int boja){
    g.posecen[u] = true;
    g.boje[u] = boja;
    
    auto pocetak = g.lista_susedstva[u].begin();
    auto kraj = g.lista_susedstva[u].end();
    
    while(pocetak != kraj){
        if(g.boje[*pocetak] == g.boje[u])
            return false;
        if(!g.posecen[*pocetak])
            if(!dfs(g, *pocetak, !boja))
                return false;
            
        pocetak++;
    }
    
    return true;
} 

int main(){
    
    Graf g;
    inicijalizuj(g, 6);
    
    dodaj_granu(g, 0, 1);
    dodaj_granu(g, 1, 2);
    dodaj_granu(g, 2, 3);
    dodaj_granu(g, 3, 4);
    dodaj_granu(g, 4, 5);
    dodaj_granu(g, 5, 0);
    
    cout << (dfs(g, 0, 0) ? "Jeste bipartitan" : "Nije bipartitan") << endl;    
    
    return 0;
}
