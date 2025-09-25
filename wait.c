#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

int main() {

  pid_t pid = fork();
  int wstatus = 0;

  if (pid == 0) {
    if (waitpid(pid, &wstatus, 0) == -1) {
      perror("waitpid");
      exit(EXIT_FAILURE);
    }

    if (WIFEXITED(wstatus)) {
      printf("Child done with exit status: %d\n", WEXITSTATUS(wstatus));

    } else {
      printf("Child did not exit normally.\n");
    }
  } else {
    int *bogus = NULL;
    int a = *bogus;
    // *(volatile int *) = NULL;
    if (execl("/usr/bin/ls", "/usr/bin/ls", "bonkers", "-a", "-l", NULL) ==
        -1) {
      perror("execl");
      exit(EXIT_FAILURE);
    }
  }
  return 0;
}
