/* Implementirati autocomplete funkcionalnost. Sa standardnog
 * ulaza se prvo unosi broj N. Nakon toga se u narednih N<=500000
 * linija unose reci. Nakon toga se unosi jedna rec S. Ispisati
 * sve reci iz skupa unetih reci koje korisnik moze odabrati
 * nakon unosa reci S. Reci treba da budu ispisane u leksikografski
 * rastucem poretku. Obavezno je korististi odgovarajucu strukturu
 * podataka. */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct cvor {
    string rec = "";
    bool krajKljuca = false;
    unordered_map<char, cvor*> grane;
};

void umetni(cvor* drvo, const string& w, int i){
    if(i == w.size()){
        drvo->rec = w;
        drvo->krajKljuca = true;
        return;
    }

    auto it = drvo->grane.find(w[i]);
    if(it == drvo->grane.end())
        drvo->grane[w[i]] = new cvor();

    umetni(drvo->grane[w[i]], w, i+1);
}

cvor* autocomplete(cvor* drvo, const string& w, int i){
    if(i == w.size()){
        return drvo;
    }

    auto it = drvo->grane.find(w[i]);
    if(it == drvo->grane.end())
        return nullptr;

    return autocomplete(drvo->grane[w[i]], w, i+1);
}

void ispisi(cvor* drvo){
    if(drvo == nullptr)
        return;

    if(drvo->krajKljuca == true)
        cout << drvo->rec << endl;

    auto pocetak = drvo->grane.begin();
    auto kraj = drvo->grane.end();

    while(pocetak != kraj){
        ispisi(pocetak->second);
        pocetak++;
    }
}

int main(){

    int n;
    cin >> n;

    vector<string> reci(n);

    cvor* drvo = new cvor();

    for(int i = 0; i < n; i++){
        cin >> reci[i];
        umetni(drvo, reci[i], 0);
    }

    string prefiks;
    cin >> prefiks;

    cvor* tmp = autocomplete(drvo, prefiks, 0);

    ispisi(tmp);

    return 0;
}
