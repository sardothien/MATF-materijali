/* Dat je trougao koordinatama svojih temena. Izracunati povrsinu. */

#include<iostream>
#include<cmath>
using namespace std;

struct Tacka {
    double x;
    double y;
};

double rastojanje(Tacka A, Tacka B){
    return sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y));
}

int main(){
    
    Tacka t1, t2, t3;
    cin >> t1.x >> t1.y;
    cin >> t2.x >> t2.y;
    cin >> t3.x >> t3.y;
    
    double a = rastojanje(t2, t3);
    double b = rastojanje(t1, t3);
    double c = rastojanje(t1, t2);
    
    int s = (a + b + c) / 2;
    
    int povrsina = sqrt(s*(s-a)*(s-b)*(s-c));
    cout << povrsina << endl;
    
    return 0;
}
