#ifndef _DATUM_H
#define _DATUM_H

#include<iostream>
#include<cstdlib>

class Datum {
public:
    Datum();
    Datum(int day, int month, int year);
    
    int getDay();
    int getMonth();
    int getYear();
    
    void printDate();
    void printISO();
    void printUSA();
    bool same(Datum& d);
    bool sooner(Datum& d);
    
private:
    int m_day;
    int m_month;
    int m_year;
};

#endif
