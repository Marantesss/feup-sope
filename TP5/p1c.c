#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

#define READ 0
#define WRITE 1 

#define MAX_STRING_SIZE 32

int main(void) {
    int fd[2];
    pid_t pid;
    pipe(fd);

    pid = fork();
    if (pid >0) { // parent
        char num1[MAX_STRING_SIZE];
        char num2[MAX_STRING_SIZE];
        printf("PARENT:\n");
        printf("x y ? "); scanf("%s %s", num1, num2);
        close(fd[READ]);
        write(fd[WRITE], num1, sizeof(num1));
        write(fd[WRITE], num2, sizeof(num2));
        close(fd[WRITE]);
    }
    else { // child
        char num1[MAX_STRING_SIZE];
        char num2[MAX_STRING_SIZE];
        close(fd[WRITE]);
        read(fd[READ], num1, sizeof(num1));
        read(fd[READ], num2, sizeof(num2));
        printf("SON:\n");
        printf("%s %s\n", num1, num2);
        printf("x + y = %d\n", atoi(num1) + atoi(num2));
        printf("x - y = %d\n", atoi(num1) - atoi(num2));
        printf("x * y = %d\n", atoi(num1) * atoi(num2));
        printf("x / y = %f\n", (float) atoi(num1) / atoi(num2));
        close(fd[READ]);
    }

    return 0;
} 
