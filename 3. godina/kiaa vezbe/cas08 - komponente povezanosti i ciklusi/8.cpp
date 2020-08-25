/* Асистент конструкције и анализе алгоритама жели да да студентима 
 * задатке за испит. То ће урадити кроз једну игру. Правила игре су следећа:
 * 1. Асистент каже задатке једном студенту.
 * 2. Асистент нумерише студенте и себе редним ројевима и одређује ко са ким 
 *    сме међусобно да комуницира.
 * 3. Сви студенти који смеју да комуницирају морају да искомуницирају тачно 
 *    једном.
 * 4. На крају последњи студент мора да понови асистенту задатке.
 * 5. Уколико студенит упеју да искомуницирају и кажу асистенту задатке ти 
 *    задаци остају за испит иначе се смишљају нови дупло тежи задаци.
 * 6. Студенти се договарају и кажу асистенту да ли прихватају игру или не.
 * Sa standardnog ulaza se unosi broj N koji predstavlja broj studenata (asistent
 * je uračunat). Nakon toga se u narednih N linija unose po 2 broja koja govore o 
 * tome ko sa kim sme da komunicira. Na standardni izlaz ispisati “DA” ukoliko
 * studenti treba da prihvate, a “NE” u suprotnom. */

// treba dodati i proveru da li je graf povezan (dfs)

#include<iostream>
#include<vector>
using namespace std;

struct Graf {
    int V;
    vector<vector<int>> lista_susedstva;
    vector<int> stepen;
};

void inicijalizuj(Graf& g, int V){
    g.V = V;
    g.lista_susedstva.resize(V);
    g.stepen.resize(V, 0);
}

void dodaj_granu(Graf& g, int u, int v){
    g.lista_susedstva[u].push_back(v);
    g.lista_susedstva[v].push_back(u);
    g.stepen[v]++;
    g.stepen[u]++;
}

int brojNeparnih(Graf& g){
    int br = 0;
    
    for(int i = 0; i < g.V; i++)
        if(g.stepen[i] % 2 == 1)
            br++;
        
    return br;
}

bool ojlerovCiklus(Graf& g){
    
    int br = brojNeparnih(g);
    
    if(br == 0)
        return true;
    else
        return false;
}

int main(){
    
    int n, m;
    cin >> n >> m;
    
    Graf g;
    inicijalizuj(g, n);
    
    int u, v;
    
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        dodaj_granu(g, u, v);
    }
    
    if(ojlerovCiklus(g))
        cout << "DA" << endl;
    else
        cout << "NE" << endl;
    
    return 0;
}
