#include <stdio.h>

int main(void) {
  int i;
  int numbers[5] = {1,2,3,4,5};

  printf("Element \t Address \t\t\t Value \n");

  for(i = 0; i < 5; i++){
    printf("numbers[%d] \t %p \t %d \n", i, &numbers[i], numbers[i]);
  }

  printf("\narray names are pointers to the first element of list\n");
  printf("numbers \t %p \n", numbers);

  printf("\ndereferenceing\n");
  printf("*numbers \t %d \n", *numbers);

  printf("\npointer of numbers[2]\n");
  printf("&numbers[2] \t %p \n", &numbers[2]);

  printf("\n*(numbers+2) \t %p \n", numbers+2);

  return 0;
}
