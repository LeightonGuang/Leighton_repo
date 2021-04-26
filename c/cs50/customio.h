//string as a data type
typedef char *string;

int get_int(char* input){
  int number;
  printf("%s", input);
  scanf("%d", &number);
  return number;
}

 char* get_string(char* input){
  string str;
  printf("%s", input);
  scanf("%s", &str);
  return str;
}