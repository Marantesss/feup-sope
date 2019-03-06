#include <stdio.h>
#include <errno.h>

#define BUF_LENGTH 256

int main(int argc , char* argv[]) {
    FILE *input, *output;

    char buf[BUF_LENGTH];

    if (argc != 3) {
        printf("Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    
    } 
    // opening input file
    if ((input = fopen(argv[1],"r" )) == NULL) {
        perror(argv[1]); // prints: infile.txt: No such file or directory
        return 2;
    }
    // opening output file
    if ((output = fopen(argv[2], "w")) == NULL) {
        perror(argv[2]); // prints: outfile.txt: No such file or directory
        return 3;
    }

    /*
    SEEK_SET	Offset is to be measured in absolute terms.
    SEEK_CUR	Offset is to be measured relative to the current location of the pointer.
    SEEK_END	Offset is to be measured relative to the end of the file.
    */
    // searching for EOF
    fseek(input, 0, SEEK_END);
    int offset = ftell(input);
    fseek(input, 0, SEEK_SET); // we need to get the cursor back to the beginning of the file - CESAR <3

    // reading from input file and writing in output file
    fread(buf, sizeof(char), offset, input);
    fwrite(buf, sizeof(char), offset, output);
    
    // DONT FORGET TO CLOSE ALL FILES
    fclose(input);
    fclose(output);
    
    return 0;
} 