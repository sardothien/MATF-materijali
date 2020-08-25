/* Најмањи број који је дељив свим бројевима од 1 до 10 је број 2520.
 * Напиши програм који за дати природан број n одређује који је најмањи
 * број дељив бројевима од 1 до n. */

#include<iostream>
using namespace std;

int nzd(int a, int b){
    while(b > 0){
        int tmp = a;
        a = b;
        b = tmp % b;
    }

    return a;
}

int nzs(int a, int b){
    return (a / nzd(a, b)) * b;
}

int main(){
    
    int n;
    cin >> n;
    
    int m = 1;
    
    for(int i = 1; i <= n; i++)
        m = nzs(m, i);
    
    cout << m << endl;
    
    return 0;
}
