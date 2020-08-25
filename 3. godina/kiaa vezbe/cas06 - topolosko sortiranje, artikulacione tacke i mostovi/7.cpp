/* Konstruisati algoritam za odredjivanje svih 
 * artikulacionih tacaka u neusmerenom grafu G. */

#include<iostream>
#include<vector>
#include<set>
using namespace std;

struct Graf {
    int V;
    vector<vector<int>> lista_susedstva;
    vector<bool> posecen;
    vector<int> roditelji;
    vector<int> vremena;
    vector<int> min_vremena;
    set<int> artikulacione_tacke;
    int vreme;
};

void inicijalizuj(Graf& g, int V){
    g.V = V;
    g.lista_susedstva.resize(V);
    g.posecen.resize(V, false);
    g.roditelji.resize(V, -1);
    g.vremena.resize(V, -1);
    g.min_vremena.resize(V, -1);
    g.vreme = 0;
}

void dodaj_granu(Graf& g, int u, int v){
    g.lista_susedstva[u].push_back(v);
    g.lista_susedstva[v].push_back(u);
}

void dfs(Graf& g, int u){
    
    g.posecen[u] = true;
    g.vremena[u] = g.min_vremena[u] = g.vreme;
    g.vreme++;
    
    int deca = 0;
    
    auto pocetak = g.lista_susedstva[u].begin();
    auto kraj = g.lista_susedstva[u].end();
    
    while(pocetak != kraj){
        if(!g.posecen[*pocetak]){
            g.roditelji[*pocetak] = u;
            
            dfs(g, *pocetak);
            
            deca++;
            g.min_vremena[u] = min(g.min_vremena[*pocetak], g.min_vremena[u]);
            
            if(g.roditelji[u] == -1 && deca > 1)
                g.artikulacione_tacke.insert(u);
            
            if(g.roditelji[u] != -1 && g.vremena[u] <= g.min_vremena[*pocetak])
                g.artikulacione_tacke.insert(u);
        }
        else if(*pocetak != g.roditelji[u]){
            g.min_vremena[u] = min(g.min_vremena[u], g.vremena[*pocetak]);
        }
        
        pocetak++;
    }
}

void nadji_artikulacione_tacke(Graf& g){
    dfs(g, 3);
    
    for(int x : g.artikulacione_tacke)
        cout << x << " ";
    cout << endl;
}

int main(){
    
    Graf g;
    inicijalizuj(g, 8);
    
    dodaj_granu(g, 0, 1);
    dodaj_granu(g, 0, 2);
    dodaj_granu(g, 1, 2);
    dodaj_granu(g, 2, 3);
    dodaj_granu(g, 3, 4);
    dodaj_granu(g, 4, 5);
    dodaj_granu(g, 4, 6);
    dodaj_granu(g, 5, 6);
    dodaj_granu(g, 5, 7);
    dodaj_granu(g, 2, 6);
    
    nadji_artikulacione_tacke(g);
    
    return 0;
}
