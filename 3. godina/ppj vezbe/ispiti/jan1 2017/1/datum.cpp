#include"datum.hpp"
using namespace std;

Datum::Datum(){}

Datum::Datum(int day, int month, int year) 
    : m_day(day), m_month(month), m_year(year)
    {}
    
int Datum::getDay(){
    return m_day;
}

int Datum::getMonth(){
    return m_month;
}

int Datum::getYear(){
    return m_year;
}
    
void Datum::printDate(){
    if(m_day > 0 && m_day < 10)
        cout << "0" << m_day;
    else
        cout << m_day;
    
    cout << ".";
    
    if(m_month > 0 && m_month < 10)
        cout << "0" << m_month;
    else
        cout << m_month;
    
    cout << ".";
    
    if(m_year < 10)
        cout << "000" << m_year;
    else if(m_year > 10 && m_year < 100)
        cout << "00" << m_year;
    else if(m_year > 100 && m_year < 1000)
        cout << "0" << m_year;
    else
        cout << m_year;
    
    cout << endl;    
}

void Datum::printISO(){
    
    if(m_year < 10)
        cout << "000" << m_year;
    else if(m_year > 10 && m_year < 100)
        cout << "00" << m_year;
    else if(m_year > 100 && m_year < 1000)
        cout << "0" << m_year;
    else
        cout << m_year;
    
    cout << "-";
    
    if(m_month > 0 && m_month < 10)
        cout << "0" << m_month;
    else
        cout << m_month;
    
    cout << "-";
    
    if(m_day > 0 && m_day < 10)
        cout << "0" << m_day;
    else
        cout << m_day;
    
    cout << endl;
}

void Datum::printUSA(){
    
    if(m_month > 0 && m_month < 10)
        cout << "0" << m_month;
    else
        cout << m_month;  
    
    cout << "/";
    
    if(m_day > 0 && m_day < 10)
        cout << "0" << m_day;
    else
        cout << m_day;    
    
    cout << "/";
    
    if(m_year < 10)
        cout << "000" << m_year;
    else if(m_year > 10 && m_year < 100)
        cout << "00" << m_year;
    else if(m_year > 100 && m_year < 1000)
        cout << "0" << m_year;
    else
        cout << m_year;
        
    cout << endl;
}

bool Datum::same(Datum& d){
    if(m_day == d.m_day && m_month == d.m_month && m_year == d.m_year)
        return true;
    else
        return false;
}

bool Datum::sooner(Datum& d){
    if(m_year < d.m_year)
        return true;
    else if(m_year == d.m_year){
        if(m_month < d.m_month)
            return true;
        else if(m_month == d.m_month)
            if(m_day < d.m_day)
                return true;
    }
    return false;
}
