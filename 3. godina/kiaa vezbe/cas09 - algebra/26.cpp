/* Напиши програм који испитује да ли је унети природан број 
 * прост (већи је од 1 и нема других делилаца осим 1 и самог себе). */

#include <iostream>
using namespace std;

bool prost(int n){
    if(n == 1 || (n % 2 == 0 && n != 2) || (n % 3 == 0 && n != 3))
        return false;
    
    for(int k = 1; (6*k - 1) * (6*k - 1) <= n; k++)
        if(n % (6 * k + 1) == 0 || n % (6 * k - 1) == 0)
            return false;
    
    return true;
}

int main(){
    
    int n;
    cin >> n;
    
    cout << (prost(n) ? "DA" : "NE") << endl;
    
    return 0;
}
