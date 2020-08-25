/* Implementirati Tarjan-ov algoritam za odredjivanje komponenti
 * jake povezanosti usmerenog grafa G. */

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct Graf {
    int V;
    vector<vector<int>> lista_susedstva;
    vector<int> vremena;
    vector<int> min_vremena;
    stack<int> stek;
    vector<bool> u_steku;
    int vreme;
};

void inicijalizuj(Graf& g, int V){
    g.V = V;
    g.lista_susedstva.resize(V);
    g.vremena.resize(V, -1);
    g.min_vremena.resize(V, -1);
    g.u_steku.resize(V, false);
    g.vreme = 0;
}

void dodaj_granu(Graf& g, int u, int v){
    g.lista_susedstva[u].push_back(v);
}

void tardzan(Graf& g, int u){
    
    g.vremena[u] = g.min_vremena[u] = g.vreme;
    g.vreme++;
    
    g.stek.push(u);
    g.u_steku[u] = true;
    
    auto pocetak = g.lista_susedstva[u].begin();
    auto kraj = g.lista_susedstva[u].end();
    
    while(pocetak != kraj){
        if(g.vremena[*pocetak] == -1){ // nije posecen
            tardzan(g, *pocetak);
            g.min_vremena[u] = min(g.min_vremena[*pocetak], g.min_vremena[u]);
        }
        else if(g.u_steku[*pocetak]){
            g.min_vremena[u] = min(g.min_vremena[u], g.vremena[*pocetak]);
        }
        
        pocetak++;
    }
    
    if(g.vremena[u] == g.min_vremena[u]){
        while(1){
            int v = g.stek.top();
            g.stek.pop();
            
            cout << v << " ";
            
            g.u_steku[v] = false;
            
            if(v == u){
                cout << endl;
                break;
            }
        }
    }
}

int main(){
    
    Graf g;
    inicijalizuj(g, 8);
    
    dodaj_granu(g, 0, 1);
    dodaj_granu(g, 0, 2);
    dodaj_granu(g, 1, 0);
    dodaj_granu(g, 1, 3);
    dodaj_granu(g, 2, 3);
    dodaj_granu(g, 3, 4);
    dodaj_granu(g, 3, 5);
    dodaj_granu(g, 4, 2);
    dodaj_granu(g, 4, 5);
    dodaj_granu(g, 4, 6);
    dodaj_granu(g, 5, 7);
    dodaj_granu(g, 6, 5);
    dodaj_granu(g, 7, 6);
    
    tardzan(g, 0);
    
    return 0;
}
