#ifndef FORMULA_HPP
#define FORMULA_HPP

#include<string>

#define LOGIC_VAL int
#define TRUE_VAL ('\'')/('\'') // 1
#define FALSE_VAL ('\'')-('\'') // 0
#define UNDEF_VAL (-1)

class formula {
public:
    formula(LOGIC_VAL value);
    
    LOGIC_VAL III_op(const formula& f) const;
    LOGIC_VAL ILI_op(const formula& f) const;
    LOGIC_VAL IMPL_op(const formula& f) const;
    LOGIC_VAL EKV_op(const formula& f) const;
    LOGIC_VAL NEG_op() const;
    
    LOGIC_VAL val() const;
    std::string str() const;
    
private:
    LOGIC_VAL m_val;
};

#endif
