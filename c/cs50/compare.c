//compare two string

#include <stdio.h>
#include <string.h>
#include "customio.h"
//#include "cs50.h"

int main(void)
{
  //compare int numbers
  int i = get_int("num 1: ");
  int j = get_int("num 2: ");

  if (i == j)
  {
    printf("Same\n");
  }
  else
  {
    printf("Different\n");
  }

  //printf("address for s:\t%p\n", i);
  //printf("address for t:\t%p\n", j);

  //compare string
  char *s = get_string("string 1: ");
  char *t = get_string("string 2: ");

  if (s == t)
  {
    printf("Same\n");
  }
  else
  {
    printf("Different\n");
  }

  printf("address for s:\t%p\n", s);
  printf("address for t:\t%p\n", t);

  //not working yet
  if (strcmp(s,t) == 0)
  {
    printf("Same\n");
  }
  else
  {
    printf("Different\n");
  }
}