#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define READ 0
#define WRITE 1 

int main(void) {
    int fd[2];
    pid_t pid;
    pipe(fd);

    struct num {
        int num1;
        int num2;
    };


    pid = fork();
    if (pid >0) { // parent
        struct num out_struct;
        printf("PARENT:\n");
        printf("x y ? ");
        scanf("%d %d",&out_struct.num1, &out_struct.num2);
        close(fd[READ]);
        write(fd[WRITE], &out_struct, sizeof(struct num));
        close(fd[WRITE]);
    }
    else { // child
        struct num in_struct;
        close(fd[WRITE]);
        read(fd[READ], &in_struct, sizeof(struct num));
        printf("SON:\n");
        printf("x + y = %d\n", in_struct.num1+in_struct.num2);
        printf("x - y = %d\n", in_struct.num1-in_struct.num2);
        printf("x * y = %d\n", in_struct.num1*in_struct.num2);
        printf("x / y = %f\n", (float)in_struct.num1/in_struct.num2);
        close(fd[READ]);
    }

    return 0;
} 
