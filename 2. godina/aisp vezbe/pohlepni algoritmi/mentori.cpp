/* Šahisti jednog tima se spremaju za dolazeće turnire. Odlučeno 
 * je da šahisti sa boljim rejtingom pomažu onim sa lošijim rejtingom, 
 * tako što će im biti mentori. Da bi jedan šahista mogao da bude
 * mentor drugome, njegov rejting treba da bude bar dva puta veći 
 * nego rejting prvoga. Ako su poznati rejtinzi svih šahista, napisati
 * program koji određuje koji je najveći broj parova učenik-mentor koji
 * se može formirati, pri čemu šahista može istovremeno biti i učenik i
 * mentor, ali ni jedan šahista ne može da ima dva učenika niti dva mentora. */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
 
  vector<int> rejting(n);
  for(int i = 0; i < n; i++)
    cin >> rejting[i];

  sort(begin(rejting), end(rejting));

  int brojParova = 0;
  vector<bool> jeMentor(n, false);
  int mentor = 1;

  for(int ucenik = 0; mentor < n; ucenik++)
    while(mentor < n){
      if(!jeMentor[mentor] && rejting[mentor] >= 2 * rejting[ucenik]){
	brojParova++;
	jeMentor[mentor] = true;
	break;
      }
      else
	mentor++;
    }
  
  cout << brojParova << endl;

  return 0;
}