// PROGRAMA p2.c
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
    printf("1\n");

    if(fork() > 0) {
        //write(STDOUT_FILENO,"2",1);
        //write(STDOUT_FILENO,"3",1);
        printf("2");
        printf("3");
    } else {
        //write(STDOUT_FILENO,"4",1);
        //write(STDOUT_FILENO,"5",1);
        printf("4");
        printf("5");
    }

    //write(STDOUT_FILENO,"\n",1);
    printf("\n");
    return 0;
}

/* Output com write()
123 # primeiro corre o processo pai
45  # depois corre o ficheiro filho
*/

/* Output com printf()
123 # primeiro corre o processo pai
145 # depois corre o ficheiro filho
# printf() sem \n nao ocorre flush do buffer
*/

/* Output com printf() e "\n"
1  # agora com \n o char '1' e flushed do buffer
23 # primeiro corre o processo pai
45 # depois corre o ficheiro filho
*/
