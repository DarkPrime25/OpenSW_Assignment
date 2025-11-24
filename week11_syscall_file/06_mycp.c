#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#define BUF_SIZE 32
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s [source file] [destination file1] ...\n", argv[0]);
        exit(0);
    }
    int src_fd = open(argv[1], O_RDONLY);
    if (src_fd == -1) {
        perror("Open source error");
        exit(1);
    }
    int num_dest = argc - 2;
    int *dest_fds = (int*)malloc(sizeof(int) * num_dest);
    for (int i = 0; i < num_dest; i++) {
        dest_fds[i] = open(argv[i + 2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (dest_fds[i] == -1) {
            perror("Open dest error");
            exit(1); 
        }
    }
    char buf[BUF_SIZE];
    ssize_t nread;
    while (1) {
        nread = read(src_fd, buf, BUF_SIZE);

        if (nread == 0) break; 
        if (nread == -1) {
            perror("Read error");
            exit(1);
        }
        for (int i = 0; i < num_dest; i++) {
            write(dest_fds[i], buf, nread);
        }
        write(1, buf, nread); 
    }
    close(src_fd);
    for (int i = 0; i < num_dest; i++) {
        close(dest_fds[i]);
    }
    free(dest_fds);
    printf("\nprogram end...\n");
    return 0;
}