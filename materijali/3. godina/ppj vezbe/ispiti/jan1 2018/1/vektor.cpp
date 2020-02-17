#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include"vektor.hpp"
using namespace std;

cvor* dodaj_na_kraj(cvor* lista, float n){
    if(lista == nullptr)
        lista = novi(n);
    else{
        cvor* pom = lista;
        while(pom->sled != nullptr)
            pom = pom->sled;
        pom->sled = novi(n);
    }
    return lista;
}

cvor* novi(float n){
    cvor* pom = (cvor*)malloc(sizeof(cvor));
    
    pom->sled = nullptr;
    pom->vr = n;
    
    return pom;
}

void ispisi(cvor* lista){
    cout << "<";
    cvor* pom = lista;
    while(pom->sled != nullptr){
        cout << pom->vr << ", ";
        pom = pom->sled;
    }
    cout << pom->vr << ">" << endl;
}

int duz(cvor* lista){
    int i = 0;
    cvor* l = lista;
    while(l != nullptr){
        i++;
        l = l->sled;
    }
    return i;
}

cvor* saberi(cvor* l1, cvor* l2){
    if(duz(l1) != duz(l2))
        cerr << "Greska u dimenziji" << endl;
    else {
        cvor* pom = nullptr;
        while (l1 != nullptr){
            pom = dodaj_na_kraj(pom, l1->vr + l2->vr);
            l1 = l1->sled;
            l2 = l2->sled;
        }
        return pom;
    }
}

cvor* oduzmi(cvor* l1, cvor* l2){
    if(duz(l1) != duz(l2))
        cerr << "Greska u dimenziji" << endl;
    else{
        cvor* pom = nullptr;
        while (l1 != nullptr){
            pom = dodaj_na_kraj(pom, l1->vr - l2->vr);
            l1 = l1->sled;
            l2 = l2->sled;
        }
        return pom;
    }
}

cvor* pomnozi(cvor* lista, double n){
    cvor* pom = lista;
	while (pom != nullptr){
		pom->vr = pom->vr * n;
        pom = pom->sled;
	}
	return lista;
}

float norma(cvor* l){
    cvor* pom = l;
    float s = 0;
    
    while(pom != nullptr){
        s += pom->vr * pom->vr;
        pom = pom->sled;
    }
    
    return sqrt(s);
}

float skalarno(cvor* l1, cvor* l2){
    if(duz(l1) != duz(l2))
        cerr << "Greska u dimenziji" << endl;
    else{
        float s = 0;
        while(l1 != nullptr){
            s += l1->vr * l2->vr;
            l1 = l1->sled;
            l2 = l2->sled;
        }
        
        return s;
    }
}

float ugao(cvor* l1, cvor* l2){
    if(duz(l1) != duz(l2))
        cerr << "Greska u dimenziji" << endl;
    
    float k = skalarno(l1, l2) / (norma(l1) * norma(l2));
    return acos(k);
}

void jednaki(cvor* l1, cvor* l2){
    double k = l2->vr / l1->vr;

	cvor* pom1 = l1;
	cvor* pom2 = l1;

	while(pom1 != nullptr){
		
		if ((pom1->vr * k == pom2->vr)) {
			cout << "False\n";
			break;
		}
		else{
			pom1 = pom1->sled;
			pom2 = pom2->sled;
		}
	}
	if (pom1 == nullptr)
        cout << "True\n";
}
