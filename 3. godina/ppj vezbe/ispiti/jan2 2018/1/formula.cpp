#include<iostream>
#include<cstdlib>
#include<string>
#include"formula.hpp"
using namespace std;

Formula::Formula(int val) : m_val(val){}
        
int Formula::konjukcija(const Formula& f) const{
    if(f.m_val == 1 && m_val == 1)
        return 1;
    else if(f.m_val == 0 || m_val == 0)
        return 0;
    else
        return -1;
}

int Formula::disjunkcija(const Formula& f) const{
    if(f.m_val == 0 && m_val == 0)
        return 0;
    else if(f.m_val == 1 || m_val == 1)
        return 1;
    else
        return -1;
}

int Formula::ekvivalencija(const Formula& f) const{
    Formula f1 = Formula(this->implikacija(f));
    Formula f2 = Formula(f.implikacija(*this));
    return f1.konjukcija(f2);
}

int Formula::implikacija(const Formula& f) const{
    Formula f1 = Formula(this->negacija());
    return f1.disjunkcija(f);
}

int Formula::negacija() const{
    if(m_val == -1)
        return -1;
    else if(m_val == 1)
        return 0;
    else
        return 1;
}
    
int Formula::vrednost() const{
    return m_val;
}

std::string Formula::str() const{
    if(m_val == -1)
        return "Undef";
    else if(m_val == 0)
        return "False";
    else
        return "True";
}
