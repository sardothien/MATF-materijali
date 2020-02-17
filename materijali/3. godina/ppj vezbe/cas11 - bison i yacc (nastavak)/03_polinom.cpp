#include "03_polinom.hpp"

void Polinom::dodaj(float c){
    koeficijenti.push_back(c);
}

void Polinom::ispisi() const{
    for(unsigned i = 0; i < koeficijenti.size(); i++){
        if(koeficijenti[i] == 0)
            continue;
        if(i != 0 && koeficijenti[i] > 0)
            cout << "+ ";
        cout << koeficijenti[i];
        if(i > 0)
            cout << "x";
        if(i > 1)
            cout << "^" << i;
        cout << " ";
    }
    
    if(koeficijenti.size() == 1 && koeficijenti[0] == 0)
        cout << 0;
    cout << endl;
}

const vector<float>& Polinom::get_koef() const{
    return koeficijenti;
}

unsigned Polinom::stepen() const{
    return koeficijenti.size()-1;
}

void Polinom::sredi_koeficijente(){
    int velicina = koeficijenti.size();
    for(int i = velicina-1; i > 0; i--)
        if(koeficijenti[i] == 0)
            velicina--;
    
    koeficijenti.resize(velicina);
}

bool Polinom::jednak(const Polinom& p) const{
    if(stepen() != p.stepen())
        return false;
    
    for(unsigned i = 0; i <= stepen(); i++)
        if(koeficijenti[i] != p.koeficijenti[i])
            return false;
        
    return true;
}

float Polinom::vrednost(float x) const{
    float rez = 0;
    int i = stepen();
    for(; i >= 0; i--)
        rez = rez * x + koeficijenti[i];
    return rez;
}

void Polinom::izvod(){
    if(stepen() > 0){
        unsigned novi_stepen = stepen()-1;
        for(unsigned i = 0; i <= novi_stepen; i++)
            koeficijenti[i] = (i+1) * koeficijenti[i+1];
        koeficijenti.resize(novi_stepen+1);
    }
    else
        koeficijenti[0] = 0;
}

void Polinom::integral(float x){
    unsigned novi_stepen = stepen() + 1;
    koeficijenti.resize(novi_stepen+1);
    for(unsigned i = novi_stepen; i > 0; i--)
        koeficijenti[i] = 1.0 / i * koeficijenti[i-1];
    koeficijenti[0] = x;
}

// Prijateljske funkcije

Polinom* saberi(const Polinom& p1, const Polinom& p2){
    unsigned stepen = max(p1.stepen(), p2.stepen());
    vector<float> r_koef(stepen+1);
    
    for(unsigned i = 0; i <= stepen; i++){
        if(i > p1.stepen())
            r_koef[i] = 0;
        else
            r_koef[i] = p1.get_koef()[i];
        
        if(i <= p2.stepen())
            r_koef[i] += p2.get_koef()[i];
    }
    
    Polinom* rez = new Polinom(r_koef);
    rez->sredi_koeficijente();
    
    return rez;
}

Polinom* oduzmi(const Polinom& p1, const Polinom& p2){
    unsigned stepen = max(p1.stepen(), p2.stepen());
    vector<float> r_koef(stepen+1);
    
    for(unsigned i = 0; i <= stepen; i++){
        if(i > p1.stepen())
            r_koef[i] = 0;
        else
            r_koef[i] = p1.get_koef()[i];
        
        if(i <= p2.stepen())
            r_koef[i] -= p2.get_koef()[i];
    }
    
    Polinom* rez = new Polinom(r_koef);
    rez->sredi_koeficijente();
    
    return rez;
}

Polinom* pomnozi(const Polinom& p1, const Polinom& p2){
    unsigned stepen = p1.stepen() + p2.stepen();
    vector<float> r_koef(stepen+1, 0);
    
    for(unsigned i = 0; i <= p1.stepen(); i++)
        for(unsigned j = 0; j <= p2.stepen(); j++)
            r_koef[i+j] += p1.get_koef()[i] * p2.get_koef()[j];
    
    Polinom* rez = new Polinom(r_koef);
    rez->sredi_koeficijente();
    
    return rez;
}

Polinom* uminus(const Polinom& p1){
    Polinom* rez = new Polinom(p1);
    
    for(unsigned i = 0; i <= rez->stepen(); i++)
        rez->koeficijenti[i] *= -1;
    
    return rez;
}
