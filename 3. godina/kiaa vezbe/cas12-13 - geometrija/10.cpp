/* Izracunati uglove trougla. */

#include<iostream>
#include<cmath>
using namespace std;

struct Tacka {
    double x, y;
};

double rastojanje(Tacka A, Tacka B){
    double dx = B.x - A.x;
    double dy = B.y - A.y;
    
    return sqrt(dx*dx + dy*dy);
}

void ispisiUglove(Tacka A, Tacka B, Tacka C){
    double a = rastojanje(B, C);
    double b = rastojanje(A, C);
    double c = rastojanje(A, B);
    
    double alfa = acos((b*b + c*c - a*a) / (2*b*c));
    double beta = acos((a*a + c*c - b*b) / (2*a*c));
    double gama = acos((b*b + a*a - c*c) / (2*b*a));
    
    alfa *= 180/3.14;
    beta *= 180/3.14;
    gama *= 180/3.14;
    
    cout << alfa << " " << beta << " " << gama << endl;
}

int main(){
    
    Tacka A, B, C;
    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;
    
    ispisiUglove(A, B, C);
    
    return 0;
}
