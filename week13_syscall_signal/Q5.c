#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct two_double{
    double a;
    double b;
} data;

void signal_alarm_handler(int signo){
    printf("%f, %f\n", data.a, data.b);
    alarm(1);
}

int main(void){
    struct sigaction sa_alarm;
    struct two_double zeros = {0.0, 0.0}, ones={1.0, 1.0};

    sigemptyset(&sa_alarm.sa_mask);
    sa_alarm.sa_flags = 0;
    sa_alarm.sa_handler = signal_alarm_handler;
    sigaction(SIGALRM, &sa_alarm, NULL);

    sigset_t block_set, old_set;
    sigemptyset(&block_set);
    sigaddset(&block_set, SIGALRM); 

    alarm(1);

    while(1){
        sigprocmask(SIG_BLOCK, &block_set, &old_set);
        data = ones;
        sigprocmask(SIG_SETMASK, &old_set, NULL);
        sigprocmask(SIG_BLOCK, &block_set, &old_set);
        data = zeros;
        sigprocmask(SIG_SETMASK, &old_set, NULL);
    }
}