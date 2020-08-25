/* Neka je dat skup reci S. Koristeci prefiksna stabla,
 * sortirati reci leksikografski u rastucem poretku. */

#include<iostream>
#include<vector>
#include<map>
using namespace std;

struct cvor {
    string rec = "";
    map<char, cvor*> grane;
};

void umetni(cvor* drvo, const string& w, int i){
    if(i == w.size()){
        drvo->rec = w;
        return;
    }

    auto it = drvo->grane.find(w[i]);
    if(it == drvo->grane.end())
        drvo->grane[w[i]] = new cvor();

    umetni(drvo->grane[w[i]], w, i+1);
}

void leksikografski(cvor* drvo){
    if(drvo->rec != "")
        cout << drvo->rec << endl;

    auto pocetak = drvo->grane.begin();
    auto kraj = drvo->grane.end();

    while(pocetak != kraj){
        leksikografski(pocetak->second); // cvor*
        pocetak++;
    }
}

int main(){

    vector<string> reci = {
        "ana", "anastasija", "anastasijin",
        "anamarija", "anamarijin"
    };

    cvor* drvo = new cvor();

    for(auto s : reci)
        umetni(drvo, s, 0);

    leksikografski(drvo);

    return 0;
}
