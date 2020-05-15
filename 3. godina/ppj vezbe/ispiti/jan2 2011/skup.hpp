#ifndef _SKUP_HPP_
#define _SKUP_HPP_

#include <set>
#include<cstdlib>
#include <iostream>
using namespace std;

class Skup {
public:
    Skup();
    Skup(int pocetak, int kraj);
    
    void dodaj(int x);
    void obrisi(int x);
    
    void stampaj() const;
    bool nadji(int x) const;
    bool podskup(const Skup* veci) const;
    int brojElemenata() const;
    
private:
    set<int> _elementi;
    friend Skup* unija(const Skup* s1, const Skup* s2);
    friend Skup* presek(const Skup* s1, const Skup* s2);
    friend Skup* razlika(const Skup* s1, const Skup* s2);
};

#endif
