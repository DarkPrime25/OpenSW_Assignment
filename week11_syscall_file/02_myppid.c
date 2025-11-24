#include <sys/types.h>
#include <unistd.h> 
#include <stdio.h>

int main(void){
    pid_t my_pid = getpid();
    pid_t my_ppid = getppid();
    printf("pid: %lu\n", (unsigned long)my_pid);
    printf("ppid: %lu\n", (unsigned long)my_ppid);
    return 0;
}