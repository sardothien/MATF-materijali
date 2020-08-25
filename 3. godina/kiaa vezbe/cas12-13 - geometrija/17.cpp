/* Neka je dato n tačaka u ravni. Proveriti da li postoje 
 * neke 4 tačke koje formiraju kvadrat. */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Tacka {
    int x, y;
};

bool poredi(const Tacka &p1, const Tacka &p2){
    return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

ostream &operator<<(ostream &out, Tacka &p){
  out << p.x << " " << p.y << " ";
  return out;
}

void nadjiKoordinate(const Tacka &A, const Tacka &B, Tacka &C, Tacka &C1, Tacka &D, Tacka &D1){
    int dx = B.x - A.x;
    int dy = B.y - A.y;
    
    C.x = B.x + dy;
    C.y = B.y - dx;
    
    C1.x = B.x - dy;
    C1.y = B.y + dx;
    
    D.x = A.x + dy;
    D.y = A.y - dx;
    
    D1.x = A.x - dy;
    D1.y = A.y + dx;
}

bool nadjiTemena(vector<Tacka> &tacke, const Tacka &C, const Tacka &C1, const Tacka &D, const Tacka &D1){
    return (binary_search(tacke.begin(), tacke.end(), C, poredi) 
         && binary_search(tacke.begin(), tacke.end(), D, poredi)) ||
           (binary_search(tacke.begin(), tacke.end(), C1, poredi) 
         && binary_search(tacke.begin(), tacke.end(), D1, poredi));
}

bool postojiKvadrat(vector<Tacka> &tacke){
    
    sort(tacke.begin(), tacke.end(), poredi);
    int n = tacke.size();
    
    Tacka C, D, C1, D1;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            if(i == j)
                continue;
            
            nadjiKoordinate(tacke[i], tacke[j], C, C1, D, D1);
            
            if(nadjiTemena(tacke, C, C1, D, D1))
                return true;
        }
        
    return false;
}

int main(){
    
    vector<Tacka> tacke = { 
        {0, 3}, {2, 2}, {6, 4}, {1, 1}, 
        {2, 1}, {2, 5}, {3, 0}, {0, 0}, {3, 3} 
    };

    cout << boolalpha << postojiKvadrat(tacke) << endl;
    
    return 0;
}
