/* Niz telefonskih brojeva je korektan ako nijedan broj nije
 * prefiks drugog. Napisati program koji odredjuje da li je
 * niz unetih brojeva korektan. Sa standardnog ulaza se unosi
 * broj *n* koji predstavlja broj brojeva. Nakon toga se unosi
 * *n* brojeva telefona. Na standardni izlaz ispisati *DA*
 * ukoliko je niz brojeva korektan a *NE* u suprotnom. */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct cvor {
    unordered_map<char, cvor*> grane;
};

cvor* napravi(const string& w, int i){
    if(i == w.size())
        return nullptr;

    cvor* pom = new cvor();
    pom->grane[w[i]] = napravi(w, i+1);

    return pom;
}

bool umetni(cvor* drvo, const string& w, int i){
    if(i == w.size() || drvo == nullptr)
        return false;

    auto it = drvo->grane.find(w[i]);
    if(it == drvo->grane.end()){
        drvo->grane[w[i]] = napravi(w, i+1);
        return true;
    }
    else
        return umetni(drvo->grane[w[i]], w, i+1);
}

int main(){

    int n;
    cin >> n;

    cvor* drvo;

    bool ok = true;

    string broj;
    cin >> broj;

    drvo = napravi(broj, 0);

    for(int i = 0; i < n-1; i++){
        cin >> broj;
        if(ok && !umetni(drvo, broj, 0))
            ok = false;
    }

    if(ok)
        cout << "DA" << endl;
    else
        cout << "NE" << endl;

    return 0;
}
