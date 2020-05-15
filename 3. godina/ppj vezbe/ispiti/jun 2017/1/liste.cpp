#include<iostream>
#include<cstdlib>
#include<vector>
#include"liste.hpp"
using namespace std;

Lista::Lista(){}

Lista::Lista(vector<int>& v) : m_lista(v) { }
    
void Lista::printList(){
    cout << "[";
    for(unsigned i = 0; i < m_lista.size(); i++){
        if(i != m_lista.size() - 1)
            cout << m_lista[i] << ", ";
        else
            cout << m_lista[i];
    }
    cout << "]" << endl; 
}

Lista* Lista::concat(Lista& l){
    vector<int> rez(m_lista.size() + l.m_lista.size(), 0);
    
    unsigned i = 0;
    for(i = 0; i < m_lista.size(); i++)
        rez[i] = m_lista[i];
    
    unsigned j = i;
    for(unsigned k = 0; k < l.m_lista.size(); k++)
        rez[j++] = l.m_lista[k];
    
    return new Lista(rez);
}
