#include"04_matrice.hpp"
using namespace std;

Matrica::Matrica(int m, int n){
    _m.resize(m);
    for(int i = 0; i < m; i++)
        _m[i].resize(n);
}

Matrica::Matrica(Matrica& m){
    _m = m._m;
}

vector<double> Matrica::operator [](int i) const {
    return _m[i];
}

vector<double> Matrica::operator [](int i) {
    return _m[i];
}

Matrica* Matrica::operator +(Matrica& m) const {
    if(_m.size() != m._m.size() || _m[0].size() != m._m[0].size())
        return NULL;
    
    Matrica* mat = new Matrica(_m.size(), _m[0].size());
    
    for(int i = 0; i < _m.size(); i++)
        for(int j = 0; j < _m[0].size(); j++)
            (*mat)[i][j] = _m[i][j] + m._m[i][j];
        
    return mat;
}

Matrica* Matrica::operator -(Matrica& m) const {
    if(_m.size() != m._m.size() || _m[0].size() != m._m[0].size())
        return NULL;
    
    Matrica* mat = new Matrica(_m.size(), _m[0].size());
    
    for(int i = 0; i < _m.size(); i++)
        for(int j = 0; j < _m[0].size(); j++)
            (*mat)[i][j] = _m[i][j] - m._m[i][j];
        
    return mat;
}

Matrica* Matrica::operator *(Matrica& m) const {
    if(_m.size() != m._m.size() || _m[0].size() != m._m[0].size())
        return NULL;
    
    Matrica* mat = new Matrica(_m.size(), _m[0].size());
    
    for(int i = 0; i < _m.size(); i++)
        for(int j = 0; j < _m[0].size(); j++){
            (*mat)[i][j] = 0;
            for(int k = 0; k < _m[0].size(); k++)
                (*mat)[i][j] += _m[i][k] * m._m[k][j];
        }
    
    return mat;
}

Matrica* Matrica::operator -() const {
    
    Matrica* mat = new Matrica(_m.size(), _m[0].size());
    
    for(int i = 0; i < _m.size(); i++)
        for(int j = 0; j < _m[0].size(); j++)
            (*mat)[i][j] = -_m[i][j];
        
    return mat;
}

Matrica* Matrica::transpose() const {
    Matrica* mat = new Matrica(_m[0].size(), _m.size());
    
    for(int i = 0; i < _m.size(); i++)
        for(int j = 0; j < _m[0].size(); j++)
            (*mat)[j][i] = _m[i][j];
        
    return mat;
}

Matrica* Matrica::scalarMul(Matrica& m) const {
    if(_m.size() != m._m.size() || _m[0].size() != m._m[0].size())
        return NULL;
    
    Matrica* mat = new Matrica(_m.size(), _m[0].size());
    
    for(int i = 0; i < _m.size(); i++)
        for(int j = 0; j < _m[0].size(); j++)
            (*mat)[i][j] = _m[i][j] * m._m[i][j];
    
    return mat;
}

void Matrica::show(ostream& s) const {
    for(int i = 0; i < _m.size(); i++){
        for(int j = 0; j < _m[0].size(); j++)
            s << _m[i][j] << " ";
        s << endl;
    }
}

void Matrica::addRow(vector<double>& v){
    _m.push_back(v);
}

ostream& operator <<(ostream& s, const Matrica& m){
    m.show(s);
    return s;
}
