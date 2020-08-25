/* Da bi se izgradio automobil, potrebno je uraditi niz poslova. Neki 
 * poslovi zavise od drugih. Napisi program koji odredjuje moguci raspored 
 * izvrsavanja ovih poslova u kome su sva ogranicenja zadovoljena. */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Graf {
    int V;
    vector<vector<int>> lista_susedstva;
    vector<int> ulazni_stepen;
};

void inicijalizuj(Graf& g, int V){
    g.V = V;
    g.lista_susedstva.resize(V);
    g.ulazni_stepen.resize(V, 0);
}

void dodaj_granu(Graf& g, int u, int v){
    g.lista_susedstva[u].push_back(v);
    g.ulazni_stepen[v]++;
}

void topolosko_sortiranje(Graf& g){
    
    queue<int> cvorovi;
    
    for(int i = 0; i < g.V; i++)
        if(g.ulazni_stepen[i] == 0)
            cvorovi.push(i);
        
    int pom;
    
    while(!cvorovi.empty()){
        pom = cvorovi.front();
        cvorovi.pop();
        
        cout << pom << endl;
        
        for(int cvor : g.lista_susedstva[pom]){
            g.ulazni_stepen[cvor]--;
            if(g.ulazni_stepen[cvor] == 0)
                cvorovi.push(cvor);
        }
    }
}

int main(){
    
    int n, m;
    cin >> n >> m;
    
    Graf g;
    inicijalizuj(g, m);
    
    int u, v;
    
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        dodaj_granu(g, v, u);
    }
    
    topolosko_sortiranje(g);    
    
    return 0;
}
