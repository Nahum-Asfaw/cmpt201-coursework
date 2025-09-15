#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
  int parentID = getppid();
  int childID = getpid();
  int startID = getpid();
  printf("Start PID=%d, parent PID= %d\n", startID, parentID);
  pid_t pid = fork();

  if (pid == 0) {
    printf("PARENT: PID=%d, child PID=%d\n", parentID, childID);
  } else {
    printf("CHILD: PID=%d, parent PID=%d\n", childID, parentID);
  }

  return 0;
}
