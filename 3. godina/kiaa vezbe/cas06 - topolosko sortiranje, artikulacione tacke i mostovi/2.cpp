/* Implementirati Kanov algoritam za topolosko sortiranje grafa. */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Graf {
    int V;
    vector<vector<int>> lista_susedstva;
    vector<int> ulazni_stepen;
};

void inicijalizuj(Graf& g, int V){
    g.V = V;
    g.lista_susedstva.resize(V);
    g.ulazni_stepen.resize(V, 0);
}

void dodaj_granu(Graf& g, int u, int v){
    g.lista_susedstva[u].push_back(v);
    g.ulazni_stepen[v]++;
}

void kan(Graf& g){
    
    queue<int> cvorovi;
    
    for(int i = 0; i < g.V; i++)
        if(g.ulazni_stepen[i] == 0)
            cvorovi.push(i);
        
    int pom;
    
    while(!cvorovi.empty()){
        pom = cvorovi.front();
        cvorovi.pop();
        
        cout << pom << " ";
        
        for(int cvor : g.lista_susedstva[pom]){
            g.ulazni_stepen[cvor]--;
            if(g.ulazni_stepen[cvor] == 0)
                cvorovi.push(cvor);
        }
    }
    
    cout << endl;
}

int main(){
    
    Graf g;
    inicijalizuj(g, 6);
    
    dodaj_granu(g, 0, 1);
    dodaj_granu(g, 1, 4);
    dodaj_granu(g, 2, 4);
    dodaj_granu(g, 3, 0);
    dodaj_granu(g, 3, 2);
    dodaj_granu(g, 5, 2);
    dodaj_granu(g, 5, 4);
    
    kan(g);
    
    return 0;
}
