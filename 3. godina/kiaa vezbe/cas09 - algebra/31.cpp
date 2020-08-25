/* Са стандардног улаза се уносе степен n и реални коефицијенти полинома
 * y = a_n·x^n + a_n−1·x^n−1 +...+ x·a_1 + a_0. Напиши програм који 
 * израчунава вредност тог полинома у k равномерно распоређених тачака
 * интервала [p, q]. */

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

const int N_MAX = 100;

double VrednostPolinoma(double a[], int n, double x){
    double y = 0.0;
    
    for(int i = 0; i <= n; i++)
        y += a[i] * pow(x, i);
    
    return y;
}

int main(){
    
    int n;
    cin >> n;
    
    double a[N_MAX];
    
    for(int i = n; i >= 0; i--)
        cin >> a[i];
    
    int k;
    double p, q;
    cin >> k >> p >> q;
    
    double h = (q - p) / (k - 1);
    double x;
    
    int i;
    for(i = 0, x = p; i < k; i++, x += h)
        cout << fixed << showpoint << setprecision(2) << VrednostPolinoma(a, n, x) << endl;
    
    return 0;
}
