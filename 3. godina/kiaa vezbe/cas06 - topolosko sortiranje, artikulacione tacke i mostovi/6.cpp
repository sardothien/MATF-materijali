/* Neka je dat aciklicki usmeren graf G. Konstruisati algoritam 
 * koji dodaje maksimalan broj grana u ovom grafu tako da on i 
 * dalje ostane aciklican. */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Graf {
    int V;
    vector<vector<int>> lista_susedstva;
    vector<bool> posecen;
    vector<int> ulazni_stepen;
    vector<int> topolosko;
    vector<pair<int, int>> grane;
    vector<pair<int, int>> dodate_grane;
};

void inicijalizuj(Graf& g, int V){
    g.V = V;
    g.lista_susedstva.resize(V);
    g.posecen.resize(V, false);
    g.ulazni_stepen.resize(V, 0);
}

void dodaj_granu(Graf& g, int u, int v){
    g.lista_susedstva[u].push_back(v);
    g.ulazni_stepen[v]++;
    g.grane.push_back({u, v});
}

void topolosko_sortiranje(Graf& g){
    
    queue<int> cvorovi;
    
    for(int i = 0; i < g.V; i++)
        if(g.ulazni_stepen[i] == 0)
            cvorovi.push(i);
        
    int pom;
    
    while(!cvorovi.empty()){
        pom = cvorovi.front();
        cvorovi.pop();
        
        cout << pom << " ";
        
        g.topolosko.push_back(pom);
        
        for(auto cvor : g.lista_susedstva[pom]){
            g.ulazni_stepen[cvor]--;
            if(g.ulazni_stepen[cvor] == 0)
                cvorovi.push(cvor);
        }
    }
    
    cout << endl;
}

void dodaj_grane(Graf& g){
    
    topolosko_sortiranje(g);
    
    for(int u = 0; u < g.V; u++){
        for(int v : g.lista_susedstva[g.topolosko[u]])
            g.posecen[v] = true;
        
        for(int j = u+1; j < g.V; j++){
            if(!g.posecen[g.topolosko[j]]){
                g.grane.push_back({g.topolosko[u], g.topolosko[j]});
                g.dodate_grane.push_back({g.topolosko[u], g.topolosko[j]});
            }
            
            g.posecen[g.topolosko[j]] = false;
        }
    }
    
    cout << "Sve grane:" << endl; 
    for(auto p : g.grane)
        cout << p.first << " -> " << p.second << endl;

    cout << "Dodate grane: " << endl;
    for(auto p : g.dodate_grane)
        cout << p.first << " -> " << p.second << endl;
}

int main(){
    
    Graf g;
    inicijalizuj(g, 6);
    
    dodaj_granu(g, 2, 3);
    dodaj_granu(g, 3, 1);
    dodaj_granu(g, 4, 0);
    dodaj_granu(g, 4, 1);
    dodaj_granu(g, 5, 0);
    dodaj_granu(g, 5, 2);
    
    dodaj_grane(g);
    
    return 0;
}
