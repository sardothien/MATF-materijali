/* Konstruisati algoritam koji pronalazi broj pojavljivanja broja 
 * x koji deli sve brojeve iz intervala [a, b] u datom nizu A. 
 * Broj x takodje pripada intervalu [a, b]. */

#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

struct cvor {
    int nzd;
    int br;
    int min_element;
};

void formiraj(const vector<int>& niz, vector<cvor>& drvo, int k, int x, int y){
    if(x == y){
        drvo[k].min_element = niz[x];
        drvo[k].nzd = niz[x];
        drvo[k].br = 1;
    }
    else{
        int sr = (x+y) / 2;
        
        formiraj(niz, drvo, 2*k, x, sr);
        formiraj(niz, drvo, 2*k+1, sr+1, y);
        
        drvo[k].nzd = __gcd(drvo[2*k].nzd, drvo[2*k+1].nzd);
        
        if(drvo[2*k].min_element < drvo[2*k+1].min_element){
            drvo[k].min_element = drvo[2*k].min_element;
            drvo[k].br = drvo[2*k].br;
        }
        else if(drvo[2*k].min_element > drvo[2*k+1].min_element){
            drvo[k].min_element = drvo[2*k+1].min_element;
            drvo[k].br = drvo[2*k+1].br;
        }
        else{
            drvo[k].min_element = drvo[2*k].min_element;
            drvo[k].br = drvo[2*k].br + drvo[2*k+1].br;
        }
    }
}

cvor brojKojiDeliSve(const vector<cvor>& drvo, int k, int x, int y, int a, int b){
    
    cvor rez;
    
    if(b < x || a > y){
        rez.nzd = 0;
        rez.min_element = 0;
        rez.br = 0;
        return rez;
    }
    
    if(a <= x && b >= y){
        rez.nzd = drvo[k].nzd;
        rez.min_element = drvo[k].min_element;
        
        if(rez.min_element != rez.nzd)
            rez.br = 0;
        else
            rez.br = drvo[k].br;
        
        return rez;
    }
    
    int sr = (x+y) / 2;
    
    cvor levo = brojKojiDeliSve(drvo, 2*k, x, sr, a, b);
    cvor desno = brojKojiDeliSve(drvo, 2*k+1, sr+1, y, a, b);
    
    if(levo.nzd && desno.nzd){
        rez.nzd = __gcd(levo.nzd, desno.nzd);
        int minimum = min(levo.min_element, desno.min_element);
        
        if(rez.nzd != minimum){
            rez.nzd = 0;
            rez.br = 0;
            rez.min_element = 0;
        }
        else{
            if(levo.min_element == desno.min_element){
                rez.min_element = levo.min_element;
                rez.br = levo.br + desno.br;
            }
            else if(levo.min_element < desno.min_element){
                rez.min_element = levo.min_element;
                rez.br = levo.br;
            }
            else{
                rez.min_element = desno.min_element;
                rez.br = desno.br;
            }
        }
        
        return rez;
    }
    else if(levo.nzd)
        return levo;
    else
        return desno;
}

int main(){
    
    vector<int> niz = {
        5, 2, 3, 2, 4, 8, 6, 4, 7, 8 
    };
    
    int n = niz.size();
    int visina = ceil(log2(n));
    int velicina = 2*pow(2, visina);
    
    vector<cvor> drvo(velicina);
    
    formiraj(niz, drvo, 1, 0, n-1);
    
    int a, b;
    cin >> a >> b;    
    
    cvor rez = brojKojiDeliSve(drvo, 1, 0, n-1, a, b);
    cout << rez.br << " " << rez.nzd << " " << rez.min_element << endl; 
    
    return 0;
}
