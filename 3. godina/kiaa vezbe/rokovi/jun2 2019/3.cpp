/* Да бу кустос у музеју могао да почне да ради, мора да обезбеди
 * сертификате шефова Департмана у музеју да је пратио њихова
 * стручна предавања. Али, неки шефови издају сертификате само ако
 * је кустос прибавио сертификат од шефа чије предавање је предуслов
 * за разумевање одговарајућег историјског периода (нпр. сертификат
 * Департмана за средњи век се не може добити ако се претходно не
 * донесе сертификат Департмана за праисторију). У првој линији
 * стандардног улаза дат је број шефова N (1<=N<=100) од којих кустос
 * тражи сертификате. У наредних N редова дате су потребне информације
 * тако да први број K у линији I+1 представља број шефова чији
 * серификати су предуслов за сертификат шефа I. Наредних K бројева
 * означавају те шефове. Ако се не могу прикупити сертификати свих
 * шефова, онда на стандардни излаз треба исписати поруку NE. Ако се
 * могу прикупити сви сертификати, онда исписати поруку DA у 1. ред
 * стандардног излаза, а у наредних N линија исписати редослед прикупљања
 * сертификата. */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Graf {
    int V;
    vector<vector<int>> lista_suseda;
    vector<int> ulazni_stepen;
};

void inicijalizacija(Graf& g, int V){
    g.V = V;
    g.lista_suseda.resize(V);
    g.ulazni_stepen.resize(V, 0);
}

void dodaj_granu(Graf& g, int u, int v){
    g.lista_suseda[u].push_back(v);
    g.ulazni_stepen[v]++;
}

void topolosko(Graf& g){
    queue<int> cvorovi;

    for(int i = 0; i < g.V; i++)
        if(g.ulazni_stepen[i] == 0)
            cvorovi.push(i);

    int pom;
    vector<int> rezultat;

    while(!cvorovi.empty()){
        pom = cvorovi.front();
        cvorovi.pop();

        rezultat.push_back(pom);

        for(int sused : g.lista_suseda[pom]){
            g.ulazni_stepen[sused]--;
            if(g.ulazni_stepen[sused] == 0)
                cvorovi.push(sused);
        }
    }

    if(rezultat.size() == g.V){
        cout << "DA" << endl;

        for(int i = 0; i < g.V; i++)
            cout << rezultat[i]+1 << endl;
    }
    else{
        cout << "NE" << endl;
    }
}

int main(){

    int n;
    cin >> n;

    Graf g;
    inicijalizacija(g, n);

    int k, x;

    for(int i = 0; i < n; i++){
        cin >> k;
        for(int j = 0; j < k; j++){
            cin >> x;
            dodaj_granu(g, x-1, i);
        }
    }

    topolosko(g);

    return 0;
}
