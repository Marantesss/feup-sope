// PROGRAMA p7.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    char prog[20];
    sprintf(prog,"%s.c",argv[1]);

    execlp("gcc","gcc",prog,"-Wall","-o", argv[1], NULL);
    // retorna 0 se o programa acima funcionar :) echo $? retorna 0

    printf("execlp() failed !!! \n");
    exit(1);
}
