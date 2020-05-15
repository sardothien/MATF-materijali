#include<iostream>
#include<cstdlib>
#include<vector>
#include"matrice.hpp"
using namespace std;

Matrica::Matrica() {}

Matrica::Matrica(vector<vector<int>> m) {
    m_matr = m;
}
    
vector<vector<int>> Matrica::getMatrica(){
    return this->m_matr;
}

Matrica* Matrica::dodaj_vrstu(vector<int> vrsta){
    this->m_matr.push_back(vrsta);
    return this;
}

void Matrica::display(){
    if(m_matr.size() == 1){
        unsigned i;
        cout << "[";
        for(i = 0; i < m_matr[0].size()-1; i++)
            cout << m_matr[0][i] << ", ";
        cout << m_matr[0][i] << "]" << endl;
    }
    else{
        unsigned i, j;
        cout << "[";
        for(i = 0; i < m_matr.size()-1; i++){
            cout << "[";
            for(j = 0; j < m_matr[i].size()-1; j++)
                cout << m_matr[i][j] << ", ";
            cout << m_matr[i][j] << "], ";
        }
        cout << "[";
        for(j = 0; j < m_matr[i].size()-1; j++)
            cout << m_matr[i][j] << ", ";
        cout << m_matr[i][j] << "]]" << endl;
    }
}
    
void Matrica::size(){
    cout << m_matr.size() << "x" << m_matr[0].size() << endl;
}

Matrica* Matrica::pomnozi(Matrica m1, Matrica m2){
    vector<vector<int>> mat1, mat2, nova;
    mat1 = m1.getMatrica();
    mat2 = m2.getMatrica();
    
    for(unsigned i = 0; i < mat1.size(); i++){
        vector<int> vrsta;
        for(unsigned j = 0; j < mat1[i].size(); j++)
            vrsta.push_back(mat1[i][j] * mat2[i][j]);
        nova.push_back(vrsta);
    }
    
    return new Matrica(nova);
}

Matrica* Matrica::saberi(Matrica m1, Matrica m2){
    vector<vector<int>> mat1, mat2, nova;
    mat1 = m1.getMatrica();
    mat2 = m2.getMatrica();
    
    for(unsigned i = 0; i < mat1.size(); i++){
        vector<int> vrsta;
        for(unsigned j = 0; j < mat1[i].size(); j++)
            vrsta.push_back(mat1[i][j] + mat2[i][j]);
        nova.push_back(vrsta);
    }
    
    return new Matrica(nova);
}

Matrica* Matrica::mnozi(Matrica m1){
    vector<vector<int>> mat1, mat2, nova;
    mat1 = this->getMatrica();
    mat2 = m1.getMatrica();
    
    unsigned n = mat2.size();
    unsigned m = mat2[0].size();
    
    for(unsigned l = 0; l < mat1.size(); l++){
        vector<int> pom;
        for(unsigned i = 0; i < m; i++){
            int prom = 0;
            for(unsigned j = 0; j < n; j++)
                prom += mat1[l][j] * mat2[j][i];
            pom.push_back(prom);
        }
        nova.push_back(pom);
    }
    
    return new Matrica(nova);
}

Matrica* Matrica::transponuj(){
    vector<vector<int>> nova, pom;
    pom = this->getMatrica();
    
    unsigned n = pom.size();
    unsigned m = pom[0].size();
    
    for(unsigned i = 0; i < m; i++){
        vector<int> vrsta;
        for(unsigned j = 0; j < n; j++)
            vrsta.push_back(pom[j][i]);
        nova.push_back(vrsta);
    }
    
    return new Matrica(nova);
}
