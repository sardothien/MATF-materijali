/* Koristeci BFS pretragu grafa pronaci najkraci put 
 * izmedju cvora u i cvora v u neusmerenom grafu G. */

#include<iostream>
#include<vector>
#include<queue>
#include<stack>
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

void bfs(Graf& g, int u, int v){
    queue<int> cvorovi;
    cvorovi.push(u);
    
    g.posecen[u] = true;
    
    int pom;
    
    while(!cvorovi.empty()){
        pom = cvorovi.front();
        cvorovi.pop();
        
        if(pom == v)
            return;
        
        auto pocetak = g.lista_susedstva[pom].begin();
        auto kraj = g.lista_susedstva[pom].end();
        
        while(pocetak != kraj){
            if(!g.posecen[*pocetak]){
                g.posecen[*pocetak] = true;
                g.roditelji[*pocetak] = pom;
                cvorovi.push(*pocetak);
            }
            
            pocetak++;
        }
    }
}

void najkraciPut(Graf& g, int u, int v){
    
    bfs(g, u, v);
   
    if(g.roditelji[v] == -1){
        cout << "Ne postoji put do cvora v!" << endl;
        return;
    }
    
    stack<int> put;
    put.push(v);
    
    while(g.roditelji[v] != -1){
        v = g.roditelji[v];
        put.push(v);
    }
    
    int x;
    int n = put.size();
    
    while(n){
        x = put.top();
        put.pop();
        if(n > 1)
            cout << x << " -> ";
        else
            cout << x << endl;
        n--;
    }    
}

int main(){
    
    Graf g;
    inicijalizuj(g, 8);
    
    dodaj_granu(g, 0, 1);
    dodaj_granu(g, 0, 3);
    dodaj_granu(g, 1, 2);
    dodaj_granu(g, 3, 4);
    dodaj_granu(g, 3, 7);
    dodaj_granu(g, 4, 5);
    dodaj_granu(g, 4, 6);
    dodaj_granu(g, 4, 7);
    dodaj_granu(g, 5, 6);
    dodaj_granu(g, 6, 7);
    
    int u, v;
    cin >> u >> v;
    
    najkraciPut(g, u, v);
    
    return 0;
}
