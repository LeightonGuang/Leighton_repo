#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "header.h"

typedef struct date Date;

struct date{
  int day, month, year;
};

int main(void) {
  char datestr[10] = "17/04/2000";

  char *pDate = malloc(8 * sizeof(char));

  Date->day = strtok(datestr, "/");
  Date->month = strtok(NULL, "/");
  Date->year = strtok(NULL, "/");

  printf("%d %d %d", Date.year, Date.month, Date.day);

  return 0;
}
