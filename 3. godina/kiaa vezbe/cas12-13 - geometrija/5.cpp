/* Date su tri tacke svojim koordinatama. Utvrditi da li 
 * su one kolinearne. */

#include<iostream>
using namespace std;

struct Tacka {
    int x;
    int y;
};

bool kolinearne(Tacka A, Tacka B, Tacka C){
    if((B.y-A.y)*(C.x-A.x) == (B.x-A.x)*(C.y-A.y))
        return true;
    else 
        return false;
}

int main(){
    
    Tacka A, B, C;
    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;
    
    if(kolinearne(A, B, C))
        cout << "jesu" << endl;
    else 
        cout << "nisu" << endl;
    
    return 0;    
}
