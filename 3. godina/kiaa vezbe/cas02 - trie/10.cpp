/* DNK sekvence se predstavljaju niskama koje se sastoje od 
 * karaktera c, t, a, g. U programu se odrzava skup podsekvenci 
 * jedne date genetske sekvence. Program podrzava tri operacije: 
 * ubacivanje podsekvence u skup, izbacivanje podsekvence iz skupa
 * i ispitivanje da li se podsekvenca nalazi u skupu. */
// pomocu postojece biblioteke

#include<iostream>
#include<unordered_set>
using namespace std;


int main(){
    
    // broj upita
    int n;
    cin >> n;
    
    unordered_set<string> niske; 
    
    for(int i = 0; i < n; i++){
        string naredba, niska;
        cin >> naredba >> niska;
        
        if(naredba == "ubaci")
            niske.insert(niska);
        else if(naredba == "izbaci")
            niske.erase(niska);
        else if(naredba == "trazi"){
            if(niske.find(niska) != niske.end())
                cout << "da" << endl;
            else
                cout << "ne" << endl; 
        }
    }        
    
    return 0;
}
