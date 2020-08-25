// Grejemov algoritam
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

struct Tacka {
    int x;
    int y;
};

Tacka P0;

Tacka drugaSVrha(stack<Tacka> &S){
    Tacka prva = S.top();
    S.pop();
    Tacka druga = S.top();
    S.push(prva);
    return druga;
}

void swap(Tacka &A, Tacka &B){
    Tacka pom = A;
    A = B;
    B = pom;
}

int kvadratRastojanja(Tacka A, Tacka B){
    return (A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y);
}

int orijentacija(Tacka A, Tacka B, Tacka C){
    double d = (B.x - A.x)*(C.y - A.y) - (B.y - A.y)*(C.x - A.x);
    if(d == 0)
        return 0;
    else if(d > 0)
        return 1;
    else
        return -1;
}

bool poredi(Tacka &A, Tacka &B){
    int o = orijentacija(P0, A, B);
    if(o == 0)
        return (kvadratRastojanja(P0, A) <= kvadratRastojanja(P0, B))
                ? true : false;
    else if(o == 1)
        return true;
    else
        return false;
}

bool poredi_min(Tacka A, Tacka B){
    return (A.x < B.x) || (A.x == B.x && A.y < B.y);
}

void konveksniOmotac(vector<Tacka> tacke){
    int n = tacke.size();
    
    if(n < 3)
        return;
    
    int min = min_element(tacke.begin(), tacke.end(), poredi_min) - tacke.begin();
    
    swap(tacke[0], tacke[min]);
    P0 = tacke[0];
    
    sort(begin(tacke) + 1, end(tacke), poredi);
    
    stack<Tacka> omotac;
    
    omotac.push(tacke[0]);
    omotac.push(tacke[1]);
    omotac.push(tacke[2]);
    
    for(int i = 3; i < n; i++){
        while(orijentacija(drugaSVrha(omotac), omotac.top(), tacke[i]) != 1)
            omotac.pop();
        omotac.push(tacke[i]);
    }
    
    while(!omotac.empty()){
        Tacka p = omotac.top();
        cout << "(" << p.x << ", " << p.y << ")" << endl;
        omotac.pop();
    }
}

int main(){
    
    vector<Tacka> tacke = {
        {0,3}, {1,1}, {2,2}, {4,4},
        {0,0}, {1,2}, {3,1}, {3,3}
    };

    konveksniOmotac(tacke);
    
    return 0;
}
