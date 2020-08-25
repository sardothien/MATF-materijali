/* Dat je trougao ABC i tacka P. Ispitati da li tacka
 * P pripada trouglu ABC ili ne. */

#include<iostream>
using namespace std;

struct Tacka {
    double x;
    double y;
};

int orijentacija(Tacka A, Tacka B, Tacka C){
    int d = (B.x-A.x)*(C.y-A.y) - (C.x-A.x)*(B.y-A.y);
    if(d == 0)
        return 0;
    else if(d > 0)
        return 1;
    else
        return -1;
}

int main(){
    
    Tacka A, B, C, P;
    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;
    cin >> P.x >> P.y;
    
    int o1 = orijentacija(A, B, P);
    int o2 = orijentacija(B, C, P);
    int o3 = orijentacija(C, A, P);
    
    if(o1 == o2 && o2 == o3)
        cout << "u trouglu" << endl;
    else
        cout << "nije u trouglu" << endl;    
    
    return 0;
}
