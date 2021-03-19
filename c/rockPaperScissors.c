#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(void) {
  int num;
  char guess[10], cpu_guess[10];
  char cpu_list[3][10] = {"rock", "paper", "scissors"};

  srand(time(NULL));  //seeding random using time
  num = rand() % 3;   //num from 0-2

  printf("Enter Rock, Paper or Scissors\n> ");
  scanf("%s", guess);
  printf("Player: %s\nCPU   : %s\n", guess, cpu_list[num]);

  if (strcmp(guess, cpu_list[num]) == 0){
    printf("its a tie\n");

  } else if (strcmp(guess, "rock") == 0){
    if(strcmp(cpu_list[num], "paper") == 0){
      printf("you lost\n");
   } else{
     printf("you won\n");
   }

  } else if (strcmp(guess, "paper") == 0){
    if(strcmp(cpu_list[num], "scissors") == 0){
     printf("you lost\n");
   } else{
     printf("you won\n");
   }

  } else if (strcmp(guess, "scissors") == 0){
    if(strcmp(cpu_list[num], "rock") == 0){
     printf("you lost\n");
   } else{
     printf("you won\n");
   }
  }

  return 0;
}
