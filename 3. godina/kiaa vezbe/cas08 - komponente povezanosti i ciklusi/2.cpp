/* Implementirati Kosaraju-ov algoritam za proveru da 
 * li je usmereni graf G jako povezan. */

#include<iostream>
#include<vector>
using namespace std;

struct Graf {
    int V;
    vector<vector<int>> lista_susedstva;
    vector<bool> posecen;
};

void inicijalizuj(Graf& g, int V){
    g.V = V;
    g.lista_susedstva.resize(V);
    g.posecen.resize(V, false);
}

void dodaj_granu(Graf& g, int u, int v){
    g.lista_susedstva[u].push_back(v);
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
        if(g.posecen[i] == false)
            br++;
        
    return br;
}

bool kosaradzu(Graf& g){
    
    dfs(g, 0);
    
    if(brojNeposecenih(g) > 0)
        return false;
    
    Graf f = obrnute_grane(g);
    
    dfs(f, 0);
    
    if(brojNeposecenih(f) > 0)
        return false;
    
    return true;
}

int main(){
    
    Graf g;
    inicijalizuj(g, 5);
    
    dodaj_granu(g, 0, 1);
    dodaj_granu(g, 1, 2);
    dodaj_granu(g, 2, 3);
    dodaj_granu(g, 3, 0);
    dodaj_granu(g, 2, 4);
    dodaj_granu(g, 4, 2);
    
    cout << (kosaradzu(g) ? "Jeste" : "Nije") << endl;
    
    return 0;
}
