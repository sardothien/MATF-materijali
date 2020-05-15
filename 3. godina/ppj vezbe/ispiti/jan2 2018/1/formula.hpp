#ifndef _FORMULA_H_
#define _FORMULA_H_

#include<string>
using namespace std;

// True 1
// False 0
// Undef -1

class Formula {
public:
    Formula(int val);
        
    int konjukcija(const Formula& f) const;
    int disjunkcija(const Formula& f) const;
    int ekvivalencija(const Formula& f) const;
    int implikacija(const Formula& f) const;
    int negacija() const;
    
    int vrednost() const;
    std::string str() const;
    
private:
    int m_val;
};

#endif
