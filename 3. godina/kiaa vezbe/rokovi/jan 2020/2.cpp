/* Neka je dato *n* tacaka u ravni svojim *x* i *y* koordinatama.
 * Konstruisati algoritam slozenosti O(n^2logn) koji odredjuje
 * koliko se maksimalno jednakostranicnih trouglova (cija je
 * jedna stranica paralelna sa nekom od koordinatnih osa) moze
 * formirati od ovih tacaka. Sa standardnog ulaza se unosi broj
 * *n* a zatim i *n* parova brojeva koje predstavljaju koordinate
 * tacaka. Na standardni izlaz ispisati koliko se maksimalno
 * jednakostranicnih trouglova moze formirati od ovih tacaka. Zbog
 * nesavrsenosti cuvanja brojeva u pokretnom zarezu u racunaru
 * zadatak resavati sa preciznoscu na 2 decimale. Dakle brojevi
 * 3.546 i 3.548 su isti dok se 1.436 i 1.429 razlikuju. */

#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

struct Tacka {
    double x, y;
};

bool poredi(Tacka& p1, Tacka& p2){
    if((int)p1.x*100 == (int)p2.x*100)
        return (int)p1.y*100 < (int)p2.y*100;

    return (int)p1.x*100 < (int)p2.x*100;
}

int brojTrouglova(const vector<Tacka>& tacke){

    sort(tacke.begin(), tacke.end(), poredi);

    int n = tacke.size();

    double pom_x, pom_y;
    int br = 0;

    Tacka A;
    double strana;

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if((int)tacke[i].x*100 == (int)tacke[j].x*100){
                strana = abs(tacke[i].y - tacke[j].y);

                pom_x = tacke[i].x + strana*sqrt(3) / 2.0;
                pom_y = (tacke[i].y + tacke[j].y) / 2.0;

                A.x = pom_x;
                A.y = pom_y;

                if(binary_search(tacke.begin(), tacke.end(), A, poredi))
                    br++;

                pom_x = tacke[i].x - strana*sqrt(3) / 2.0;

                A.x = pom_x;
                A.y = pom_y;

                if(binary_search(tacke.begin(), tacke.end(), A, poredi))
                    br++;
            }
            else if((int)tacke[i].y*100 == (int)tacke[j].y*100){
                strana = abs(tacke[i].x - tacke[j].x);

                pom_y = tacke[i].y + strana*sqrt(3) / 2.0;
                pom_x = (tacke[i].x + tacke[j].x) / 2.0;

                A.x = pom_x;
                A.y = pom_y;

                if(binary_search(tacke.begin(), tacke.end(), A, poredi))
                    br++;

                pom_y = tacke[i].y - strana*sqrt(3) / 2.0;

                A.x = pom_x;
                A.y = pom_y;

                if(binary_search(tacke.begin(), tacke.end(), A, poredi))
                    br++;
            }
        }
    }

    return br;
}

int main(){

    int n;

    vector<Tacka> tacke(n);

    for(int i = 0; i < n; i++)
        cin >> tacke[i].x >> tacke[i].y;

    cout << brojTrouglova(tacke) << endl;

    return 0;
}
