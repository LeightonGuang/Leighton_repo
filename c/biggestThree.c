//biggest number of the three from user

#include <stdio.h>

int main(){
  int one, two, three;

  printf("enter first number\n> ");
  scanf("%d", &one);

  printf("enter second number\n> ");
  scanf("%d", &two);

  printf("enter third number\n> ");
  scanf("%d", &three);

  if(one > two){
    if (one > three){
      printf("%d is the biggest number\n", one);
    }
  }

  if(two > one){
    if(two > three){
      printf("%d is the biggest number\n", two);
    }
  }

  if(three > one){
    if(three > two){
      printf("%d is the biggest number\n", three);
    }
  }
  return (0);
}
