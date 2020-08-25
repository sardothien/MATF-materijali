/* Neka je dato n reci. Utvrditi da li je moguce ulancati sve
 * te reci tako sto se kraj jedne od reci nadovezuje na pocetak
 * naredne. Cilj je vratiti se u rec iz koje smo krenuli. */

#include<iostream>
#include<vector>
using namespace std;

#define MAX (26)

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

void dodaj_reci(Graf& g, vector<string>& reci){
    for(string& rec : reci)
        dodaj_granu(g, rec[0]-'a', rec[rec.size()-1]-'a');
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
        if(!g.posecen[i] && g.ulazni_stepen[i])
            br++;
        
    return br;
}

bool kosaradzu(Graf& g, int u){
    
    dfs(g, u);
    
    if(brojNeposecenih(g) > 0)
        return false;
    
    Graf f = obrnute_grane(g);
    
    dfs(f, u);
    
    if(brojNeposecenih(f) > 0)
        return false;
    
    return true;
}

bool ojlerov(Graf& g, int u){
    
    if(kosaradzu(g, u) == false)
        return false;
    
    for(int i = 0; i < g.V; i++)
        if(g.ulazni_stepen[i] != g.lista_susedstva[i].size())
            return false;
        
    return true;
}

int main(){
    
    Graf g;
    inicijalizuj(g, MAX);

    vector<string> reci = {
        "programmer", "ridiculous", "speed", "deep"
    };
    
    dodaj_reci(g, reci);
    
    cout << (ojlerov(g, reci[0][0]-'a') ? "moze" : "ne moze") << endl;
    
    return 0;
}
