#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    pid_t child_pid;
    int wstatus;
    
    if (argc < 2) {
        printf("Usage: %s <program path> [OPTION]...\n", argv[0]);
        exit(0);
    }

    child_pid = fork();

    if(child_pid == 0){
        execve(argv[1], &argv[1], NULL);
        perror("execve error");
        exit(1);
    }
    else{
        int wstatus;
        waitpid(child_pid, &wstatus, 0);
        if(WIFEXITED(wstatus)){
            printf("Child exited with status: %d\n", WEXITSTATUS(wstatus));
        }
    }
    return 0;
}