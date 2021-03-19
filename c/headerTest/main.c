#include <stdio.h>
#include <stdlib.h>
#include "date.h"

int main(void) {
  Date leighton_date = {17,4,2000};
  printf("Leighton: %d/%d/%d\n", leighton_date.day, leighton_date.month, leighton_date.year);

  char leighton_birthday[] = "17/04/2000" ;
  printf("Leighton string: %s\n", leighton_birthday);

  char *day = strtok(leighton_birthday,"/");
  printf("day: %s\n", day);
  char *month = strtok(leighton_birthday,"");
  printf("month: %s\n", month);
  char *year = strtok(leighton_birthday,"/");
  printf("year: %s\n", year);

  Date luther_date = {17,8,1960};

  char luther_birthday[] = "";
  printf("Luther: %d/%d/%d\n", luther_date.day, luther_date.month, luther_date.year);
  return 0;
}
