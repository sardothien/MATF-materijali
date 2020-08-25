/* Dato je n tacaka u ravni takvih da nisu sve kolinearne.
 * Povezati ih prostim mnogouglom. */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Tacka {
    int x;
    int y;
};

Tacka P0;

void swap(Tacka& A, Tacka& B){
    Tacka pom;
    pom = A;
    A = B;
    B = pom;
}

int orijentacija(Tacka A, Tacka B, Tacka C){
    int d = (B.x-A.x)*(C.y-A.y) - (C.x-A.x)*(B.y-C.y);
    if(d == 0)
        return 0;
    else if(d > 0)
        return 1;
    else 
        return -1;
}

int kvadratRastojanja(Tacka A, Tacka B){
    return (A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y);
}

void odstampajMnogougao(vector<Tacka>& tacke){
    
    int n = tacke.size();
    int x_min = tacke[0].x;
    int min = 0;
    
    for(int i = 1; i < n; i++){
        int x = tacke[i].x;
        if((x < x_min) || (x_min == x && tacke[i].y < tacke[min].y)){
            x_min = x;
            min = i;
        }
    }
    
    swap(tacke[0], tacke[min]);
    
    P0 = tacke[0];
    
    sort(tacke.begin()+1, tacke.end(), [](auto& P1, auto& P2){
        if(orijentacija(P0, P1, P2) == 0){
            if(kvadratRastojanja(P0, P1) <= kvadratRastojanja(P0, P2))
                return true;
            else
                return false;
        }
        else if(orijentacija(P0, P1, P2) == 1)
            return true;
        else
            return false;
    });
    
    for(int i = 0; i < n; i++)
        cout << "(" << tacke[i].x << ", " << tacke[i].y << "), ";
    cout << endl;
}

int main(){
    
    vector<Tacka> tacke = {
        {0, 3}, {1, 1}, {2, 2}, {4, 4},
        {0, 0}, {1, 2}, {3, 1}, {3, 3}
    };
    
    odstampajMnogougao(tacke);
    
    return 0;
}
