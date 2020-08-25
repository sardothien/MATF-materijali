/* Napisati program koji odredjuje poslednje tri cifre
 * zbira i poslednje tri cifre proizvoda cetiri uneta 
 * cela broja manja od 999. */

#include<iostream>
using namespace std;

int zbir(int a, int b, int m){
    return (a+b) % m;
}

int proizvod(int a, int b, int m){
    return (a*b) % m;
}

int main(){
    
    int x, y, z, f;
    cin >> x >> y >> z >> f;
    
    cout << "Poslednje cifre zbira: " << zbir(zbir(zbir(x, y, 1000), z, 1000), f, 1000) << endl;
    cout << "Poslednje cifre proizvoda: " << proizvod(proizvod(proizvod(x, y, 1000), z, 1000), f, 1000) << endl;
    
    return 0;
}
