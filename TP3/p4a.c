#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX 50000

int main(void) {

    pid_t pid, pidSon;
    int status;

    pid=fork();
    
    switch (pid) {
        case -1:
            perror("fork");
            break;
        case 0: //filho
            printf("Hello ");
            break;
        default: //pai
            pidSon = wait(&status);
            printf("World!\n");
            printf("My son %d exited with exit code %d\n", pidSon, WEXITSTATUS(status)); 
    }

    return 0;
}
