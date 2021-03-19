#include <stdio.h>

int main(void) {
  int num, result, i;

  printf("please enter a number\n> ");
  scanf("%d", &num);

  for (i = 1; i <= 10; ++i){
    result = num * i;
    printf("%d x %d = %d\n", num, i, result);
  }
  return 0;
}
