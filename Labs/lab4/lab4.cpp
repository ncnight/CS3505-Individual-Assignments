#include <iostream>
using namespace std;

// int main(){
//   int vals[] {1,2,3};
//   cout << vals[3] << endl;
//   vals[3] = 1;
// }

int main() {
  int* val = new int(4);
  int* same_mem = val;

  std::cout << *val << *same_mem << std::endl;
  delete val;
}
