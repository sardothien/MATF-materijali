/* Ispitati da li tacka Q pripada konveksnom mnogouglu. */

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

#define EPS 1.0E-6;

struct Tacka {
    double x;
    double y;
};

int orijentacija(Tacka A, Tacka B, Tacka C){
    double d = (B.x - A.x)*(C.y - A.y) - (B.y - A.y)*(C.x - A.x);
    if(d == 0)
        return 0;
    else if(d > 0)
        return 1;
    else
        return -1;    
}

bool saIsteStrane(Tacka A, Tacka B, Tacka C, Tacka D){
    int o1 = orijentacija(A, B, C);
    int o2 = orijentacija(A, B, D);
    
    if(o1 == o2)
        return true;
    else
        return false;
}

double povrsina(Tacka A, Tacka B, Tacka C){
    return abs(B.x*C.y - A.x*C.y - B.x*A.y 
             - B.y*C.x + A.y*C.x + B.y*A.x) / 2.0;
}

bool tackaUTrouglu(Tacka A, Tacka B, Tacka C, Tacka P){
    double T = povrsina(A, B, C);
    double P1 = povrsina(P, B, C);
    double P2 = povrsina(A, P, C);
    double P3 = povrsina(A, B, P);
    
    return abs(T - (P1 + P2 + P3)) < EPS;    
}

bool uMnogouglu(vector<Tacka> tacke, Tacka Q){
    int n = tacke.size();
    
    if(orijentacija(tacke[0], tacke[1], Q) != 1 ||
       orijentacija(tacke[n-1], tacke[0], Q) != 1)
        return false;
        
    int i = 1, j = n-1;
    while(j-i > 1){
        int m = (j+i)/2;
        if(saIsteStrane(tacke[0], tacke[m], Q, tacke[j]))
            i = m;
        else
            j = m;
    }
    
    return tackaUTrouglu(tacke[i], tacke[i+1], tacke[0], Q);
}

int main(){
    
    vector<Tacka> tacke = {
        {1, -2}, {3, -1}, {5, 1},
        {4, 3}, {1, 4}, {0, 1}
    };

    Tacka Q = {2, 1};
    Tacka R = {2, -2};
        
    if(uMnogouglu(tacke, Q))
        cout << "Tacka Q je u mnogouglu" << endl;
    else
        cout << "Tacka Q nije u mnogouglu" << endl;
    
    if(uMnogouglu(tacke, R))
        cout << "Tacka R je u mnogouglu" << endl;
    else
        cout << "Tacka R nije u mnogouglu" << endl;
    
    return 0;
}
