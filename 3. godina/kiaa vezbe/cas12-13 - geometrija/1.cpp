/* Izracunaj skalarni proizvod dva vektora. */

#include<iostream>
#include<vector>
using namespace std;

int skalarniProizvod(vector<int>& a, vector<int>& b){
    int rez = 0;
    
    for(int i = 0; i < a.size(); i++)
        rez += a[i]*b[i];
    
    return rez;
}

int main(){
    
    vector<int> a = {2, 2};
    vector<int> b = {3, 4};
    
    cout << skalarniProizvod(a, b) << endl;
    
    return 0;
}
