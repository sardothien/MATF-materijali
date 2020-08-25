/* Напиши програм који за унети природни број n одређује
 * најмањи број m такав да је n*m потпун квадрат. */

#include<iostream>
using namespace std;

long long dopunaDoPunogKvadrata(long long n){

    long long m = 1;
    long long p = 2;

    while(p*p <= n){
        int k = 0;

        while(n % p == 0){
            n /= p;
            k++;
        }

        if(k % 2 != 0)
            m *= p;

        p++;
    }

    if(n > 1)
        m *= n;

    return m;
}

int main(){

    long long n;
    cin >> n;

    cout << dopunaDoPunogKvadrata(n) << endl;

    return 0;
}
