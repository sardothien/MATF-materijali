#ifndef _RAZLOMAK_H
#define _RAZLOMAK_H

#include<iostream>
using namespace std;

class Razlomak {
public:
    Razlomak(int _br, int _im);
    
    int getBr();
    int getIm();
    
    Razlomak* saberi(Razlomak& r1, Razlomak& r2);
    Razlomak* oduzmi(Razlomak& r1, Razlomak& r2);
    Razlomak* pomnozi(Razlomak& r1, Razlomak& r2);
    Razlomak* podeli(Razlomak& r1, Razlomak& r2);
        
    void ispisi(Razlomak& r);
    
private:    
    int m_br, m_im;
};

#endif
