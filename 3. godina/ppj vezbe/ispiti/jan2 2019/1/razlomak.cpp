#include<iostream>
#include<cstdlib>
#include"razlomak.hpp"
using namespace std;

int nzd(int a, int b){
    if(b == 0)
        return a;
    else
        return abs(nzd(b, a%b));
}

Razlomak::Razlomak(int _br, int _im){
    if(_im == 0){
        cerr << "Nije dozvoljeno!" << endl;
        exit(EXIT_FAILURE);
    }
    int d = nzd(max(_br, _im), min(_br, _im));
    m_im = _im / d;
    m_br = _br / d;
}
    
int Razlomak::getBr(){
    return m_br;
}

int Razlomak::getIm(){
    return m_im;
}
    
Razlomak* Razlomak::saberi(Razlomak& r1, Razlomak& r2){
    int imenilac, brojilac;
    
    imenilac = r1.getIm() * r2.getIm();
    brojilac = r1.getBr() * r2.getIm() + r2.getBr() * r1.getIm();
    
    int d = nzd(imenilac, brojilac);
    imenilac /= d;
    brojilac /= d;
    
    return new Razlomak(brojilac, imenilac);
}

Razlomak* Razlomak::oduzmi(Razlomak& r1, Razlomak& r2){
    int imenilac, brojilac;
    
    imenilac = r1.getIm() * r2.getIm();
    brojilac = r1.getBr() * r2.getIm() - r2.getBr() * r1.getIm();
    
    int d = nzd(imenilac, brojilac);
    imenilac /= d;
    brojilac /= d;
    
    return new Razlomak(brojilac, imenilac);
}

Razlomak* Razlomak::pomnozi(Razlomak& r1, Razlomak& r2){
    int imenilac, brojilac;
    
    imenilac = r1.getIm() * r2.getIm();
    brojilac = r1.getBr() * r2.getBr();
    
    int d = nzd(imenilac, brojilac);
    imenilac /= d;
    brojilac /= d;
    
    return new Razlomak(brojilac, imenilac);
}

Razlomak* Razlomak::podeli(Razlomak& r1, Razlomak& r2){
    if(r2.getBr() == 0){
        cerr << "Ne moze se deliti nulom" << endl;
        exit(EXIT_FAILURE);
    }
    
    int imenilac, brojilac;
    
    imenilac = r1.getIm() * r2.getBr();
    brojilac = r1.getBr() * r2.getIm();
    
    int d = nzd(imenilac, brojilac);
    imenilac /= d;
    brojilac /= d;
    
    return new Razlomak(brojilac, imenilac);
}
    
void Razlomak::ispisi(Razlomak& r){
    if(r.getIm() == 1)
        cout << "[" << r.getBr() << "]" << endl;
    else if(r.getIm() == -1)
        cout << "[" << -1*r.getBr() << "]" << endl;
    else
        cout << "[" << r.getBr() << ", " << r.getIm() << "]" << endl;
}
