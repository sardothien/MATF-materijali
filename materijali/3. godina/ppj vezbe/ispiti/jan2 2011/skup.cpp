#include "skup.hpp"

Skup::Skup(){}

Skup::Skup(int pocetak, int kraj){
    for(int i = pocetak; i <= kraj; i++)
        _elementi.insert(i);
}

void Skup::dodaj(int x){
    _elementi.insert(x);
}

void Skup::obrisi(int x){
    if(nadji(x))
        _elementi.erase(x);
}

void Skup::stampaj() const {
    cout << "{";
    for(set<int>::iterator i = _elementi.begin(); i != _elementi.cend(); i++){
        if(i != _elementi.cbegin())
            cout << ", ";
        cout << *i;
    }
    cout << "}" << endl;
}

bool Skup::nadji(int x) const {
    return _elementi.find(x) != _elementi.end();
}

bool Skup::podskup(const Skup* veci) const {
    for(auto i = _elementi.cbegin(); i != _elementi.cend(); i++)
        if(!veci->nadji(*i))
            return false;
    return true;
}

int Skup::brojElemenata() const {
    return _elementi.size();
}

Skup* unija(const Skup* s1, const Skup* s2){
    Skup* rez = new Skup(*s1);
    
    for(auto i = s2->_elementi.cbegin(); i != s2->_elementi.cend(); i++)
        rez->dodaj(*i);
    
    return rez;
}

Skup* presek(const Skup* s1, const Skup* s2){
    Skup* rez = new Skup(*s1);
    
    for(auto i = s1->_elementi.cbegin(); i != s1->_elementi.cend(); ){
        if(!s2->nadji(*i))
            rez->obrisi(*i);
        ++i;
    }
    
    return rez;
}

Skup* razlika(const Skup* s1, const Skup* s2){
    Skup* rez = new Skup(*s1);
    
    for(auto i = s1->_elementi.cbegin(); i != s1->_elementi.cend(); i++){
        if(s2->nadji(*i))
            rez->obrisi(*i);
    }
    
    return rez;    
}
