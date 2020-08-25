/* Implementirati Fleury-ev algoritam za odredjivanje 
 * Ojlerovog ciklusa/puta u neusmerenom grafu G. */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Graf {
    int V;
    vector<vector<int>> lista_susedstva;
    vector<bool> posecen;
    vector<int> stepeni;
};

void inicijalizuj(Graf& g, int V){
    g.V = V;
    g.lista_susedstva.resize(V);
    g.posecen.resize(V, false);
    g.stepeni.resize(V, 0);
}

void dodaj_granu(Graf& g, int u, int v){
    g.lista_susedstva[u].push_back(v);
    g.lista_susedstva[v].push_back(u);
    g.stepeni[u]++;
    g.stepeni[v]++;
}

int brojNeparnih(Graf& g){
    int br = 0;
    
    for(int i = 0; i < g.V; i++)
        if(g.stepeni[i] % 2 == 1)
            br++;
        
    return br;
}

int nadji_cvor_parnog_stepena(Graf& g){
    for(int i = 0; i < g.V; i++)
        if(g.stepeni[i] % 2 == 0 && g.stepeni[i] != 0)
            return i;
}

int nadji_cvor_neparnog_stepena(Graf& g){
    for(int i = 0; i < g.V; i++)
        if(g.stepeni[i] % 2 == 1)
            return i;
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

void ukloni_granu(Graf& g, int u, int v){
    g.lista_susedstva[u].erase(find(g.lista_susedstva[u].begin(), g.lista_susedstva[u].end(), v));
    g.lista_susedstva[v].erase(find(g.lista_susedstva[v].begin(), g.lista_susedstva[v].end(), u));
}

bool validna_grana(Graf& g, int u, int v){
    
    if(g.lista_susedstva[u].size() == 1)
        return true;
    
    ukloni_granu(g, u, v);
    
    fill(g.posecen.begin(), g.posecen.end(), false);
    
    dfs(g, u);
    
    dodaj_granu(g, u, v);
    
    if(!g.posecen[u])
        return false;
    
    return true;
}

void ispisi(Graf& g, int u){
    for(int v : g.lista_susedstva[u]){
        if(validna_grana(g, u, v)){
            cout << u << " -> " << v << endl;
            ukloni_granu(g, u, v);
            ispisi(g, v);
            break;
        }
    }
}

void fleury(Graf& g){
    
    int neparni = brojNeparnih(g);
    
    int start;
    if(neparni == 0){
        start = nadji_cvor_parnog_stepena(g);
        ispisi(g, start);
    }
    else if(neparni == 2){
        start = nadji_cvor_neparnog_stepena(g);
        ispisi(g, start);
    }
}

int main(){
    
    Graf g;
    inicijalizuj(g, 5);
    
//     dodaj_granu(g, 0, 1);
//     dodaj_granu(g, 1, 2);
//     dodaj_granu(g, 2, 0);
    
    dodaj_granu(g, 0, 1);
    dodaj_granu(g, 0, 2);
    dodaj_granu(g, 0, 3);
    dodaj_granu(g, 1, 2);
    dodaj_granu(g, 1, 3);
    dodaj_granu(g, 2, 3);
    dodaj_granu(g, 2, 4);
    dodaj_granu(g, 3, 4);
    
    fleury(g);
    
    return 0;
}
