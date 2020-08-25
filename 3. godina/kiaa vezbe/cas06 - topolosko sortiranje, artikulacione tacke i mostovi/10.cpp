/* Konstruisati algoritam koji u neusmerenom grafu G 
 * pronalazi sve cikluse duzine n. */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Graf {
    int V;
    vector<vector<int>> lista_susedstva;
    vector<bool> posecen;
    int brCiklusa;
};

void inicijalizuj(Graf& g, int V){
    g.V = V;
    g.lista_susedstva.resize(V);
    g.posecen.resize(V, false);
    g.brCiklusa = 0;
}

void dodaj_granu(Graf& g, int u, int v){
    g.lista_susedstva[u].push_back(v);
    g.lista_susedstva[v].push_back(u);
}

void dfs(Graf& g, int u, int start, int n){
    
    g.posecen[u] = true;
    
    if(n == 0){
        if(find(g.lista_susedstva[u].begin(), g.lista_susedstva[u].end(), start) != g.lista_susedstva[u].end())
            g.brCiklusa++;
        
        g.posecen[u] = false;
        return;
    }
    
    auto pocetak = g.lista_susedstva[u].begin();
    auto kraj = g.lista_susedstva[u].end();
    
    while(pocetak != kraj){
        if(!g.posecen[*pocetak])
            dfs(g, *pocetak, start, n-1);
        pocetak++;
    }
    
    g.posecen[u] = false;
}

int brojCiklusa(Graf& g, int n){
    
    for(int i = 0; i < g.V-(n-1); i++){
        dfs(g, i, i, n-1);
        g.posecen[i] = true;
    }
    
    return g.brCiklusa / 2;
}

int main(){
    
    Graf g;
    inicijalizuj(g, 7);
    
    dodaj_granu(g, 0, 1);
    dodaj_granu(g, 1, 2);
    dodaj_granu(g, 2, 3);
    dodaj_granu(g, 3, 0);
    dodaj_granu(g, 3, 4);
    dodaj_granu(g, 4, 6);
    dodaj_granu(g, 6, 5);
    dodaj_granu(g, 5, 3);   
    
    int n;
    cin >> n;
    
    cout << brojCiklusa(g, n) << endl;
    
    return 0;
}
