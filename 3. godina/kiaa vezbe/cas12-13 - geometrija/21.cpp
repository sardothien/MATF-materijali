/* Dato je N tačaka u ravni nazivom i koordinatama. Kreirajte
 * program koji pronalazi sve trouglove čija tri temena mogu
 * biti date tačke. */

#include<iostream>
using namespace std;

struct Tacka {
    int x, y;
};

bool kolinearne(Tacka A, Tacka B, Tacka C){
    if((B.y - A.y) * (C.x - A.x) == (C.y - A.y) * (B.x -A.x))
        return true;
    else
        return false;
}

int main(){

    int n;
    cin >> n;

    char imeTacke[26];
    Tacka tacke[26];

    for(int i = 0; i < n; i++)
        cin >> imeTacke[i] >> tacke[i].x >> tacke[i].y;

    bool nadjeno = false;

    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
            for(int k = j+1; k < n; k++)
                if(!kolinearne(tacke[i], tacke[j], tacke[k])){
                    cout << imeTacke[i] << " " << imeTacke[j] << " " << imeTacke[k] << endl;
                    nadjeno = true;
                }

    if(!nadjeno)
        cout << "Nema trouglova." << endl;

    return 0;
}
