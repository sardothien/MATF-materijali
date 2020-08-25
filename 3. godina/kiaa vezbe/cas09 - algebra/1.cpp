/* Za dati broj n izracunati sumu svih njegovih delilaca. */
// O(sqrt(n))

#include<iostream>
#include<cmath>
using namespace std;

int sumaDelilaca(int n){
    int suma = 0;
    
    for(int i = 1; i <= sqrt(n); i++){
        if(n % i == 0){
            if(i != sqrt(n))
                suma += (i + n/i);
            else
                suma += i;
        }
    }
    
    return suma;
}

int main(){
    
    int n;
    cin >> n;
    
    cout << sumaDelilaca(n) << endl;
    
    return 0;
}
