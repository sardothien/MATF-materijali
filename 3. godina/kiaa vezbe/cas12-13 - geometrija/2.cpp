/* Izracunaj vektorski proizvod dva vektora. */

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void vektorskiProizvod(vector<int>& a, vector<int>& b, vector<int>& rez){
    rez[0] = a[1]*b[2] - a[2]*b[1];
    rez[1] = a[2]*b[0] - a[0]*b[2];
    rez[2] = a[0]*b[1] - a[1]*b[0];
}

int main(){
    
    vector<int> a = {3, 3, -4};
    vector<int> b = {1, -2, 5};
    
    vector<int> rez(3);
    
    vektorskiProizvod(a, b, rez);
    
    for(int i = 0; i < 3; i++)
        cout << rez[i] << " ";
    cout << endl;
    
    
    return 0;
}
