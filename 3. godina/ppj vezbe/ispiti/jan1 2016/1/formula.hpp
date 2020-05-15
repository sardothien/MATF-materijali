#ifndef _FORMULA_H_
#define _FORMULA_H_

#include<string>

class Logika {
public:
    Logika(int value);
    
    int DISJ_op(const Logika& l) const;
    int KONJ_op(const Logika& l) const;
    int IMPL_op(const Logika& l) const;
    int EKV_op(const Logika& l) const;
    int NEG_op() const;
    
    int val() const;
    std::string str() const;
    
private:
    int m_val;
};

#endif
