#include <stdio.h>
#include <stdlib.h> // for atoi

int main(int argc , char* argv[]) {
    for (int i = 0; i < atoi(argv[2]); i++) {
        printf("Hello %s\n", argv[1]);
    }
    return 0;
}

/* Command 'echo $?' returns the retur of the last command executed
 *
 *  In this case the return is 0, so the ouput will be 0
 */