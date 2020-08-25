/* Gradovi su povezani putevima i za svaki put je poznata duzina izmedju 
 * dva grada. Napisi program koji odredjuje najkrace puteve izmedju pocetnog 
 * grada (cvor 0) i svih ostalih gradova. Pretpostavka je da je graf aciklicki. */

#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;

struct Graf {
    int V;
    vector<vector<pair<int,int>>> lista_susedstva;
    vector<int> ulazniStepen;
    vector<int> najkraciPut;
    vector<int> roditelj;
};

void inicijalizuj(Graf& g, int V){
    g.V = V;
    g.lista_susedstva.resize(V);
    g.ulazniStepen.resize(V, 0);
    g.najkraciPut.resize(V, INT_MAX);
    g.roditelj.resize(V, -1);
}

void dodaj_granu(Graf& g, int u, int v, int tezina){
    g.lista_susedstva[u].push_back(make_pair(v, tezina));
    g.ulazniStepen[v]++;
}

void odstampajPut(Graf& g, int cvor){
    if(g.roditelj[cvor] == -1)
        return;
    
    odstampajPut(g, g.roditelj[cvor]);
    cout << ", " << cvor;
}

void odstampajNajkraciPut(Graf& g, int cvor){
    cout << "Najkraci put do cvora " << cvor << " je: 0";
    odstampajPut(g, cvor);
    cout << " i duzine je " << g.najkraciPut[cvor] << endl;
}

void najkraciPutevi(Graf& g){
    
    g.najkraciPut[0] = 0;
    
    queue<int> cvorovi;
    
    for(int i = 0; i < g.V; i++)
        if(g.ulazniStepen[i] == 0)
            cvorovi.push(i);
        
    int pom;
        
    while(!cvorovi.empty()){
        pom = cvorovi.front();
        cvorovi.pop();
        
        odstampajNajkraciPut(g, pom);
        
        for(int x = 0; x < g.lista_susedstva[pom].size(); x++){
            int sused = g.lista_susedstva[pom][x].first;
            int grana = g.lista_susedstva[pom][x].second;
            
            if(g.najkraciPut[pom] + grana < g.najkraciPut[sused]){
                g.najkraciPut[sused] = g.najkraciPut[pom] + grana;
                g.roditelj[sused] = pom;
            }
            
            g.ulazniStepen[sused]--;
            if(g.ulazniStepen[sused] == 0)
                cvorovi.push(sused);
        }        
    }
}

int main(){
    
    // broj gradova i broj puteva
    int n, m;
    cin >> n >> m;
    
    Graf g;
    inicijalizuj(g, n);
    
    int u, v, tezina;
    
    for(int i = 0; i < m; i++){
        cin >> u >> v >> tezina;
        dodaj_granu(g, u, v, tezina);
    }
    
    najkraciPutevi(g);
    
    return 0;
}
