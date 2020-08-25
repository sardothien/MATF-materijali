/* Neka je dat skup aerodroma. Putnik moze da zahteva da ide 
 * preko nekog grada ili moze da trazi da preko nekog grada 
 * nikako ne leti. Odrediti minimalnu kilometrazu koju putnik 
 * mora da predje ako ide preko zadatog grada, odnosno izbegava isti. */

#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

struct Graf {
    int V;
    vector<vector<pair<int,int>>> lista_susedstva;
    vector<int> rastojanja;
    vector<bool> pronadjen_put;
};

void inicijalizuj(Graf& g, int V){
    g.V = V;
    g.lista_susedstva.resize(V);
    g.rastojanja.resize(V, INT_MAX);
    g.pronadjen_put.resize(V, false);
}

void dodaj_granu(Graf& g, int u, int v, int tezina){
    g.lista_susedstva[u].push_back(make_pair(v, tezina));
    g.lista_susedstva[v].push_back(make_pair(u, tezina));
}

void reset(Graf& g){
    fill(g.rastojanja.begin(), g.rastojanja.end(), INT_MAX);
    fill(g.pronadjen_put.begin(), g.pronadjen_put.end(), false);
}

struct poredi {
    bool operator()(pair<int,int>& p1, pair<int,int>& p2){
        return p1.first > p2.first;
    }
};

int dijkstra(Graf& g, int u, int v, int zaobidji){
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, poredi> hip;
    
    g.rastojanja[u] = 0;
    
    hip.push(make_pair(g.rastojanja[u], u));
    
    pair<int,int> pom;
    
    while(!hip.empty()){
        pom = hip.top();
        hip.pop();
        
        if(g.pronadjen_put[pom.second])
            continue;
        
        g.pronadjen_put[pom.second] = true;
        
        for(pair<int,int>& sused : g.lista_susedstva[pom.second]){
            if(sused.first == zaobidji)
                continue;
            
            if(g.rastojanja[sused.first] > g.rastojanja[pom.second] + sused.second){
                g.rastojanja[sused.first] = g.rastojanja[pom.second] + sused.second;
                hip.push(make_pair(g.rastojanja[sused.first], sused.first));
            }
        }
    }
    
    return g.rastojanja[v];
}

int najkraciPutPrekoCvora(Graf& g, int u, int v, int cvor){
    int rezultat = dijkstra(g, u, cvor, -1);
    
    reset(g);
    
    return rezultat + dijkstra(g, cvor, v, -1);
}

int najkraciPutZaobilazak(Graf& g, int u, int v, int cvor){
    return dijkstra(g, u, v, cvor);
}

int main(){
    
    Graf g;
    inicijalizuj(g, 5);
    
    dodaj_granu(g, 0, 1, 10);
    dodaj_granu(g, 0, 2, 2);
    dodaj_granu(g, 1, 3, 9);
    dodaj_granu(g, 2, 3, 7);
    dodaj_granu(g, 2, 4, 5);
    dodaj_granu(g, 3, 4, 6);
    
    cout << najkraciPutPrekoCvora(g, 0, 1, 4) << endl;
    
    reset(g);
    cout << najkraciPutZaobilazak(g, 0, 3, 2) << endl;
    
    return 0;
}
