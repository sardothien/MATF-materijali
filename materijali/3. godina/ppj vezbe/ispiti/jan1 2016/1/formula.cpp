#include"formula.hpp"

Logika::Logika(int value) : m_val(value){}
    
int Logika::DISJ_op(const Logika& l) const {
    if(m_val == 0 && l.m_val == 0)
        return 0;
    else if(m_val == 1 || l.m_val == 1)
        return 1;
    else
        return -1; // undefined
}

int Logika::KONJ_op(const Logika& l) const{
    if(m_val == 0 || l.m_val == 0)
        return 0;
    else if(m_val == 1 && l.m_val == 1)
        return 1;
    else -1;
}

int Logika::IMPL_op(const Logika& l) const{
    Logika negir = Logika(this->NEG_op());
    return negir.DISJ_op(l);
}

int Logika::EKV_op(const Logika& l) const{
    Logika l1 = Logika(this->IMPL_op(l));
    Logika l2 = Logika(l.IMPL_op(*this));
    return l1.KONJ_op(l2);
}

int Logika::NEG_op() const{
    if(m_val == -1)
        return -1;
    else if(m_val == 0)
        return 1;
    else
        return 0;
}
    
int Logika::val() const{
    return m_val;
}

std::string Logika::str() const{
    if(m_val == 1)
        return "True";
    else if(m_val == 0)
        return "False";
    else
        return "Undef";
}
