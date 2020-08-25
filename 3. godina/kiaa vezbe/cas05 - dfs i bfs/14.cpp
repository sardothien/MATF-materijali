/* Za svaki ruter u racunarskoj mrezi je poznat spisak rutera 
 * sa kojima je povezan. Napisi program koji proverava da li je 
 * moguce poslati poruku od jednog do drugog zadatog rutera. */

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

bool dfs(Graf& g, int u, int v){
    if(u == v)
        return true;
    
    if(g.posecen[u])
        return false;
    
    g.posecen[u] = true;
    
    auto pocetak = g.lista_susedstva[u].begin();
    auto kraj = g.lista_susedstva[u].end();
    
    while(pocetak != kraj){
        if(dfs(g, *pocetak, v))
            return true;
        pocetak++;
    }
    
    return false;
}

int main(){
    
    // broj rutera
    int n;
    cin >> n;
    
    // broj veza izmedju rutera
    int m;
    cin >> m;
    
    Graf g;
    inicijalizuj(g, n);
    
    int u, v;    
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        // kako bi krenuli od 0
        u--;
        v--;
        dodaj_granu(g, u, v);
    }
    
    // broj parova rutera
    int p;
    cin >> p;
    
    int start, cilj;
    for(int i = 0; i < p; i++){
        fill(g.posecen.begin(), g.posecen.end(), false);
        cin >> start >> cilj;
        start--;
        cilj--;
        if(dfs(g, start, cilj))
            cout << "da" << endl;
        else
            cout << "ne" << endl;
    }
    
    return 0;
}
