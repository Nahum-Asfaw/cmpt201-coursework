#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int fd = open("/tmp/fifo_test", O_RDONLY);
    char buf[100];
    read(fd, buf, 100);
    printf("Received: %s\n", buf);
    close(fd);
    exit(EXIT_SUCCESS);
}
