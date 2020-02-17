#include"formula.hpp"

formula::formula(LOGIC_VAL val) 
    : m_val(val)
{}

LOGIC_VAL formula::III_op(const formula& f) const {
    if(m_val == FALSE_VAL || f.m_val == FALSE_VAL)  
        return FALSE_VAL;
    if(m_val == TRUE_VAL && f.m_val == TRUE_VAL)
        return TRUE_VAL;
    else
        return UNDEF_VAL;
}

LOGIC_VAL formula::ILI_op(const formula& f) const {
    if (m_val == FALSE_VAL && f.m_val == FALSE_VAL)
        return FALSE_VAL;
    else if (m_val == TRUE_VAL || f.m_val == TRUE_VAL)
        return TRUE_VAL;
    else
        return UNDEF_VAL;
}

LOGIC_VAL formula::IMPL_op(const formula& f) const {
    formula negirano_this = formula(this->NEG_op());
    return negirano_this.ILI_op(f);
}

LOGIC_VAL formula::EKV_op(const formula& f) const {
    formula tmp1 = formula(this->IMPL_op(f)); 
    formula tmp2 = formula(f.IMPL_op(*this)); 
    return tmp1.III_op(tmp2);
}

LOGIC_VAL formula::NEG_op() const {
    if (m_val == UNDEF_VAL)
        return UNDEF_VAL;
    else if (m_val == TRUE_VAL)
        return FALSE_VAL;
    else
        return TRUE_VAL;
}

std::string formula::str() const {
    if(m_val == TRUE_VAL)
        return "True";
    else if(m_val == FALSE_VAL)
        return "False";
    else
        return "Undef";
}

LOGIC_VAL formula::val() const {
    return m_val;
}
