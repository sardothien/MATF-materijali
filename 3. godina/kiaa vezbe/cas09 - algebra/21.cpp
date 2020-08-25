/* Претпоставимо да приликом исказивања времена за сате користимо само
 * бројеве од 1 до 12. Тако за 17:45 кажемо 5:45, а за 0:32 кажемо да 
 * је 12:32. Ако је познат број сати и минута такав да је број сати у 
 * опсегу од 0 до 23, а минута од 0 до 59, исказати то време тако да је
 * број сати у опсегу 1 до 12. */

#include<iostream>
using namespace std;

int main(){
    
    int sat, minut;
    cin >> sat >> minut;
    
    cout << (sat == 0 ? 12 : sat % 12) << ":" << minut << endl;
    
    return 0;
}
