#include <stdio.h>

int get_int(char* input){
  int number;
  printf("%s", input);
  scanf("%d", &number);
  return number;
}

int main(void){
  int n;
  do{
    n = get_int("Width: ");
  }
  while (n < 1);
  for (int i = 0; i < n; i++){
    printf("?");
  }
  printf("\n");
}
