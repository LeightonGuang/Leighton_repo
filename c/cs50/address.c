//print out the address of variable n
#include <stdio.h>
#include "customio.h"

int main(void)
{
  //with customio header file with typedef string
  string name = "Leighton";
  //
  int n = 50;
  //declaring a pointer
  int *p = &n;
  //string in c
  char *s = "HI!";
  
  //
  printf("my name: \t%s\n", name);
  // & the address
  printf("address n:\t%p\n", &n);
  // * goes to that address to get the value(dereference the address)
  printf("value n:\t%i\n", *&n);
  //
  printf("address n:\t%p\n", p);
  //goes to the pointer
  printf("value n:\t%i\n", *p);

  printf("string s:\t%s\n", s);

  printf("pointer s\t%p\n", s);

  printf("pointer of first char in string s:\t%p\n", &s[0]);

  printf("pointer of second char in string s:\t%p\n", &s[1]);

  printf("%c\n", *s);
  
  printf("%c\n", *(s+1));

  printf("%c\n", *(s+2));
}
