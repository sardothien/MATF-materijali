// Uvijanje poklona
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

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

bool poredi(Tacka &p1, Tacka &p2){
    return (p1.x < p2.x) || (p1.x == p2.x && p1.y > p2.y);
}

void konveksniOmotac(vector<Tacka> tacke){
    int n = tacke.size();
    
    if(n < 3)
        return;
    
    vector<Tacka> omotac;
    
    int max = max_element(tacke.begin(), tacke.end(), poredi) - tacke.begin();
    int tekuca = max;
    int naredna;
    
    do{
        omotac.push_back(tacke[tekuca]);
        naredna = (tekuca+1) % n;
        
        for(int i = 0; i < n; i++)
            if(orijentacija(tacke[tekuca], tacke[naredna], tacke[i]) == -1)
                naredna = i;
            
        tekuca = naredna;
    }while(tekuca != max);
    
    for(int i = 0; i < omotac.size(); i++)
        cout << "(" << omotac[i].x << ", " << omotac[i].y << ")" << endl;
}

int main(){
    
    vector<Tacka> tacke = {
        {0,3}, {1,1}, {2,2}, {4,4},
        {0,0}, {1,2}, {3,1}, {3,3}
    };

    konveksniOmotac(tacke);    
    
    return 0;
}
