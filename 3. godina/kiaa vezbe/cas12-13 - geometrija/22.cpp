/* Dato je n pravougaonika u koordinatnom sistemu sa 
 * stranicama paralelnim osama. Svaki pravougaonik je 
 * dat koordinatom donjeg-levog i koordinatom gornjeg-desnog 
 * temena. Naći površinu njihovih preseka. Prvi red standardnog 
 * ulaza sadrži ceo broj n. Potom se u narednih n redova
 * učitava po četiri broja x1, y1, x2 (x1 < x2) i y2 (y1 < y2).
 * Svaka koordinata je ceo broj iz intervala [0, 100 000].
 * Prvi red standardnog izlaza treba da sadrži jedan ceo broj
 * koji predstavlja površinu preseka datih pravougaonika. */
#include<iostream>
using namespace std;

/* Ukupna povrsina pravougaonika koji se seku:
 int ukupnaPovrsina(Tacka l1, Tacka r1, Tacka l2, Tacka r2){ 
  
    int p1 = abs(l1.x - r1.x) * abs(l1.y - r1.y); 
  
    int p2 = abs(l2.x - r2.x) * abs(l2.y - r2.y); 
  
    int presek = (min(r1.x, r2.x) - max(l1.x, l2.x)) *  
                 (min(r1.y, r2.y) - max(l1.y, l2.y)); 
  
    return (p1 + p2 - presek); 
} 
 */

int main(){
    
    long n, i;
    long dx, dy, gx, gy;
    long x1, x2, y1, y2;
    
    cin >> n;
    cin >> dx >> dy >> gx >> gy;
    
    for(int i = 2; i <= n; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        
        if(x1 > dx)
            dx = x1;
        if(x2 < gx)
            gx = x2;
        if(y1 > dy)
            dy = y1;
        if(y2 < gy)
            gy = y2;
        
        if((gy - dy < 1) || (gx - dx < 1)){
            cout << "0" << endl;
            return 0;
        }
    }
    
    cout << (gy-dy) * (gx-dx) << endl;    
    
    return 0;
}
