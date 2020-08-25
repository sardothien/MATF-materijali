/* Dat je prost mnogougao P i tacka Q. Da li je tacka Q
 * u ili van mnogougla P? */

#include<iostream>
#include<vector>
using namespace std;

struct Tacka {
    double x;
    double y;
};

bool tackaUMnogouglu(vector<Tacka>& tacke, Tacka A){
    
    int n = tacke.size();
    if(n < 3)
        return false;
    
    bool uMnogouglu = false;
    
    for(int i = 0; i < n; i++){
        int j = (i+1) % n; // naredno teme
        if(A.x > min(tacke[i].x, tacke[j].x) && A.x < max(tacke[i].x, tacke[j].x) &&
           tacke[i].y + (tacke[j].y - tacke[i].y) / (tacke[j].x - tacke[i].x)*(A.x - tacke[i].x) < A.y)
            uMnogouglu = !uMnogouglu;
    }
    
    return uMnogouglu;
}

int main(){
  
    vector<Tacka> tacke = {
        {0, 0}, {10, 1}, {12, 12}, {2, 10}
    };
    
    Tacka A = {5, 8};
    
    if(tackaUMnogouglu(tacke, A))
        cout << "u mnogouglu" << endl;
    else
        cout << "van mnogougla" << endl;
    
    
    return 0;
}
