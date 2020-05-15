#ifndef MATRICE_HPP
#define MATRICE_HPP

#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

class Matrica {
public:
    Matrica() {};
    Matrica(int m, int n);
    Matrica(Matrica& m);
    
    vector<double> operator [](int i) const;
    vector<double> operator [](int i);
    
    Matrica* operator +(Matrica& m) const;
    Matrica* operator -(Matrica& m) const;    
    Matrica* operator *(Matrica& m) const;
    Matrica* operator -() const;
    
    Matrica* transpose() const;
    Matrica* scalarMul(Matrica& m) const;
    
    void show(ostream& s) const;
    void addRow(vector<double>& v);
    
private:
    vector<vector<double>> _m;
};

ostream& operator <<(ostream& s, const Matrica& m);

#endif
