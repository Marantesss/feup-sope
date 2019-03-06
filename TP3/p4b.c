#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX 50000

int main(void) {

    pid_t pid;

    pid = fork();
    
    switch (pid) {
        case -1:
            perror("fork");
            break;
        case 0: //filho
            printf("World!\n");
            break;
        default: //pai
            printf("Hello ");
    }

    return 0;
}
