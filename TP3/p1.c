// PROGRAMA p1.c
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int global=1;

int main(void) {
    int local = 2;

    // cada processo tem as suas proprias variaveis
    if(fork() > 0) {
        printf("I'm the parent, ID = %d; PARENT_PROCESS_ID(Bash ID) = %d\n", getpid(), getppid());
        global++;
        local--;
    } else {
        printf("I'm the son, ID = %d; PARENT_PROCESS_ID = %d\n", getpid(), getppid());
        global--;
        local++;
    }

    printf("PID = %d - global = %d ; local = %d\n", getpid(), global, local);
    return 0;
}
