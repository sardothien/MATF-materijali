/* Na ceremoniji otvaranja Svetskog kupa postoji plesna 
 * tačka gde mnoga deca širom sveta pokušavaju da kreiraju
 * veliki krug na poljani. Oni su uspeli da naprave savršeni
 * krug, ali pošto deca nisu baš marljivo vežbala, onda nisu 
 * bili ravnomerno raspoređeni po krugu. Vi ste to brzo uočili
 * i želite da znate koje je minimalno rastojanje između neka 
 * dva deteta. Prva linija standardnog ulaza sadrži broj NN koji 
 * predstavlja broj dece. Svaka od sledećih N linija sadrži dva 
 * realna broja zaokružena na dva decimalna mesta – koordinate 
 * svakog deteta. Garantuje se da će sve tačke biti na krugu. Prva
 * i jedina linija standardnog izlaza treba da sadrži jedan realan
 * broj (zaokružen na dva decimale) – Euklidsko rastojanje između 
 * dva najbliža deteta. */
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

#define EPS 0.000001

struct Tacka {
    double x, y;
};

Tacka tacke[333555];

double rastojanje(Tacka p1, Tacka p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

bool poredi(Tacka p1, Tacka p2){
    double u1, u2;
    
    if(fabs(p1.y - tacke[0].y) < EPS)
        return false;
    if(fabs(p2.y - tacke[0].y) < EPS)
        return true;
    
    u1 = (p1.x - tacke[0].x) / (p1.y - tacke[0].y);
    u2 = (p2.x - tacke[0].x) / (p2.y - tacke[0].y);

    return (u1 < u2);
}

int main(){
    
    int n, p, i;
    double d, rez;
    Tacka tmp;
    
    cin >> n;
    p = 0;
    
    for(i = 0; i < n; i++){
        cin >> tacke[i].x >> tacke[i].y;
        if(tacke[i].y < tacke[p].y || 
          (fabs(tacke[i].y - tacke[p].y) < EPS && tacke[i].x < tacke[p].x))
            p = i;
    }
    
    tmp = tacke[0];
    tacke[0] = tacke[p];
    tacke[p] = tmp;
    
    sort(tacke+1, tacke+n, poredi);
    
    rez = rastojanje(tacke[0], tacke[n-1]);
    
    for(i = 1; i < n; i++){
        d = rastojanje(tacke[i], tacke[i-1]);
        if(d < rez)
            rez = d;
    }
    
    cout << rez << endl;
    
    return 0;
}
