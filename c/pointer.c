#include <stdio.h>

//variables that store addresses are pointers

int main(void) {
  //variable tuna to 19
  int tuna = 19;

  printf("Address \t\t Name \t Value \n");

  int * pTuna = &tuna;

  printf("%p \t %s \t %d \n", pTuna, "tuna", tuna);
  printf("%p \t %s \t %p \n", &pTuna, "pTuna", pTuna);

  return 0;
}
