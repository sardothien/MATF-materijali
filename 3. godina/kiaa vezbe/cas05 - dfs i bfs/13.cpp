/* Neka je dato stablo u vidu usmerenog grafa. Svaki Cvor 
 * moze da ima od 1 do n sinova. Odrediti broj cvorova na 
 * nivou i koristeci BFS algoritam. */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Graf {
    int V;
    vector<vector<int>> lista_susedstva;
    vector<bool> posecen;
    vector<int> nivoi;
};

void inicijalizuj(Graf& g, int V){
    g.V = V;
    g.lista_susedstva.resize(V);
    g.posecen.resize(V, false);
    g.nivoi.resize(V);
}

void dodaj_granu(Graf& g, int u, int v){
    g.lista_susedstva[u].push_back(v);
}

void bfs(Graf& g, int u, int nivo){
    
    queue<int> cvorovi;
    cvorovi.push(u);
    
    int trenutniNivo = 0;
    g.nivoi[u] = trenutniNivo;
    
    int pom;
    
    while(!cvorovi.empty()){
        pom = cvorovi.front();
        cvorovi.pop();
        
        auto pocetak = g.lista_susedstva[pom].begin();
        auto kraj = g.lista_susedstva[pom].end();
        
        while(pocetak != kraj){
            if(!g.posecen[*pocetak]){
                g.posecen[*pocetak] = true;
                g.nivoi[*pocetak] = g.nivoi[pom] + 1;
                cvorovi.push(*pocetak);
            }
            
            pocetak++;
        }
    }
    
    int br = 0;
    for(int x : g.nivoi)
        if(x == nivo)
            br++;
    
    cout << br << endl;
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
    
    bfs(g, 0, nivo);  
    
    return 0;
}
