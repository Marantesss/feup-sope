#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_LENGTH 256

int main(int argc, char *argv[])
{
    int fd1, fd2, nr, nw;
    unsigned char buffer[BUF_LENGTH];

    // checking number of args
    if ((argc != 2) && (argc != 3)) {
        printf("Usage: %s <source> OR %s <source> <destination>\n", argv[0], argv[0]);
        return 1;
    }

    // opening read file
    fd1 = open(argv[1], O_RDONLY);
    if (fd1 == -1) {
        perror(argv[1]);
        return 2;
    }

    // opening write file
    if (argc == 3) {
        fd2 = open(argv[2], O_WRONLY | O_CREAT, 0644);
        if (fd2 == -1) {
            perror(argv[2]);
            close(fd1);
            return 3;
        }
        dup2(fd2, STDOUT_FILENO);
    }

    while ((nr = read(fd1, buffer, BUF_LENGTH)) > 0)
        if ((nw = write(STDOUT_FILENO, buffer, nr)) <= 0 || nw != nr)
        {
            perror(argv[2]);
            close(fd1);
            close(fd2);
            return 4;
        }

    close(fd1);
    if (argc == 3)
        close(fd2);

        
    return 0;
}