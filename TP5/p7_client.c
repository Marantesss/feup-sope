// PROGRAMA p07_client.c 
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int readline(int fd, char *str); 

int main(void) {
    setbuf(stdout, NULL);
    
    int fifo_ans, fifo_req;

    printf("Opening FIFO communication channels...");

    do {
        fifo_req=open("/tmp/fifo_req", O_WRONLY | O_NONBLOCK); // | O_NONBLOCK makes so that it does not block
        if (fifo_req == -1) {
            printf("\nfifo_req: Attempt failed.");
            sleep(1); 
        }
    } while (fifo_req == -1); 

    do {
        fifo_ans=open("/tmp/fifo_ans", O_RDONLY | O_NONBLOCK);
        if (fifo_ans == -1) {
            printf("\nfifo_ans: Attempt failed");
            sleep(1);
        }
    } while (fifo_ans == -1); 

    printf("\nChannels opened.\n");

    char num1[20], num2[20];

    num1[0] = '\0';
    num2[0] = '\0';

    printf("\nPlease write two Numbers:\nNumber1: ");
    fgets(num1, 20, stdin);

    printf("Number2: ");
    fgets(num2, 20, stdin);

    int messagelen = strlen(num1) + 1;
    write(fifo_req,num1,messagelen); 
    messagelen = strlen(num2) + 1; 
    write(fifo_req,num2,messagelen);

    char resultSum[50], resultDiff[50], resultProduct[50], resultQuo[50];

    /*
    We need to wait a bit for the server to send us the results,
    there's got to be a better way to do this
    */
    printf("\nWaiting results...");
    sleep(1);

    printf("\nReading results...");
    // SUM
    readline(fifo_ans, resultSum);
    printf("\n%s", resultSum);

    // DIFF
    readline(fifo_ans, resultDiff);
    printf("\n%s", resultDiff);

    // PRODUCT
    readline(fifo_ans, resultProduct);
    printf("\n%s", resultProduct);

    // QUOCIENT
    readline(fifo_ans, resultQuo);
    printf("\n%s\n", resultQuo);

    close(fifo_ans);
    close(fifo_req);

    /* only for file names
    ex: unlink("/tmp/my_fifo")
    unlink(fifo_req);
    unlink(fifo_ans);
    */

    return 0; 
} 

int readline(int fd, char *str) {
    int n;

    do { 
        n = read(fd, str, 1); 
    } while (n>0 && *str++ != '\0');

    return (n>0); 
}
