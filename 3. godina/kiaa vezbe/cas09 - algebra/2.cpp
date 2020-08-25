/* Za dati broj n izracunati ukupan broj njegovih delilaca. */
// O(sqrt(n))

#include<iostream>
using namespace std;

int brojDelilaca(int n){
    int br = 0;
    
    for(int i = 1; i*i <= n; i++){
        if(n % i == 0){
            if(i*i == n)
                br++;
            else
                br += 2;
        }
    }
    
    return br;
}

int main(){
    
    int n;
    cin >> n;
    
    cout << brojDelilaca(n) << endl;    
    
    return 0;
}
