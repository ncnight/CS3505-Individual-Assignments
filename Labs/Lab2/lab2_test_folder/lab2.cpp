#include <iostream>
using namespace std;

class Cat {
  int lives; // Cats have 9 lives
public:
 // Construct a Cat with the number of lives
 Cat(int startLives) : lives{startLives} {
 // nothing else to do
 }

 void reportLives() {
   cout << lives << endl;
 }

 void loseLife() {
   lives--;
 }
};

int main() {
 Cat mittens(9);
 mittens.reportLives();
 mittens.loseLife();
 mittens.loseLife();
 cout << "Lives should be 7. Actual: ";
 mittens.reportLives();
 for(int i = 0; i < 7; i++) {
   mittens.loseLife();
 }

 cout << "Lives should be 0. Actual: ";
 mittens.reportLives();

}
