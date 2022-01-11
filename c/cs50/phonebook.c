#include <stdio.h>
#include <string.h>

typedef struct
{
  char name[10];
  char number[20];
}
person;

int main(void)
{

  person people[2];

  strcpy(people[0].name, "Brian");
  strcpy(people[0].number, "+1-123-456-7890");

  strcpy(people[1].name, "David");
  strcpy(people[1].number, "+1-987-654-3210");


  //people[0].name = "Brian";
  //people[0].number = "+1-123-456-7890";

  //people[1].name = "David";
  //people[1].number = "+1-987-654-3210";

  //char names[2][10] = {"Brian", "David"};
  //char numbers[2][20] = {"+1-123-456-7890", "+1-987-654-3210"};

  for (int i = 0; i < 2; i++)
  {
    if (strcmp(people[1].name, "David") == 0)
    {
      printf("Found %s\n", people[1].number);
      return 0;
    }
  }
  printf("Not found\n");
  return 1;
}
