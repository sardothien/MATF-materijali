/* Neka je dat aciklicki graf G koji ima i usmerene 
 * i neusmerene grane. Konstruisati algoritam koji 
 * usmerava neusmerene grane tako da graf ostane
 * aciklicki. */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Graf {
    int V;
    vector<vector<int>> lista_susedstva;
    vector<int> ulazni_stepen;
    vector<pair<int, int>> neusmerene_grane;
    vector<pair<int, int>> dodate_grane;
    vector<pair<int, int>> sve_grane;
    vector<int> pozicija_u_sortiranju;
};

void inicijalizuj(Graf& g, int V){
    g.V = V;
    g.lista_susedstva.resize(V);
    g.ulazni_stepen.resize(V, 0);
    g.pozicija_u_sortiranju.resize(V, -1);
}

void dodaj_usmerenu_granu(Graf& g, int u, int v){
    g.lista_susedstva[u].push_back(v);
    g.ulazni_stepen[v]++;
    g.sve_grane.push_back({u, v});
}

void dodaj_neusmerenu_granu(Graf& g, int u, int v){
    g.neusmerene_grane.push_back({u, v});
}

void topolosko_sortiranje(Graf& g){
    
    queue<int> cvorovi;
    
    for(int i = 0; i < g.V; i++)
        if(g.ulazni_stepen[i] == 0)
            cvorovi.push(i);
        
    int pom;
    int poz = 0;
    
    while(!cvorovi.empty()){
        pom = cvorovi.front();
        cvorovi.pop();
        
        g.pozicija_u_sortiranju[pom] = poz;
        poz++;
        
        for(int cvor : g.lista_susedstva[pom]){
            g.ulazni_stepen[cvor]--;
            if(g.ulazni_stepen[cvor] == 0)
                cvorovi.push(cvor);
        }
    }
}

void dodeli_usmerenja(Graf& g){
    
    topolosko_sortiranje(g);
    
    for(auto p : g.neusmerene_grane){
        if(g.pozicija_u_sortiranju[p.first] < g.pozicija_u_sortiranju[p.second]){
            dodaj_usmerenu_granu(g, p.first, p.second);
            g.dodate_grane.push_back({p.first, p.second});
        }
        else{
            dodaj_usmerenu_granu(g, p.second, p.first);
            g.dodate_grane.push_back({p.second, p.first});
        }
    }
    
    cout << "Sve grane:" << endl; 
    for(auto p : g.sve_grane)
        cout << p.first << " -> " << p.second << endl;

    cout << "Dodate grane: " << endl;
    for(auto p : g.dodate_grane)
        cout << p.first << " -> " << p.second << endl;
}

int main(){
    
    Graf g;
    inicijalizuj(g, 6);
    
    dodaj_usmerenu_granu(g, 0, 1);
    dodaj_usmerenu_granu(g, 0, 5);
    dodaj_usmerenu_granu(g, 1, 2);
    dodaj_usmerenu_granu(g, 1, 3);
    dodaj_usmerenu_granu(g, 1, 4);
    dodaj_usmerenu_granu(g, 2, 3);
    dodaj_usmerenu_granu(g, 2, 4);
    dodaj_usmerenu_granu(g, 3, 4);
    dodaj_usmerenu_granu(g, 5, 1);
    dodaj_usmerenu_granu(g, 5, 2);

    dodaj_neusmerenu_granu(g, 0, 2);
    dodaj_neusmerenu_granu(g, 0, 3);
    dodaj_neusmerenu_granu(g, 4, 5);
    
    dodeli_usmerenja(g);
    
    return 0;
}
