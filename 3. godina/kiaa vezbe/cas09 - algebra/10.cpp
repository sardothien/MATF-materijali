/* Na Kosutnjaku je tokom uranka odrzano takmicenje za najbolju
 * kobasicu. Mesar Sremac je napravio N jednakih kobasica i 
 * potrebno je da ih ravnomerno podeli na K delova tako da svaki
 * od K clanova zirija dobije jednaku kolicinu kobasice. Da bi
 * podela bila sto kvalitetnija, broj rezova kobasice mora biti
 * sto manji. Konstruisati algoritam slozenosti O(log(N+K)) koji
 * racuna najmanji potreban ukupan broj rezova. */

#include<iostream>
using namespace std;

int nzd(int n, int k){
    if(k == 0)
        return n;
    
    return nzd(k, n%k);
}

int main(){
    
    int n, k;
    cin >> n >> k;
    
    cout << nzd(n, k) << endl;
    
    return 0;
}
