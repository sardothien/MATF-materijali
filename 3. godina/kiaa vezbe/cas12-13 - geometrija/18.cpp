/* Ispitati da li se dva pravougaonika presecaju. */

#include<iostream>
#include<cmath>
using namespace std;

struct Tacka {
    int x, y;
};

// Svaki pravougaonik je dat sa 2 dijagonalne tacke
bool presek(Tacka A1, Tacka B1, Tacka A2, Tacka B2){
    if(A1.x > B2.x || A2.x > B1.x)
        return false;
    if(A1.y < B2.y || A2.y < B1.y)
        return false;
    
    return true;
}

int main(){
    
    Tacka A1 = {0, 10}, B1 = {10, 0};
    Tacka A2 = {5, 5}, B2 = {15, 0};
    
    if(presek(A1, B1, A2, B2))
        cout << "Presecaju se" << endl;
    else
        cout << "Ne presecaju se" << endl;    
    
    return 0;
}
