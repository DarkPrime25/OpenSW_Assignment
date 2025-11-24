#include <sys/types.h>
#include <unistd.h> 
#include <stdio.h>

int main(void){
    pid_t my_pid = getpid();
    printf("pid: %lu\n", (unsigned long)my_pid);
    return 0;
}