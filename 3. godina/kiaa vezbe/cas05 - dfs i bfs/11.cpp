/* Konstruisati algoritam koji za neusmereni graf G proverava da
 * li u njemu postoji ciklus. Algoritam bazirati na BFS pretrazi grafa. */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Graf {
    int V;
    vector<vector<int>> lista_susedstva;
    vector<bool> posecen;
    vector<int> roditelji;
};

void inicijalizuj(Graf& g, int V){
    g.V = V;
    g.lista_susedstva.resize(V);
    g.posecen.resize(V, false);
    g.roditelji.resize(V, -1);
}

void dodaj_granu(Graf& g, int u, int v){
    g.lista_susedstva[u].push_back(v);
    g.lista_susedstva[v].push_back(u);
}

bool bfs(Graf& g, int u){
    
    queue<int> cvorovi;
    cvorovi.push(u);
    
    int pom;
    
    while(!cvorovi.empty()){
        pom = cvorovi.front();
        cvorovi.pop();
        
        auto pocetak = g.lista_susedstva[pom].begin();
        auto kraj = g.lista_susedstva[pom].end();
        
        while(pocetak != kraj){
            if(!g.posecen[*pocetak]){
                g.posecen[*pocetak] = true;
                g.roditelji[*pocetak] = pom;
                cvorovi.push(*pocetak);
            }
            else if(g.roditelji[pom] != *pocetak)
                return true;
            
            pocetak++;
        }
    }
    
    return false;
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
    
    cout << (bfs(g, 0) ? "Ima ciklus" : "Nema ciklus") << endl;
    
    return 0;
}
