/* Implementirati BFS pretragu grafa za usmereni/neusmereni
 * graf koji je predstavljen listom. */

#include<iostream>
#include<vector>
#include<queue>
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
    // g.lista_susedstva[v].push_back(u);
}

void bfs(Graf& g, int u){
    
    queue<int> cvorovi;
    cvorovi.push(u);
    
    int pom;
    
    while(!cvorovi.empty()){
        pom = cvorovi.front();
        cvorovi.pop();
        cout << pom << " ";
        
        g.posecen[pom] = true;
        
        auto pocetak = g.lista_susedstva[pom].begin();
        auto kraj = g.lista_susedstva[pom].end();
        
        while(pocetak != kraj){
            if(!g.posecen[*pocetak]){
                g.posecen[*pocetak] = true;
                cvorovi.push(*pocetak);
            }
            pocetak++;
        }
    }
    
    cout << endl;
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
    
    bfs(g, 2);
    
    return 0;
}
