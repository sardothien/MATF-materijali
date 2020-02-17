#ifndef _MATRICA_H
#define _MATRICA_H

#include<vector>
using namespace std;

class Matrica {
public:
    Matrica();
    Matrica(vector<vector<int>> m);
    
    vector<vector<int>> getMatrica();
    
    Matrica* dodaj_vrstu(vector<int> vrsta);    
    void display();
    void size();
    
    static Matrica* pomnozi(Matrica m1, Matrica m2);
    static Matrica* saberi(Matrica m1, Matrica m2);
    
    Matrica* mnozi(Matrica m1);
    Matrica* transponuj();
    
private:
    vector<vector<int>> m_matr;
};

#endif
