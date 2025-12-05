#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void sigint_handler(int sig){
    printf("\n[SIGINT handler]\n");
    pid_t pid = fork();
    if (pid == 0) { 
        char *argv[] = {"ls", NULL};
        execve("/usr/bin/ls", argv, NULL);
        exit(1); 
    } else { 
        wait(NULL); 
    }
}

void sigquit_handler(int sig){
    printf("\n[SIGQUIT handler]\n");
    pid_t pid = fork();
    if (pid == 0) {
        char *argv[] = {"date", NULL};
        execve("/usr/bin/date", argv, NULL);
        exit(1);
    } else {
        wait(NULL);
    }
}

void sigalrm_handler(int sig){
    printf("\n[SIGALRM handler]\n");
    pid_t pid = fork();
    if (pid == 0) {
        char *argv[] = {"whoami", NULL};
        execve("/usr/bin/whoami", argv, NULL);
        exit(1);
    } else {
        wait(NULL);
        alarm(3); 
    }
}

int main(void)
{
    struct sigaction sa_int;
    struct sigaction sa_quit;
    struct sigaction sa_alrm;

    sa_int.sa_handler = sigint_handler;
    sigemptyset(&sa_int.sa_mask);
    sa_int.sa_flags = 0;
    sigaction(SIGINT, &sa_int, NULL);

    sa_quit.sa_handler = sigquit_handler;
    sigemptyset(&sa_quit.sa_mask);
    sa_quit.sa_flags = 0;
    sigaction(SIGQUIT, &sa_quit, NULL);

    sa_alrm.sa_handler = sigalrm_handler;
    sigemptyset(&sa_alrm.sa_mask);
    sa_alrm.sa_flags = 0; 
    sigaction(SIGALRM, &sa_alrm, NULL);

    alarm(3); 

    while(1)
    {
        sleep(1); 
    }
}