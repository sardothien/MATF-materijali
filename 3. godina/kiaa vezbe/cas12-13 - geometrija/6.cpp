/* Za dati trougao odrediti njegovu orijentaciju. */

#include<iostream>
using namespace std;

struct Tacka {
    double x;
    double y;
};

int orijentacija(Tacka A, Tacka B, Tacka C){
    int d = (B.x-A.x)*(C.y-A.y) - (C.x-A.x)*(B.y-A.y);
    if(d == 0) // kolinearne
        return 0;
    else if(d > 0)
        return 1; // pozitivna
    else
        return -1; // negativna
}

int main(){
    
    Tacka A, B, C;
    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;
    
    int o = orijentacija(A, B, C);
    if(o == 0)
        cout << "kolinearne" << endl;
    else if(o == -1)
        cout << "negativna orijentacija" << endl;
    else
        cout << "pozitivna orijentacija" << endl;
    
    return 0;
}
