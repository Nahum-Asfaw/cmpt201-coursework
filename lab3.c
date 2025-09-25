#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define SIZE = 5

void processInput(char *input, char *history) {

  if (strcmp(input, "print")) {
    printf("%s\n", history);
  }
}

void reading(char *input, char *history, size_t n) {

  while (strcmp(input, "print") == 0) {
    printf("Enter: ");
    getline(&input, &n, stdin);
  }
}

int main() {

  char input;   // lab 1 implementation
  size_t n = 0; // lab 1
  char history[5];
  int lineNum = 0;

  while (1) {

    printf("Enter: ");

    getline(&input, &n, stdin);

    history[lineNum] = input;

    printf("You entered: %c\n", input);

    if (1) {
      for (int i = 0; i < lineNum; i++) {
        printf("%c", history[i]);
      }
    }

    printf("\n");
    lineNum++;
  }

  return 0;
}
