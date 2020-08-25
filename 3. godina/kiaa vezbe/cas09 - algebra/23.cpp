/* Напиши програм који израчунава степен по модулу, тј. за
 * дате ројеве a, n и m израчунава a^n mod m. */

#include<iostream>
using namespace std;

int stepen(int a, int n, int m){
    int s = 1;
    
    while(n > 0){
        if((n & 1) == 0){
            a = (a*a) % m;
            n = n >> 1;
        }
        else{
            s = (s * a) % m;
            n--;
        } 
    }
    
    return s;
}

int main(){
    
    int a, n, m;
    cin >> a >> n >> m;
    
    cout << stepen(a, n, m) << endl;
        
    return 0;
}
