#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int get_random() {
  int x;
  x = rand() % 12 + 1;
  return x;
}

int main(int argc, char *argv[]) {
  int balance;
  balance = 1000;
  while (1) {
    int user_number;
    int amount;
    printf("Your total balance: %d\n", balance);

    printf("Enter amount you want to bet: \n");
    scanf("%d", &amount);
    if (amount > balance) {
      printf(
          "Your amount exides you balance please enter right amount to bet.\n");
      continue;
    }

    balance = balance - amount;
    printf("Enter dice number you want to guess: \n");
    fflush(stdout);
    scanf("%d", &user_number);

    if (user_number > 12) {
      printf("You can't give dice number to grater then 12\n");
      balance += amount;
      continue;
    }

    int dice_number = get_random();
    srand(time(NULL));

    printf("Dice result: %d\n", dice_number);
    if (user_number == dice_number) {
      printf("You won game and you get 3x amount you bet.\n");
      balance = amount * 4 + balance;
    } else if (user_number != dice_number) {
      printf("You loss!!\n");
    }

    if (balance == 0) {
      printf("Your balance got 0 and quiting game...\n");
      return 0;
    }
  }
  return 0;
}
