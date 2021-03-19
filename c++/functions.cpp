#include <iostream>

using namespace std;

//put the function on top so the program knows what the function is
void printSomething(int x){
  cout << "The number "<< x << endl;
}

int add(int x, int y){
  int sum = x+y;
  return sum;
}

int main() {
  printSomething(69);
  cout << add(21,69) << endl;
  return 0;
}
