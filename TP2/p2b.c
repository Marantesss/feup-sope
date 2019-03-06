#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h> 

#define BUF_LENGTH 256

int main(int argc , char* argv[]) {
    int input, output, nr, nw;

    char buf[BUF_LENGTH];

    if (argc != 3) {
        printf("Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    
    } 
    // opening input file
    // O_RDONLY     Read only
    input = open(argv[1], O_RDONLY); 
    if (input == -1) {
        perror(argv[1]); // prints: infile.txt: No such file or directory
        return 2;
    }
    // opening output file
    /*
    O_WRONLY        Write only
    O_CREAT         If pathname does not exist, create it as a regular file.
    O_EXCL          Ensure that this call creates the file: if this flag  is  speci‐
                    fied  in  conjunction with O_CREAT, and pathname already exists,
                    then open() fails with the error EEXIST.
    */
    output = open(argv[2], O_WRONLY | O_CREAT, 0644); 
    if (output == -1) {
        perror(argv[2]); // prints: outfile.txt: No such file or directory
        return 3;
    }

    while ((nr = read(input, buf, BUF_LENGTH)) > 0)
        if ((nw = write(output, buf, nr)) <= 0 || nw != nr) {
            perror(argv[2]);
            close(input);
            close(output);
            return 4;
        }

    close(input);
    close(output);
    
    return 0;
} 