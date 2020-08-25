/* Za zadati povezani usmereni graf G odrediti klasifikaciju grana
 * u DFS stablu. DFS pretragu grafa pokrenuti iz cvora 0. */

#include<iostream>
#include<vector>
using namespace std;

struct Graf {
    int V;
    vector<vector<int>> lista_susedstva;
    vector<bool> posecen;
    vector<int> ulazna_numeracija;
    vector<int> izlazna_numeracija;
    vector<int> roditelji;
};

void inicijalizuj(Graf& g, int V){
    g.V = V;
    g.lista_susedstva.resize(V);
    g.posecen.resize(V, false);
    g.ulazna_numeracija.resize(V);
    g.izlazna_numeracija.resize(V);
    g.roditelji.resize(V, -1);
}

void dodaj_granu(Graf& g, int u, int v){
    g.lista_susedstva[u].push_back(v);
}

void dfs(Graf& g, int u, int& ulaz, int& izlaz){
    g.ulazna_numeracija[u] = ulaz;
    ulaz++;
    
    g.posecen[u] = true;
    
    auto pocetak = g.lista_susedstva[u].begin();
    auto kraj = g.lista_susedstva[u].end();
    
    while(pocetak != kraj){
        if(!g.posecen[*pocetak]){
            g.roditelji[*pocetak] = u;
            dfs(g, *pocetak, ulaz, izlaz);
        }
        pocetak++;
    }
    
    g.izlazna_numeracija[u] = izlaz;
    izlaz++;
}

void klasifikacija(Graf& g){
    int ulaz = 0;
    int izlaz = 0;
    
    dfs(g, 0, ulaz, izlaz);
    
    vector<pair<int, int>> grane_drveta;
    vector<pair<int, int>> direktne_grane;
    vector<pair<int, int>> povratne_grane;
    vector<pair<int, int>> poprecne_grane;
    
    for(int u = 0; u < g.V; u++){
        for(int v : g.lista_susedstva[u]){
            if(g.izlazna_numeracija[u] <= g.izlazna_numeracija[v])
                povratne_grane.push_back({u, v});
            else if(g.izlazna_numeracija[u] > g.izlazna_numeracija[v] && g.ulazna_numeracija[u] > g.ulazna_numeracija[v])
                poprecne_grane.push_back({u, v});
            else if(g.izlazna_numeracija[u] > g.izlazna_numeracija[v] && u == g.roditelji[v])
                grane_drveta.push_back({u, v});
            else
                direktne_grane.push_back({u, v});
        }
    }
    
    cout << "Grane stabla:" << endl;
    for(auto &p : grane_drveta)
        cout << p.first << " " << p.second << endl;
    
    cout << "Povratne grane:" << endl;
    for(auto &p : povratne_grane)
        cout << p.first << " " << p.second << endl;
    
    cout << "Direktne grane:" << endl;
    for(auto &p : direktne_grane)
        cout << p.first << " " << p.second << endl;
    
    cout << "Poprecne grane:" << endl;
    for(auto &p : poprecne_grane)
        cout << p.first << " " << p.second << endl;
}

int main(){
    
    // broj cvorova i broj grana
    int n, m;
    cin >> n >> m;
    
    Graf g;
    inicijalizuj(g, n);
    
    int u, v;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        dodaj_granu(g, u, v);
    }
    
    klasifikacija(g);
    
    return 0;
}
