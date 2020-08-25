/* U neusmerenom grafu G odrediti put najmanje tezine izmedju 
 * cvorova u i v. Ukoliko postoji vise puteva iste tezine 
 * ispisati onaj koji sadrzi najmanje grana. */

#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<stack>
using namespace std;

struct Graf {
    int V;
    vector<vector<pair<int,int>>> lista_susedstva;
    vector<int> rastojanja;
    vector<bool> pronadjen_put;
    vector<int> roditelji;
    vector<int> najkraci_put;
};

void inicijalizuj(Graf& g, int V){
    g.V = V;
    g.lista_susedstva.resize(V);
    g.roditelji.resize(V, -1);
    g.rastojanja.resize(V, INT_MAX);
    g.pronadjen_put.resize(V, false);
    g.najkraci_put.resize(V, INT_MAX);
}

void dodaj_granu(Graf& g, int u, int v, int tezina){
    g.lista_susedstva[u].push_back(make_pair(v, tezina));
    g.lista_susedstva[v].push_back(make_pair(u, tezina));
}

struct poredi {
    bool operator()(const pair<int,int>& p1, const pair<int,int>& p2){
        return p1.first > p2.first;
    }
};

void dijkstra(Graf& g, int u, int v){
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, poredi> hip;
    
    g.rastojanja[u] = 0;
    g.najkraci_put[u] = 0;
    
    hip.push(make_pair(g.rastojanja[u], u));
    
    pair<int,int> pom;
    
    while(!hip.empty()){
        pom = hip.top();
        hip.pop();
        
        if(g.pronadjen_put[pom.second])
            continue;
        
        g.pronadjen_put[pom.second] = true;
        
        for(pair<int,int>& sused : g.lista_susedstva[pom.second]){
            if(g.rastojanja[sused.first] >= g.rastojanja[pom.second] + sused.second
                && g.najkraci_put[sused.first] > g.najkraci_put[pom.second] + 1){
                    
                    g.najkraci_put[sused.first] = g.najkraci_put[pom.second] + 1;
                    g.roditelji[sused.first] = pom.second;
                    
                    g.rastojanja[sused.first] = g.rastojanja[pom.second] + sused.second;
                    
                    hip.push(make_pair(g.rastojanja[sused.first], sused.first));
            }
        }
    }
    
    stack<int> put;
    
    while(g.roditelji[v] != -1){
        put.push(v);
        v = g.roditelji[v];
    }
    put.push(v);
    
    int n = put.size();
    int cvor;
    
    while(n > 0){
        cvor = put.top();
        put.pop();
        
        if(n > 1)
            cout << cvor << " -> ";
        else
            cout << cvor << endl;
        
        n--;
    }
}

int main(){
    
    Graf g;
    inicijalizuj(g, 9);
    
    dodaj_granu(g, 0, 1, 4);
    dodaj_granu(g, 0, 7, 8);
    dodaj_granu(g, 1, 7, 11);
    dodaj_granu(g, 1, 2, 8);
    dodaj_granu(g, 2, 8, 2);
    dodaj_granu(g, 2, 3, 7);
    dodaj_granu(g, 7, 8, 7);
    dodaj_granu(g, 7, 6, 1);
    dodaj_granu(g, 8, 6, 6);
    dodaj_granu(g, 2, 5, 4);
    dodaj_granu(g, 6, 5, 2);
    dodaj_granu(g, 3, 5, 14);
    dodaj_granu(g, 3, 4, 9);
    dodaj_granu(g, 4, 5, 10);
    
    int u, v;
    cin >> u >> v;
    
    dijkstra(g, u, v);
    
    return 0;
}
