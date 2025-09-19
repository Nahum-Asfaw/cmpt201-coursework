#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int arg_count, char *args[]) {

  for (int i = 0; i < arg_count; i++) {
    printf("args[%d] = %s\n", i, args[i]);
  }
  pid_t pid = fork();
  if (pid == 0) {
    printf("Parent running 'ls -a':\n");
    execl("/bin/ls", "/bin/ls",
          "/home/cmpt201/cmpt201-coursework/lecture/02-process", "-a",
          (char *)NULL);
  } else {
    printf("Child running 'ls -a -l -h':\n");
    execl("/bin/ls",
          "/bin/ls"
          "/home/cmpt201/cmpt201-coursework/lecture/02-process",
          "-a", "-l", "-h", (char *)NULL);
  }
}
