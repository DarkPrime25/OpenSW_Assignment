#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int mysystem(const char* command){
    pid_t pid;
    int status;
    
    if (command == NULL){
        return 1;
    }
    pid = fork();
    if (pid < 0){
        return -1;
    }
    if (pid == 0){
        execl("/bin/sh", "sh", "-c", command, (char*)NULL);
        exit(1);
    }
    else {
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        }
    }
    return -1;
}

int main(void){
    // system("ls -l | wc -l");
    // system("find . -name '*.c'");

    mysystem("ls -l | wc -l");
    mysystem("find . -name '*.c'");

    printf("Good bye~\n");
    return 0;
}