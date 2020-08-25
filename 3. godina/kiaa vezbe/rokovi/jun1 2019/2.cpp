/* Вероватно да ово нисте знали, али у нашој галаксији има N
 * настањених планета. Између неких планета постоје устаљени
 * међупланетарни летови. Са сваке планете могуће је доћи до
 * било које друге и ако постоји лет од планете A до планете
 * B, постоји и повратни лет и он кошта C динара. Велики
 * трошкови одржавања међупланетарних линија довели су до
 * тога да је галактички одбор за транспорт одлучио да укине
 * све летове који неће реметити повезаност свих планета, али
 * тако да се трошкови одржавања свих преосталих летова сведу
 * на минимум. У првој линији стандардног улаза налазе се два
 * цела броја N и М. У следећих M редова налазе се по три броја
 * А, B и C одвојени размаком. А и B су бројеви планета које су
 * повезане, а C је цена одржавања међупланетарне линије између
 * планета А и B. У прву линију стандардног излаза испишиte један
 * цео број који представља цену одржавања преосталих летова након
 * укидања оних неповољних. Временска сложеност алгоритма: O(MlogM).
 * Меморијска сложеност: O(MlogN). */

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

struct Graf {
    int V;
    vector<vector<pair<int, int>>> lista_suseda;
    vector<int> roditelj;
    vector<int> rastojanja;
    vector<bool> uDrvetu;
};

void inicijalizuj(Graf& g, int V){
    g.V = V;
    g.lista_suseda.resize(V);
    g.uDrvetu.resize(V, false);
    g.roditelj.resize(V, -1);
    g.rastojanja.resize(V, INT_MAX);
}

void dodaj_granu(Graf& g, int u, int v, int tezina){
    g.lista_suseda[u].push_back({v, tezina});
    g.lista_suseda[v].push_back({u, tezina});
}

int minGrana(Graf& g){

    int min = INT_MAX;
    int min_ind;

    for(int i = 0; i < g.V; i++)
        if(!g.uDrvetu[i] && g.rastojanja[i] < min){
            min = g.rastojanja[i];
            min_ind = i;
        }

    return min_ind;
}

void prim(Graf& g, int u){

    g.rastojanja[u] = 0;

    int cvor;

    for(int i = 0; i < g.V; i++){
        cvor = minGrana(g);
        g.uDrvetu[cvor] = true;

        for(int v = 0; v < g.V; v++){
            if(g.lista_suseda[cvor][v].second && !g.uDrvetu[v] && g.lista_suseda[cvor][v].second < g.rastojanja[v]){
                g.roditelj[v] = cvor;
                g.rastojanja[v] = g.lista_suseda[cvor][v].second;
            }
        }
    }

    int cena = 0;
    for(int i = 0; i < g.V; i++)
        if(i != u)
            cena += g.rastojanja[i];

    cout << cena << endl;
}

int main(){

    int n, m;
    cin >> n >> m;

    Graf g;
    inicijalizuj(g, n);

    int a, b, c;

    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        dodaj_granu(g, a-1, b-1, c);
    }

    prim(g, 3);

    return 0;
}
