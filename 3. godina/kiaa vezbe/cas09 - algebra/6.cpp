/* Izracunati vrednost Ojlerove funkcije za sve vrednosti
 * manje ili jednake n. */
// O(nlognlogn)

#include<iostream>
#include<vector>
using namespace std;

void ojler(int n){
    
    vector<int> ojler(n+1);
    
    for(int i = 1; i <= n; i++)
        ojler[i] = i;
    
    for(int p = 2; p <= n; p++){
        if(ojler[p] == p){
            ojler[p] = p-1;
            
            for(int i = 2*p; i <= n; i += p)
                ojler[i] = (ojler[i] / p) * (p - 1);
        }
    }
    
    for(int i = 1; i <= n; i++)
        cout << "fi(" << i << ") = " << ojler[i] << endl;
}

int main(){
    
    int n;
    cin >> n;
    
    ojler(n);
    
    return 0;
}
