// PROGRAMA p6a.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define BUF_LENGTH 256


int main(int argc , char* argv[]) {

    FILE *src, *dst;
    char buf[BUF_LENGTH];

    if ((src = fopen(argv[1],"r" )) == NULL) {
        perror("infile.txt"); // prints: infile.txt: No such file or directory
        //strerror(1);
        //printf("ERROR: %s\n", strerror(errno)); // prints ERROR: No such file or directory
        printf("Usage: %s file1 file2\n", argv[0]);
        exit(1);
    }

    if ((dst = fopen(argv[1], "w")) == NULL) {
        perror("outfile.txt"); // prints: outfile.txt: No such file or directory
        //strerror(2);// no need for both
        //printf("ERROR: %s\n", strerror(errno));
        printf("Usage: %s file1 file2\n", argv[0]);
        exit(2);
    }

    // sizeof(buf) == BUF_LENGTH
    while(fgets(buf, BUF_LENGTH, src) != NULL) {
        fputs(buf, dst);
    }
    
    fclose(src);
    fclose(dst);
    exit(0); // zero é geralmente indicativo de "sucesso"
} 
