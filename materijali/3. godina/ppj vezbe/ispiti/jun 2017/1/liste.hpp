#ifndef _LISTA_H
#define _LISTA_H

#include<vector>
using namespace std;

class Lista {
public:
    Lista();
    Lista(vector<int>& v);
    
    void printList();
    Lista* concat(Lista& l);

private:
    vector<int> m_lista;
};

#endif
