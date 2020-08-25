/* Da li data tacka pripada pravougaoniku? */

#include<iostream>
#include<cmath>
using namespace std;

struct Tacka {
    double x;
    double y;
};

double povrsinaTrougla(Tacka A, Tacka B, Tacka C){
    return abs(B.x*C.y - A.x*C.y - B.x*A.y 
             - B.y*C.x + A.y*C.x + B.y*A.x) / 2.0;
}

bool uPravougaoniku(Tacka A, Tacka B, Tacka C, Tacka D, Tacka P){
    double p = povrsinaTrougla(A, B, C) + povrsinaTrougla(A, D, C);

    double p1 = povrsinaTrougla(P, A, B);
    double p2 = povrsinaTrougla(P, B, C);
    double p3 = povrsinaTrougla(P, C, D);
    double p4 = povrsinaTrougla(P, A, D);
    
    return (p == p1 + p2 + p3 + p4);
}

int main(){
    
    Tacka A, B, C, D, P;
    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;
    cin >> D.x >> D.y;
    cin >> P.x >> P.y;
    
    if(uPravougaoniku(A, B, C, D, P))
        cout << "Jeste u pravougaoniku" << endl;
    else
        cout << "Nije u pravougaoniku" << endl;
        
    return 0;
}
