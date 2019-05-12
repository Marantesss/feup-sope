// PROGRAMA p06_reader.c
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <stdio.h>
#include <unistd.h>

int readline(int fd, char *str);

int main(void) {
    int fd;
    char str[100];

    mkfifo("/tmp/myfifo",0660);
    fd=open("/tmp/myfifo", O_RDONLY);

    /*
    fd=open("/tmp/myfifo",O_RDWR);

    if the FIFO is open in read and write mode, when p6_writer ends,
    the 'do ... while' loop in p6_reader will not end because read will still be
    valid since the pipe is still open in write mode by the process that is
    trying to read from it, causing an infinite loop
    */
    
    while(readline(fd,str))
        printf("%s",str);
    
    close(fd);
    
    return 0;
}

int readline(int fd, char *str) {
    int n;

    do {
        n = read(fd,str,1);
    } while (n>0 && *str++ != '\0');

    return (n>0);
}