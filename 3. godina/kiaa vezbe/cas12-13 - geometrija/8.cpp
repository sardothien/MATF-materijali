/* Date su dve duzi u ravni. Utvrditi da li se ove duzi seku. */

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

bool pripadaDuzi(Tacka A, Tacka C, Tacka B){
    if(C.x <= max(A.x, B.x) && C.x >= min(A.x, B.x) &&
       C.y <= max(A.y, B.y) && C.y >= min(A.y, B.y))
        return true;
    else
        return false;
}

bool sekuSe(Tacka P1, Tacka Q1, Tacka P2, Tacka Q2){
    int o1 = orijentacija(P1, Q1, P2);
    int o2 = orijentacija(P1, Q1, Q2);
    int o3 = orijentacija(P2, Q2, P1);
    int o4 = orijentacija(P2, Q2, Q1);
    
    if(o1 != o2 && o3 != o4)
        return true;
    if(o1 == 1 && pripadaDuzi(P1, P2, Q1))
        return true;
    if(o2 == 1 && pripadaDuzi(P1, Q2, Q1))
        return true;
    if(o3 == 1 && pripadaDuzi(P2, P1, Q2))
        return true;
    if(o4 == 1 && pripadaDuzi(P2, Q1, Q2))
        return true;
    
    return false;
}

int main(){
    
    Tacka P1, Q1, P2, Q2;
    cin >> P1.x >> P1.y;
    cin >> Q1.x >> Q1.y;
    cin >> P2.x >> P2.y;
    cin >> Q1.x >> Q2.y;
    
    if(sekuSe(P1, Q1, P2, Q2))
        cout << "seku se" << endl;
    else
        cout << "ne seku se" << endl;
    
    return 0;
}
