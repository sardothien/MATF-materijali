/* Odrediti cele brojeve x i y tako da vazi
 * d = nzd(a, b) = x*a + y*b. 
 * Npr. 3 = 33x + 24y 
 * O(log(a+b)) */

#include<iostream>
using namespace std;

int nzdProsireni(int a, int b, int& x, int& y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    
    int x1, y1;
    
    int nzd = nzdProsireni(b, a%b, x1, y1);
    x = y1;
    y = x1 - (a/b)*y1;
    
    return nzd;
}

int main(){
    
    int a, b;
    cin >> a >> b;
    
    int x, y;
    int d = nzdProsireni(a, b, x, y);
    
    cout << x << ", " << y << endl;
    
    return 0;
}
