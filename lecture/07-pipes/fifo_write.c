#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h> // Added for errno

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s message\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int ret = mkfifo("/tmp/fifo_test", S_IRUSR | S_IWUSR);
    if (ret == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    int fd = open("/tmp/fifo_test", O_WRONLY);
    write(fd, argv[1], strlen(argv[1]));
    close(fd);
    unlink("/tmp/fifo_test");
    exit(EXIT_SUCCESS);
}
