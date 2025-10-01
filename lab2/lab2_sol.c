// Lab 2 solution by Brian Fraser
// Do not distribute beyond the class.

#define _POSIX_C_SOURCE 200809L
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  while (true) {
    printf("Enter programs to run.\n");
    printf("> ");

    // Read user command
    char *line = NULL;
    size_t len = 0;
    if ((len = getline(&line, &len, stdin)) != -1) {

      // Strip linefeed
      line[len - 1] = '\0';
      // printf("Command will be: %s\n", line);

      // Run the command
      pid_t pid = fork();
      if (pid != 0) {

        // Parent: Wait
        pid_t wpid = waitpid(pid, NULL, 0);
        if (wpid == -1) {
          printf("ERROR waiting for PID\n");
        }
        // Should use WEXITSTATUS() to check exit status of waitpid(

      } else {

        // Child: Exec
        if (execl(line, line, NULL) == -1) {
          printf("Exec failure\n");
        }
      }
    } else {
      printf("Getline failed\n");
      exit(EXIT_FAILURE);
    }
  }
}
