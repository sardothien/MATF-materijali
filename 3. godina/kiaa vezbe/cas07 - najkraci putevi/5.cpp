/* Neka je dato n gradova koji su povezani dvosmernim putevima. U nekim
 * od gradova postoje policijske stanice. Za svaki od gradova odrediti 
 * njegovu udaljenost od najblize policijske stanice. */

#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

struct poredi {
    bool operator()(const pair<int,int>& p1, const pair<int,int>& p2){
        return p1.second > p2.second;
    }
};

struct Graf {
    int V;
    vector<vector<int>> lista_susedstva;
    vector<int> rastojanja;
    vector<bool> pronadjen_put;
    vector<int> stanice;
    priority_queue<pair<int,int>, vector<pair<int,int>>, poredi> hip;
};

void inicijalizuj(Graf& g, int V){
    g.V = V;
    g.lista_susedstva.resize(V);
    g.rastojanja.resize(V, INT_MAX);
    g.pronadjen_put.resize(V, false);
}

void dodaj_granu(Graf& g, int u, int v){
    g.lista_susedstva[u].push_back(v);
    g.lista_susedstva[v].push_back(u);
}

void dodaj_stanicu(Graf& g, int u){
    g.stanice.push_back(u);
}

void dijkstra(Graf& g){
    
    pair<int,int> pom;
    
    while(!g.hip.empty()){
        pom = g.hip.top();
        g.hip.pop();
        
        if(g.pronadjen_put[pom.first])
            continue;
        
        g.pronadjen_put[pom.first] = true;
        
        for(int sused : g.lista_susedstva[pom.first]){
            if(g.rastojanja[sused] > g.rastojanja[pom.first] + 1){
                g.rastojanja[sused] = g.rastojanja[pom.first] + 1;
                g.hip.push(make_pair(sused, g.rastojanja[sused]));
            }
        }
    }
}

void najblizaStanica(Graf& g){
    
    for(int stanica : g.stanice){
        g.hip.push(make_pair(stanica, 0));
        g.rastojanja[stanica] = 0;
    }
    
    dijkstra(g);
    
    for(int i = 0; i < g.V; i++)
        cout << i << ": " << g.rastojanja[i] << endl;
}

int main(){
    
    Graf g;
    inicijalizuj(g, 7);
    
    dodaj_granu(g, 0, 1);
    dodaj_granu(g, 0, 5);
    dodaj_granu(g, 1, 2);
    dodaj_granu(g, 1, 5);
    dodaj_granu(g, 2, 3);
    dodaj_granu(g, 2, 4);
    dodaj_granu(g, 2, 5);
    dodaj_granu(g, 3, 4);
    dodaj_granu(g, 2, 6);
    
    dodaj_stanicu(g, 0);
    dodaj_stanicu(g, 4);
    
    najblizaStanica(g);
    
    return 0;
}
