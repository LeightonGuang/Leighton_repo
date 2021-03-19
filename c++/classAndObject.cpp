#include <iostream>
using namespace std;
//classes are an easy way to group all your functions and varaibles

//declaring class
class SomeClass{
  //you can use it outside the class
  public:
    void setName(string n){
      name = n;
    }

    string getName(){
      return name;
    }

  //private so you can use it outside the class
  private:
    string name;
};


int main()
{
  SomeClass theObj;
  //theObj.printSomething();
  //cout << theObj.returnInt(69) << endl;
  theObj.setName("Leighton");
  cout << theObj.getName() << endl;
  return 0;
}
