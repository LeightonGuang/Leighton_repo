#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
//#include "customio.h"

int main (void)
{}
  char *s;
  char *t = malloc(strlen(s) + 1);      
  //+ 1 because of \0 in a stringa string t 

  if(t == NULL)
  {
    return 1;
  }

  printf("s: ");
  scanf("%s", s);


  strcpy(t,s);

  //string copy
  /*for (int i = 0, n = strlen(s); i<=n; i++)
  {
    t[i] = s[i];
    //same thing
    //*(t+i) = *(s+i);
  }
  */
  //error checking
  if (strlen(t) > 0)
  {
    t[0] = toupper(t[0]);
    //same thing
    //*t = toupper(*t);
  }

  printf("s: %s\n", s);
  printf("t: %s\n", t);

  free(t);
}
