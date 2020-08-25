/* Za date tacke C i D utvrditi da li su sa iste strane 
 * prave p odredjene tackama A i B. */

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
    
    Tacka A, B;
    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    
    Tacka C, D;
    cin >> C.x >> C.y;
    cin >> D.x >> D.y;
    
    int o1 = orijentacija(A, B, C);
    int o2 = orijentacija(A, B, D);
    
    if(o1 == o2)
        cout << "sa iste strane" << endl;
    else
        cout << "nisu sa iste strane" << endl; 
    
    return 0;
}
