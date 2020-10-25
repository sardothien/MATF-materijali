#include<iostream>
using namespace std;

struct Tacka {
    double x, y;
    double z = 1;
};

void vektorski_proizvod(Tacka A, Tacka B, Tacka& rez){
    rez.x = A.y*B.z - A.z*B.y;
    rez.y = A.z*B.x - A.x*B.z;
    rez.z = A.x*B.y - A.y*B.x;
}

void nevidljivo(Tacka A, Tacka B, Tacka C, Tacka A1, Tacka B1, Tacka C1, Tacka D1){
    Tacka CB;
    vektorski_proizvod(C, B, CB);

    Tacka C1B1;
    vektorski_proizvod(C1, B1, C1B1);

    Tacka P;
    vektorski_proizvod(CB, C1B1, P);

    // -----------------------------

    Tacka B1A1;
    vektorski_proizvod(B1, A1, B1A1);

    Tacka C1D1;
    vektorski_proizvod(C1, D1, C1D1);

    Tacka Q;
    vektorski_proizvod(B1A1, C1D1, Q);

    // -----------------------------

    Tacka PA;
    vektorski_proizvod(P, A, PA);

    Tacka CQ;
    vektorski_proizvod(C, Q, CQ);

    Tacka D;
    vektorski_proizvod(PA, CQ, D);

    cout << "(" << D.x/D.z << ", " << D.y/D.z << ")" << endl;

    // izlaz: (486.739, 184.261)
}

int main(){

    Tacka A, B, C, A1, B1, C1, D1;

    A.x = 670; A.y = 267;
    B.x = 331; B.y = 549;
    C.x = 138; C.y = 359;
    A1.x = 717; A1.y = 131;
    B1.x = 330; B1.y = 372;
    C1.x = 101; C1.y = 196;
    D1.x = 507; D1.y = 58;

    nevidljivo(A, B, C, A1, B1, C1, D1);
}
