/* Напиши програм који израчунава збир природних бројева
 * од 1 до n по датом модулу m. */

#include<iostream>
using namespace std;

int main(){
    
    int n, m;
    cin >> n >> m;
    
    int zbir;
    
    if(n % 2 == 0)
        zbir = (((n/2) % m) * (n+1) % m) % m;
    else
        zbir = ((n % m) * ((n+1)/2) % m) % m;
    
    cout << zbir << endl;
    
    return 0;
}
