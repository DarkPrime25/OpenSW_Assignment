#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main() {
    sigset_t newset, pendingset;

    sigemptyset(&newset);
    sigaddset(&newset, SIGINT);

    sigprocmask(SIG_BLOCK, &newset, NULL);

    printf("SIGINT blocked. Sleeping for 5 seconds...\n");
    printf("Try Ctrl + C during sleep.\n");

    sleep(5);

    if (sigpending(&pendingset) < 0) {
        perror("sigpending error");
        return 1;
    }

    if (sigismember(&pendingset, SIGINT)) {
        printf("\nSIGINT is pending\n");
    } else {
        printf("SIGINT is not pending\n");
    }
    return 0;
}