/* Римљани опет нападају Гале. У галском селу постоји N стубова око којих
 * се могу градити заштитне зидине и М кућа. Заштитне зидине се граде тако
 * што се подижу између стубова. Дакле, између свака 2 стуба можемо изградити
 * део зида. Помозите Галима да утврде да ли могу да изграде заштитне зидине
 * око стубова и да заштите све куће у селу. У првој линији стандардног улаза
 * се уносе бројеви N и М. У наредних N линија се уносе по 2 броја која
 * представљају позиције стубова. Након тога се у наредних М линија уносе
 * позиције кућа у селу. У јединој линији стандардног излаза исписати NE ако
 * је немогуће оградити све куће заштитном оградом која се формира око стубова,
 * а DА иначе. Сложеност алгоритма треба да буде О(𝑁log𝑁). Вредности координата
 * по апсолутној вредности неће прелазити 500. Вредности природних бројева
 * N и М неће прелазити 1000. Напомена: Не морају сви стубови бити искоришћени. */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Tacka {
    int x, y;
    bool zid;
};

Tacka P0;

int orijentacija(Tacka& A, Tacka& B, Tacka& C){
    int d = (B.y-A.y)*(C.x-A.x) - (C.y-A.y)*(B.x-A.x);
    if(d == 0)
        return 0;
    else if(d > 0)
        return 1;
    else
        return -1;
}

int rastojanje(Tacka& A, Tacka& B){
    return (A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y);
}
bool poredi(Tacka& t1, Tacka& t2){
    int o = orijentacija(P0, t1, t2);
    if(o == 0)
        return rastojanje(P0, t1) < rastojanje(P0, t2);
    else if(o == 1)
        return false;
    else
        return true;
}

void swap(Tacka& A, Tacka& B){
    Tacka pom = A;
    A = B;
    B = pom;
}

int nadji_max(vector<Tacka>& tacke){
    int max_x = tacke[0].x;
    int min_y = tacke[0].y;
    int ind = 0;

    int n = tacke.size();

    for(int i = 1; i < n; i++){
        if(tacke[i].x > max_x){
            max_x = tacke[i].x;
            min_y = tacke[i].y;
            ind = i;
        }
        else if(tacke[i].x == max_x && tacke[i].y < min_y){
            min_y = tacke[i].y;
            ind = i;
        }
    }

    return ind;
}

void konveksniOmotac(vector<Tacka>& tacke){

    int max = nadji_max(tacke);

    swap(tacke[0], tacke[max]);

    P0 = tacke[0];

    sort(tacke.begin()+1, tacke.end(), poredi);

    vector<Tacka> rezultat;

    rezultat.push_back(tacke[0]);
    rezultat.push_back(tacke[1]);
    rezultat.push_back(tacke[2]);

    int n = tacke.size();
    int m = 2;

    for(int k = 3; k < n; k++){
        while(orijentacija(rezultat[m-1], rezultat[m], tacke[k]) == 1){
            rezultat.pop_back();
            m--;
        }

        m++;
        rezultat.push_back(tacke[k]);
    }

    for(Tacka& t : rezultat)
        if(t.zid == false){
            cout << "NE" << endl;
            return;
        }

    cout << "DA" << endl;
}

int main(){

    int n, m;
    cin >> n >> m;

    vector<Tacka> tacke(n+m);

    for(int i = 0; i < n; i++){
        cin >> tacke[i].x >> tacke[i].y;
        tacke[i].zid = true;
    }

    for(int i = n; i < m+n; i++){
        cin >> tacke[i].x >> tacke[i].y;
        tacke[i].zid = false;
    }

    konveksniOmotac(tacke);

    return 0;
}
