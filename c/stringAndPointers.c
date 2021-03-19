#include <stdio.h>

int main(void) {

  char name1[] = "Leighton";    //name of the array is constant
  char * name2 = "Peter";       //pointer to a string is a variable

  puts(name2);

  name2 = "Kei";      //stores the address of something

  puts(name2);

  return 0;
}
