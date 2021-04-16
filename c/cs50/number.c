//linear search in code
#include <stdio.h>

int main(void)
{
  int numbers[] = {4,6,8,2,7,5,0};

  for (int i = 0; i<7; i++)
  {
    if (numbers[i] == 0)      //if found 0
    {
      printf("Found\n");      //tell user found

      return 0;
    }
  }
  printf("Not found\n");
  return 1;
}
