#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define BUF_SIZE 128

int main(int argc, char* argv[]) {
    char buf[BUF_SIZE];
    ssize_t nread;
    if (argc != 1){
        printf("Usage: %s\n", argv[0]);
        exit(0);
    }
    while (1) {
        nread = read(0, buf, BUF_SIZE);

        if (nread == 0) {
            printf("Detected EOF (Ctrl+D)\nTerminating read loop...\n");
            break;
        }
        if (nread == -1) {
            perror("read");
            exit(1);
        }
        write(1, buf, nread);
    }
    return 0;
}