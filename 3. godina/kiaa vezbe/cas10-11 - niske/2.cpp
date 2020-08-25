/* Implementirati Z-algoritam. */

#include<iostream>
#include<vector>
using namespace std;

vector<int> izracunajZNiz(string& s, int n){
    
    vector<int> z(n);
    
    int l = 0, d = 0;
    
    for(int i = 1; i < n; i++){
        if(i <= d)
            z[i] = min(d-i+1, z[i-l]);
        
        while(i+z[i] < n && s[z[i]] == s[i+z[i]])
            z[i]++;
        
        if(i + z[i] - 1 > d){
            d = i + z[i] - 1;
            l = i;
        }
    }
    
    return z;
}

int main(){
    
    string niz = "CDA#ACBACDACBACBACDA";
    int n = niz.size();
    
    vector<int> z_niz = izracunajZNiz(niz, n);
    
    for(int i = 0; i < n; i++)
        cout << z_niz[i] << " ";
    cout << endl;
    
    for(int i = 0; i < n; i++)
        if(z_niz[i] == 3)
            cout << i-4 << endl;
     
    return 0;
}
