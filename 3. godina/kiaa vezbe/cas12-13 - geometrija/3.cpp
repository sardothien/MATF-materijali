/* Naci polarne koordinate. */

#include<iostream>
#include<cmath>
using namespace std;

void polarne(double x, double y, double &r, double &ugao){
    r = sqrt(x*x + y*y);
    ugao = atan2(y, x);
}

void dekartovske(double &a, double &b, double r, double ugao){
    a = r * cos(ugao);
    b = r * sin(ugao);
}

int main(){
    
    double x, y;
    cin >> x >> y;
    
    double r, ugao;
    polarne(x, y, r, ugao);
    cout << r << " " << ugao << endl;
    
    double a, b;
    dekartovske(a, b, r, ugao);
    cout << a << " " << b << endl;

    return 0;
}
