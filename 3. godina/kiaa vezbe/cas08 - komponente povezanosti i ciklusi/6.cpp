/* Implementirati Hierholzer-ov algoritam za pronalazenje
 * Ojlerovog ciklusa u usmerenom grafu G. */

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct Graf {
    int V;
    vector<vector<int>> lista_susedstva;
    vector<int> ojlerov_put;
    stack<int> stek;
};

void inicijalizuj(Graf& g, int V){
    g.V = V;
    g.lista_susedstva.resize(V);
}

void dodaj_granu(Graf& g, int u, int v){
    g.lista_susedstva[u].push_back(v);
}

void hierholzer(Graf& g){
    
    g.stek.push(0);
    
    int v = 0;
    int pom;
    
    while(g.stek.size()){
        if(g.lista_susedstva[v].size()){
            g.stek.push(v);
            
            pom = g.lista_susedstva[v].back();
            g.lista_susedstva[v].pop_back();
            
            v = pom;
        }
        else{
            g.ojlerov_put.push_back(v);
            v = g.stek.top();
            g.stek.pop();
        }
    }
    
    int i;
    for(i = g.ojlerov_put.size()-1; i >= 1; i--)
        cout << g.ojlerov_put[i] << " -> ";
    cout << g.ojlerov_put[i] << endl;
}

int main(){
    
    Graf g;
    inicijalizuj(g, 5);
    
    dodaj_granu(g, 0, 1);
    dodaj_granu(g, 1, 2);
    dodaj_granu(g, 1, 3);
    dodaj_granu(g, 2, 0);
    dodaj_granu(g, 3, 4);
    dodaj_granu(g, 4, 1);
    
    hierholzer(g);
    
    return 0;
}
