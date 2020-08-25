/* Modifikovati algoritam za topolosko sortiranje 
 * grafa tako da ukoliko nema ciklusa ispisuje
 * topolosko sortiranje, inace ispisuje neki ciklus. */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Graf {
    int V;
    vector<vector<int>> lista_susedstva;
    vector<bool> posecen;
    vector<int> ulazni_stepen;
    bool nadjen;
};

void inicijalizuj(Graf& g, int V){
    g.V = V;
    g.lista_susedstva.resize(V);
    g.posecen.resize(V, false);
    g.ulazni_stepen.resize(V, 0);
    g.nadjen = false;
}

void dodaj_granu(Graf& g, int u, int v){
    g.lista_susedstva[u].push_back(v);
    g.ulazni_stepen[v]++;
}

void topolosko_sortiranje(Graf& g, vector<int>& rezultat){
    
    queue<int> cvorovi;
    
    for(int i = 0; i < g.V; i++)
        if(g.ulazni_stepen[i] == 0)
            cvorovi.push(i);
        
    int pom;
    
    while(!cvorovi.empty()){
        pom = cvorovi.front();
        cvorovi.pop();
        
        rezultat.push_back(pom);
        
        for(int cvor : g.lista_susedstva[pom]){
            g.ulazni_stepen[cvor]--;
            if(g.ulazni_stepen[cvor] == 0)
                cvorovi.push(cvor);
        }
    }
}

void dfs(Graf& g, int u, vector<int>& rezultat, int start){
    
    if(g.posecen[u] && u == start){
        rezultat.push_back(u);
        g.nadjen = true;
        return;
    }
    
    g.posecen[u] = true;
    rezultat.push_back(u);
    
    auto pocetak = g.lista_susedstva[u].begin();
    auto kraj = g.lista_susedstva[u].end();
    
    while(pocetak != kraj){
        if(!g.nadjen)
            dfs(g, *pocetak, rezultat, start);
        pocetak++;
    }
}

void pronadji(Graf& g){
    
    vector<int> rezultat;
    topolosko_sortiranje(g, rezultat);
    
    bool topolosko = true;
    
    for(int i = 0; i < g.V; i++)
        if(g.ulazni_stepen[i]) // != 0
            topolosko = false;
        
    if(topolosko){
        cout << "Topolosko sortiranje:" << endl;
        for(int r : rezultat)
            cout << r << " ";
        cout << endl;
        
        return;
    }
    else{
        cout << "Ciklus:" << endl;
        
        rezultat.clear();
        
        for(int i = 0; i < g.V; i++)
            if(g.ulazni_stepen[i] != 0){
                dfs(g, i, rezultat, i);
                
                int j;
                for(j = 0; j < rezultat.size()-1; j++)
                    cout << rezultat[j] << " -> ";
                cout << rezultat[j] << endl;
                
                return;
            }
    }
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
    
    pronadji(g);
    
    return 0;
}
