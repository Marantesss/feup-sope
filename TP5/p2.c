#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define READ 0
#define WRITE 1 

int main(void) {
    int fd1[2];
    int fd2[2];
    pid_t pid;
    pipe(fd1);
    pipe(fd2);

    pid = fork();
    if (pid >0) { // parent
        int a[2];
        int res[4];
        printf("PARENT:\n");
        printf("x y ? "); scanf("%d %d",&a[0],&a[1]);
        // closing pipe entries
        close(fd1[READ]);
        close(fd2[WRITE]);

        write(fd1[WRITE], a, 2*sizeof(int));
        read(fd2[READ], res, sizeof(res));
        printf("x + y = %d\n", res[0]);
        printf("x - y = %d\n", res[1]);
        printf("x * y = %d\n", res[2]);
        printf("x / y = %d\n", res[3]);

        close(fd1[WRITE]);
        close(fd2[READ]);
    }
    else { // child
        int b[2];
        int res[4];
        // closing pipe entries
        close(fd2[READ]);
        close(fd1[WRITE]);

        read(fd1[READ], b, 2*sizeof(int));
        printf("SON:\n");
        res[0] = b[0]+b[1];
        res[1] = b[0]-b[1];
        res[2] = b[0]*b[1];
        res[3] = b[0]/b[1];
        write(fd2[WRITE], res, sizeof(res));

        close(fd2[WRITE]);
        close(fd1[READ]);;
    }

    return 0;
} 
