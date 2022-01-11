#include <stdio.h>

char get_string(char* input)
{
  char string[10];
  printf("%s", input);
  scanf("%s", string);
  return 0;
}

int main(void)
{
  char s;
  s = get_string("Input: ");
  printf("Output: ");
  for (int i = 0; s != '\0'; i++)
  {
    printf("%c", s);
  }
  printf("\n");
  return 0;
}
