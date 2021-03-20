#include <iostream>

using namespace std;

//put the function above the main
void printSomething(int x){     //void means not to return anything in function
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
