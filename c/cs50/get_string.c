#include <stdio.h>
#include <string.h>

typedef char *string;

const char* get_string(char* input){
  char str[20];
  printf("%s", input);
  scanf("%s", str);
  return str;
}
int main() {
  const char* something = get_string("Enter name: ");
  printf("%s", something); 
  return 0;
}