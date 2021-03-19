#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char y[10] = "Leighton";
  char *x = malloc(10);
  x = "Leighton";
  printf("Variable \t Address\n");
  printf("%s \t %p\n", x, &x);
  printf("%s \t %p\n", y, &y);
  free (x);
  return 0;
}
