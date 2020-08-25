/* Konstruisati algoritam koji ispisuje putanju od cvora u
 * do cvora v u usmerenom/neusmerenom grafu G. Algoritam 
 * treba da bude zanovan na DFS pretrazi grafa. */

#include<iostream>
#include<vector>
using namespace std;

struct Graf {
    int V;
    vector<vector<int>> lista_susedstva;
    vector<bool> posecen;
    bool nadjen;
};

void inicijalizuj(Graf& g, int V){
    g.V = V;
    g.lista_susedstva.resize(V);
    g.posecen.resize(V, false);
    g.nadjen = false;
}

void dodaj_granu(Graf& g, int u, int v){
    g.lista_susedstva[u].push_back(v);
    // g.lista_susedstva[v].push_back(u);
}

bool dfs(Graf& g, int u, int v, vector<int>& rezultat){
    if(u == v){
        rezultat.push_back(u);
        g.nadjen = true;
        return true;
    }
    
    g.posecen[u] = true;
    rezultat.push_back(u);
    
    auto pocetak = g.lista_susedstva[u].begin();
    auto kraj = g.lista_susedstva[u].end();
    
    while(pocetak != kraj){
        bool vr = false;
        
        if(!g.posecen[*pocetak] && !g.nadjen)
            vr = dfs(g, *pocetak, v, rezultat);
        
        if(vr)
            return true;
        
        rezultat.pop_back();
        pocetak++;
    }
    
    return false;
}

int main(){
    
    Graf g;
    inicijalizuj(g, 5);
    
    dodaj_granu(g, 0, 1);
    dodaj_granu(g, 1, 2);
    dodaj_granu(g, 1, 3);
    dodaj_granu(g, 3, 4);
    
    int u, v;
    cin >> u >> v;
    
    vector<int> rezultat;
    
    if(dfs(g, u, v, rezultat)){
        int i;
        for(i = 0; i < rezultat.size()-1; i++)
            cout << rezultat[i] << " -> ";
        cout << rezultat[i] << endl;
    }
    else{
        cout << "Nema puta..." << endl;
    }
    
    return 0;
}
