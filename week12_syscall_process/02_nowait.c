#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    pid_t child_pid;
    child_pid = fork();

    if(child_pid == 0){
        sleep(1);
        printf("Child process PID: %lu\n", (unsigned long)getpid());
        printf("Child process PPID: %lu\n", (unsigned long)getppid());
        return 7;
    }
    else{
        printf("Parent process PID: %lu\n", (unsigned long)getpid());
        printf("Parent process PPID: %lu\n", (unsigned long)getppid());

        exit(0);
    }
    return 0;
}