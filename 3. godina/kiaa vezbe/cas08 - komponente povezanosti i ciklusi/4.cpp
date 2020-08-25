/* Konstruisati algoritam koji za dati usmereni graf G
 * utvrdjuje da li sadrzi Ojlerov ciklus.  */

#include<iostream>
#include<vector>
using namespace std;

struct Graf {
    int V;
    vector<vector<int>> lista_susedstva;
    vector<bool> posecen;
    vector<int> ulazni_stepen;
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
}

Graf obrnute_grane(Graf& g){
    Graf f;
    inicijalizuj(f, g.V);
    
    for(int i = 0; i < g.V; i++)
        for(int u : g.lista_susedstva[i])
            dodaj_granu(f, u, i);
        
    return f;
}

void dfs(Graf& g, int u){
    g.posecen[u] = true;
    
    auto pocetak = g.lista_susedstva[u].begin();
    auto kraj = g.lista_susedstva[u].end();
    
    while(pocetak != kraj){
        if(!g.posecen[*pocetak])
            dfs(g, *pocetak);
        pocetak++;
    }
}

int brojNeposecenih(Graf& g){
    int br = 0;
    
    for(int i = 0; i < g.V; i++)
        if(!g.posecen[i] && (g.lista_susedstva[i].size() > 0 || g.ulazni_stepen[i] > 0))
            br++;
        
    return br;
}

bool kosaradzu(Graf& g){
    int start;
    
    for(int i = 0; i < g.V; i++)
        if(g.lista_susedstva[i].size()){
            start = i;
            break;
        }
    
    dfs(g, start);
    
    if(brojNeposecenih(g) > 0)
        return false;
    
    Graf f = obrnute_grane(g);
    
    dfs(f, start);
    
    if(brojNeposecenih(f) > 0)
        return false;
    
    return true;
}

bool ojlerov(Graf& g){
    if(kosaradzu(g) == false)
        return false;
    
    for(int i = 0; i < g.V; i++)
        if(g.ulazni_stepen[i] != g.lista_susedstva[i].size())
            return false;
        
    return true;
}

int main(){
    
    Graf g;
    inicijalizuj(g, 6);
    
    dodaj_granu(g, 0, 2);
    dodaj_granu(g, 0, 3);
    dodaj_granu(g, 1, 0);
    dodaj_granu(g, 2, 1);
    dodaj_granu(g, 3, 4);
    dodaj_granu(g, 4, 0);
    dodaj_granu(g, 4, 5);
    
    cout << (ojlerov(g) ? "Jeste" : "Nije") << endl;
    
    return 0;
}
