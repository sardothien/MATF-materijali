/* Dat je broj n. Rastaviti ga na proste cinioce. */
// O(nlogn)

#include<iostream>
#include<vector>
using namespace std;

#define MAX (1000)
vector<int> najmanjiCinilac(MAX);

void eratosten(){
    for(int i = 1; i < MAX; i++)
        najmanjiCinilac[i] = i;
    
    for(int d = 2; d*d <= MAX; d++)
        if(najmanjiCinilac[d] == d)
            for(int i = d+d; i <= MAX; i += d)
                if(najmanjiCinilac[i] == i)
                    najmanjiCinilac[i] = d;
}

void ispisiProste(int n){
    while(n != 1){
        cout << najmanjiCinilac[n] << " ";
        n /= najmanjiCinilac[n];
    }
    cout << endl;
}

int main(){
    
    int n;
    cin >> n;
    
    eratosten();
    ispisiProste(n);    
    
    return 0;
}
